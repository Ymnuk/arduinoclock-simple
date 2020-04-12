//Показать будильник
void showAlarm(){
  if(menu==0){
    lcd.setCursor(1, 2);
    if(alarmEnabled){
      lcd.write(byte(0));
    }
    else{
      lcd.print(" ");
    }
    showAlarmHour(alarmHours);
    lcd.print(":");
    showAlarmMinute(alarmMinutes);
    lcd.print(" ");
  }
}

void showAlarmHour(uint8_t value){
  lcd.setCursor(2,2);
  if(value<10){
    lcd.print("0");
  }
  lcd.print(value);
}

void showAlarmMinute(uint8_t value){
  lcd.setCursor(5,2);
  if(value<10){
    lcd.print("0");
  }
  lcd.print(value);
}

