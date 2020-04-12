void editTimeCursor(){
  switch(cur){
  case 0:
    lcd.setCursor(3,1);
    break;
  case 1:
    lcd.setCursor(6,1);
    break;
  case 2:
    lcd.setCursor(9,1);
    break;
  }
  lcd.write(byte(3));
}
