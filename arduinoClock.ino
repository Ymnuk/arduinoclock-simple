/**
 * Часы.
 * Время - DS3231 mini
 * Давление, температура, влажность (наверно, нужно проверить) - BMP280
 * 2-е сенсорные кнопи
 * Дисплей - 2004A LCD
 *
 * Вывод на дисплей информации:
 * ДД.ММ.ГГГГ День недели
 * ЧЧ.ММ.СС Восход/Закат
 * Будильник (если включен)
 */
 
/**
 * Библиотеки были взяты с https://github.com/AlexGyver/GyverLibs
 */

//#define DEBUG

//#define MUSIC//Раскомментировать, если использовать мелодию

#ifdef MUSIC
#define NOTE_NONE 0
#define NOTE_B4  988
#define NOTE_FS5 1480
#define NOTE_G5  1568
#define NOTE_E5  1318
#define NOTE_D5  1174
#define NOTE_CS5 1108
#define NOTE_DELAY 250
#endif

#include <microWire.h>
#include <microDS3231.h>
#include <microLiquidCrystal_I2C.h>
#include <GyverButton.h>
#include <EEPROM.h>
#include <GyverPower.h>

#define BIT_BTN_PREV 2
#define BIT_BTN_NEXT 3

GButton btnPrev(BIT_BTN_PREV);
GButton btnNext(BIT_BTN_NEXT);
MicroDS3231 rtc;

LiquidCrystal_I2C lcd(0x27, 20, 4);


uint8_t lastSecond=0;//Последняя секунда
uint8_t lastDate=0;//Последний день при изменении

bool alarmEnabled=0;//Будильник включен
uint8_t alarmHours=0;//Часы будильника
uint8_t alarmMinutes=0;//Минуты будильника
/**
 * 0 - Отображает дату, время и ближайший будильник (если он включен)
 * 1 - Все установленные будильники
 * 2 - Таймер. Можно установить таймер, который по окончанию работы запустит звуковой сигнал
 */

uint8_t cur=0;//Курсор. Отображает на экране позицию курсора в зависимости от экрана. Сбрасывается при выходе из режима пролистывания

/**
 * Какое меню на текущий момент включено.
 * 0 - меню не включено,
 * 1 - главное меню,
 * 2 - настройка даты,
 ** 5 - День
 ** 6 - Месяц
 ** 7 - Год
 * 3 - настройка времени,
 ** 8 - часы
 ** 9 - минуты
 ** 10 - секунды
 * 4 - настройка будильника
 * 11 - часы будильника
 * 12 - минуты будильника
 */
uint8_t menu = 0;

/*uint8_t day=0;
 uint8_t month=0;
 uint16_t year=0;*/

uint16_t modifyValue=0;

/**
 * Будильник в памяти хранится в следующем формате:
 * 1 бит - будильник включен или выключен
 * 5 бит - часы
 * 6 бит - минуты
 */

uint32_t currMillisAlarm = 0;
bool enabledSound = false;

#ifdef MUSIC
uint8_t melodyPos = 0;//Позиция ноты мелодии
#endif

bool enabledDisplay=true;
bool displayOn=true;
uint32_t currMillisDisplay;

uint8_t screenSaverRow = 0;
uint8_t screenSaverCol = 0;
uint8_t currMinutes = 0;

void setup()
{
  //Проверяем будильник
  uint8_t testAlarm=EEPROM.read(0);
  if(bitRead(testAlarm,7)){
    alarmEnabled=true;
  }
  else{
    alarmEnabled=false;
  }
  bitClear(testAlarm,7);
  bitClear(testAlarm,6);
  bitClear(testAlarm,5);
  alarmHours=testAlarm;
  testAlarm=EEPROM.read(1);
  if(testAlarm > 59){
    testAlarm=59;
  }
  alarmMinutes=testAlarm;
  //Устанавливаем кнопки
  //btnPrev.setDebounce(10);
  btnPrev.setType(LOW_PULL);
  //btnNext.setDebounce(10);
  btnNext.setType(LOW_PULL);

  pinMode(13, OUTPUT);

  //Устанавливаем начальные значения дисплея
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.noCursor();

#ifdef DEBUG
  Serial.begin(9600);
#endif
  byte ding[8]={
    0b01110,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000,
    0b00100
  };
  byte arrowRight[8]={
    0b11000,
    0b00100,
    0b00010,
    0b00001,
    0b00010,
    0b00100,
    0b11000
  };
  byte arrowLeft[8]={
    0b00011,
    0b00100,
    0b01000,
    0b10000,
    0b01000,
    0b00100,
    0b00011
  };
  byte arrowLeftEdit[8]={
    0b00011,
    0b00111,
    0b01111,
    0b11111,
    0b01111,
    0b00111,
    0b00011
  };
  //Добавляем колокольчик в символы
  lcd.createChar(0,ding);
  lcd.createChar(1,arrowRight);
  lcd.createChar(2,arrowLeft);
  lcd.createChar(3,arrowLeftEdit);

  currMillisDisplay=millis();

  showAlarm();
  hardwareDisable(PWR_ADC | PWR_USB | PWR_SPI | PRESCALER_4);
}

void loop()
{
  while(true){
    control();//Вызываем функцию для управления
    workAlarm();
    display();
  }
}


