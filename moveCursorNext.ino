//Переместить курсор вперед
void moveCursorNext(){
  if(menu==1){
    lcd.setCursor(0, cur);
    lcd.print(" ");
    if(cur==2){
      cur=0;
    }
    else{
      cur++;
    }
    lcd.setCursor(0,cur);
    lcd.write(byte(1));
  }
  //Настройка даты
  if(menu==2){
    uint8_t oldCur=cur;
    if(cur==2){
      cur=0;
    }
    else{
      cur++;
    }
    showDateCursor(oldCur, cur);
  }
  //Изменение числа даты
  if(menu==5){
    if(modifyValue==31){
      modifyValue=1;
    }
    else{
      modifyValue++;
    }
    showDateDay(modifyValue);
  }
  //Изменение месяца даты
  if(menu==6){
    if(modifyValue==12){
      modifyValue=1;
    }
    else{
      modifyValue++;
    }
    showDateMonth(modifyValue);
  }
  //Изменение год даты
  if(menu==7){
    if(modifyValue==2100){
      modifyValue=1970;
    }
    else{
      modifyValue++;
    }
    showDateYear(modifyValue);
  }
  //Настройка времени
  if(menu==3){
    uint8_t oldCur=cur;
    if(cur==2){
      cur=0;
    }
    else{
      cur++;
    }
    showTimeCursor(oldCur,cur);
  }
  if(menu==8){
    if(modifyValue==23){
      modifyValue=0;
    }
    else{
      modifyValue++;
    }
    showTimeHour(modifyValue);
  }
  if(menu==9){
    if(modifyValue==59){
      modifyValue=0;
    }
    else{
      modifyValue++;
    }
    showTimeMinute(modifyValue);
  }
  if(menu==10){
    if(modifyValue==59){
      modifyValue=0;
    }
    else{
      modifyValue++;
    }
    showTimeSecond(modifyValue);
  }
  //Будильник
  if(menu==4){
    uint8_t oldCur=cur;
    if(cur==1){
      cur=0;
    }
    else{
      cur++;
    }
    showAlarmCursor(oldCur, cur);
  }
  if(menu==11){
    if(modifyValue>=23){
      modifyValue=0;
    }
    else{
      modifyValue++;
    }
    showAlarmHour(modifyValue);
  }
  if(menu==12){
    if(modifyValue>=59){
      modifyValue=0;
    }
    else{
      modifyValue++;
    }
    showAlarmMinute(modifyValue);
  }
}

