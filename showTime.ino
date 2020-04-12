//Показать время
void showTime(){
  if(menu==0){
    uint8_t seconds=rtc.getSeconds();
    if(seconds!=lastSecond){
      showTimeHour(rtc.getHours());
      lcd.print(":");
      showTimeMinute(rtc.getMinutes());
      lcd.print(":");
      showTimeSecond(seconds);
      lastSecond=seconds;
    }
  }
}

void showTimeHour(uint8_t value){
  lcd.setCursor(1,1);
  if(value<10){
    lcd.print("0");
    lcd.print(value);
  }
  else{
    lcd.print(value);
  }
}

void showTimeMinute(uint8_t value){
  lcd.setCursor(4,1);
  if(value<10){
    lcd.print("0");
    lcd.print(value);
  }
  else{
    lcd.print(value);
  }
}

void showTimeSecond(uint8_t value){
  lcd.setCursor(7,1);
  if(value<10){
    lcd.print("0");
    lcd.print(value);
  }
  else{
    lcd.print(value);
  }
}

