//Управление клавишами
void control(){
  btnPrev.tick();
  btnNext.tick();
  if(btnPrev.isHolded()){
    //Вкдючаем дисплей
    enabledDisplay=true;
    currMillisDisplay=millis();
    //Вход в основное меню
    if(menu==0){
      menu=1;
      cur=0;
    }
    //Редактирование даты
    else if(menu==1 && cur==0){
      menu=2;
      cur=0;
      showDateCursor(0, 0);
    }
    //Редактирование времени
    else if(menu==1 && cur==1){
      menu=3;
      cur=0;
      showTimeCursor(0, 0);
    }
    //Редактирование будильника
    /*else if(menu==1 && cur==2){
     menu=4;
     }*/
    //Редактирование даты дня
    else if(menu==2 && cur==0){
      menu=5;
      editDateCursor();
      modifyValue=rtc.getDate();
    }
    //Редактирование даты месяца
    else if(menu==2&&cur==1){
      menu=6;
      editDateCursor();
      modifyValue=rtc.getMonth();
    }
    //Редактирование даты года
    else if(menu==2&&cur==2){
      menu=7;
      editDateCursor();
      modifyValue=rtc.getYear();
    }
    //Редактирование времени часов
    else if(menu==3&&cur==0){
      menu=8;
      editTimeCursor();
      modifyValue=rtc.getHours();
    }
    //Редактирование времени минуты
    else if(menu==3&&cur==1){
      menu=9;
      editTimeCursor();
      modifyValue=rtc.getMinutes();
    }
    //Редактирование времени секунды
    else if(menu==3&&cur==2){
      menu=10;
      editTimeCursor();
      modifyValue=rtc.getSeconds();
    }
    //Редактирование будильника
    else if(menu==1&&cur==2){
      menu=4;
      cur=0;
      showAlarmCursor(0,0);
    } 
    else if(menu==4&&cur==0){
      menu=11;
      editAlarmCursor();
      modifyValue=alarmHours;
    }
    else if(menu==4&&cur==1){
      menu=12;
      editAlarmCursor();
      modifyValue=alarmMinutes;
    }
#ifdef DEBUG
    Serial.print("Menu: ");
    Serial.println(menu);
    Serial.print("Cursor: ");
    Serial.println(cur);
#endif

  }

  if(btnPrev.isClick()){
    enabledDisplay=true;
    currMillisDisplay=millis();
    moveCursorPrev();
  }
  if(btnNext.isClick()){
    enabledDisplay=true;
    currMillisDisplay=millis();
    moveCursorNext();
  }

  if(btnNext.isHolded()){
    enabledDisplay=true;
    currMillisDisplay=millis();
    switch(menu){
    case 11:
      //изменить часы будильника
      menu=4;
      showAlarmCursor(cur,cur);
      alarmHours=modifyValue;
      if(alarmEnabled){
        bitSet(alarmHours,7);
      }
      else{
        bitClear(alarmHours,7);
      }
      EEPROM.write(0,alarmHours);
      bitClear(alarmHours,7);
#ifdef DEBUG
      Serial.print("Alarm minutes: ");
      Serial.println(alarmMinutes);
#endif
      break;
    case 12:
      //изменить минуты будильника
      menu=4;
      showAlarmCursor(cur,cur);
      alarmMinutes=modifyValue;
      EEPROM.write(1,alarmMinutes);
#ifdef DEBUG
      Serial.print("Alarm minutes: ");
      Serial.println(alarmMinutes);
#endif
      break;
    case 8:
      menu=3;
      showTimeCursor(cur,cur);
      rtc.setTime(rtc.getSeconds(), rtc.getMinutes(), modifyValue, rtc.getDate(), rtc.getMonth(), rtc.getYear());
      break;
    case 9:
      menu=3;
      showTimeCursor(cur,cur);
      rtc.setTime(rtc.getSeconds(), modifyValue, rtc.getHours(), rtc.getDate(), rtc.getMonth(), rtc.getYear());
      break;
    case 10:
      menu=3;
      showTimeCursor(cur,cur);
      rtc.setTime(modifyValue, rtc.getMinutes(), rtc.getHours(), rtc.getDate(), rtc.getMonth(), rtc.getYear());
      break;
    case 7:
      menu=2;
      showDateCursor(cur,cur);
      rtc.setTime(rtc.getSeconds(), rtc.getMinutes(), rtc.getHours(), rtc.getDate(), rtc.getMonth(), modifyValue);
      break;
    case 6:
      menu=2;
      showDateCursor(cur,cur);
      rtc.setTime(rtc.getSeconds(), rtc.getMinutes(), rtc.getHours(), rtc.getDate(), modifyValue, rtc.getYear());
      break;
    case 5:
      menu=2;
      showDateCursor(cur,cur);
      rtc.setTime(rtc.getSeconds(), rtc.getMinutes(), rtc.getHours(), modifyValue, rtc.getMonth(), rtc.getYear());
      break;
    case 4:
      menu=1;
      cur=2;
      lcd.setCursor(7,2);
      lcd.print(" ");
      showAlarm();
      break;
    case 3:
      menu=1;
      cur=1;
      lastSecond=0;
      lcd.setCursor(9,1);
      lcd.print(" ");
      break;
    case 2:
      menu=1;
      cur=0;
      lastDate=0;
      lcd.setCursor(11,0);
      lcd.print(" ");
      break;
    case 1:
      menu=0;
      lcd.setCursor(0, cur);
      lcd.print(" ");
      break;
      //Включение или отключение будильника
    case 0:
      alarmInvert();
      break;
    }
  }
}












