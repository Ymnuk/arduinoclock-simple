void editDateCursor(){
  switch(cur){
  case 0:
    lcd.setCursor(3,0);
    break;
  case 1:
    lcd.setCursor(6,0);
    break;
  case 2:
    lcd.setCursor(11,0);
    break;
  }
  lcd.write(byte(3));
}
