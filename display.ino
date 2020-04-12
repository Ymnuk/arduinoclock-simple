void display()
{
  if(enabledDisplay){
    if(!displayOn){
      lcd.backlight();
      displayOn=true;
      lastSecond=0;
      lastDate=0;
      lcd.clear();
    }
    uint32_t currMillis = millis();
    if(currMillisDisplay>currMillis){
      currMillisDisplay=currMillis;
    }
    showDate();
    showTime();
    if(menu>0){
      showCursor();
    }
    showAlarm();

    if((currMillis - currMillisDisplay) > 180000){
      enabledDisplay=false;
    }

  }
  else{
    //Если включена подсветка, то выключаем
    if(displayOn){
      lcd.noBacklight();
      displayOn=false;
    }
    //Выводим часы как скринсейвер
    if(currMinutes != rtc.getMinutes()){
      currMinutes=rtc.getMinutes();
      uint8_t currHours=rtc.getHours();
      uint8_t screenSaverCol = byte(random(0, 15));
      uint8_t screenSaverRow = byte(random(0, 4));
      lcd.clear();
      lcd.setCursor(screenSaverCol, screenSaverRow);
      if(currHours < 10){
        lcd.print("0");
      }
      lcd.print(currHours);
      lcd.print(":");
      if(currMinutes < 10){
        lcd.print("0");
      }
      lcd.print(currMinutes);
      #ifdef DEBUG
      Serial.print("Column: ");
      Serial.println(screenSaverCol);
      Serial.print("Row: ");
      Serial.println(screenSaverRow);
      Serial.print("Time: ");
      Serial.print(currHours);
      Serial.print(":");
      Serial.println(currMinutes);
      #endif
    }
  }
}


