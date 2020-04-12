void editAlarmCursor(){
  switch(cur){
  case 0:
    lcd.setCursor(4,2);
    break;
  case 1:
    lcd.setCursor(7,2);
    break;
  }
  lcd.write(byte(3));
}
