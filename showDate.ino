//Показать дату
void showDate()
{
  if(menu==0){
    uint8_t days = rtc.getDate();
    if(days!=lastDate){
      showDateDay(days);
      lcd.print(".");
      showDateMonth(rtc.getMonth());
      lcd.print(".");
      showDateYear(rtc.getYear());
      lcd.print(" ");
      showDay(rtc.getDay());
      //lcd.print(rtc.getDay());

      lastDate=days;
    }
  }
}

void showDateDay(uint8_t value) {
  lcd.setCursor(1,0);
  if(value<10){
    lcd.print("0");
    lcd.print(value);
  }
  else{
    lcd.print(value);
  }
}

void showDateMonth(uint8_t value) {
  lcd.setCursor(4,0);
  if(value<10){
    lcd.print("0");
    lcd.print(value);
  }
  else{
    lcd.print(value);
  }
}

void showDateYear(uint16_t value) {
  lcd.setCursor(7,0);
  lcd.print(value);
}

//Выводим день недели
void showDay(uint8_t value){
#ifdef DEBUG
  Serial.print("Day: ");
  Serial.println(value);
#endif

  switch(value){
  case 1:
    lcd.print("Mon");
    break;
  case 2:
    lcd.print("Tue");
    break;
  case 3:
    lcd.print("Wed");
    break;
  case 4:
    lcd.print("Thu");
    break;
  case 5:
    lcd.print("Fri");
    break;
  case 6:
    lcd.print("Sat");
    break;
  case 0:
    lcd.print("Sun");
    break;
  }
}
