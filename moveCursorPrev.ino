//Переместить курсор назад
void moveCursorPrev(){
  //Главное меню
  if(menu==1){
    lcd.setCursor(0, cur);
    lcd.print(" ");
    if(cur==0){
      cur=2;
    }
    else{
      cur--;
    }
    lcd.setCursor(0,cur);
    lcd.write(byte(1));
  }
  //Настройка даты
  if(menu==2){
    uint8_t oldCur=cur;
    if(cur==0){
      cur=2;
    }
    else{
      cur--;
    }
    showDateCursor(oldCur, cur);
  }
  //Изменение числа даты
  if(menu==5){
    if(modifyValue==1){
      modifyValue=31;
    }else{
      modifyValue--;
    }
    showDateDay(modifyValue);
  }
  //Изменение месяца даты
  if(menu==6){
    if(modifyValue==1){
      modifyValue=12;
    }else{
      modifyValue--;
    }
    showDateMonth(modifyValue);
  }
  //Изменение год даты
  if(menu==7){
    if(modifyValue==1970){
      modifyValue=2100;
    }else{
      modifyValue--;
    }
    showDateYear(modifyValue);
  }
  
  if(menu==8){
    if(modifyValue==0){
      modifyValue=23;
    }else{
      modifyValue--;
    }
    showTimeHour(modifyValue);
  }
  if(menu==9){
    if(modifyValue==0){
      modifyValue=59;
    }else{
      modifyValue--;
    }
    showTimeMinute(modifyValue);
  }
  if(menu==10){
    if(modifyValue==0){
      modifyValue=59;
    }else{
      modifyValue--;
    }
    showTimeSecond(modifyValue);
  }
  //Будильник
  if(menu==4){
    uint8_t oldCur=cur;
    if(cur==0){
      cur=1;
    }else{
      cur--;
    }
    showAlarmCursor(oldCur,cur);
  }
    if(menu==11){
    if(modifyValue==0){
      modifyValue=23;
    }
    else{
      modifyValue--;
    }
    showAlarmHour(modifyValue);
  }
  if(menu==12){
    if(modifyValue==0){
      modifyValue=59;
    }
    else{
      modifyValue--;
    }
    showAlarmMinute(modifyValue);
  }
  
  #ifdef DEBUG
  Serial.print("Menu: ");
  Serial.println(menu);
  Serial.print("Cursor: ");
  Serial.println(cur);
  #endif
}
