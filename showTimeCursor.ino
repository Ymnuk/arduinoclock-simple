//Показать курсор на времени
void showTimeCursor(uint8_t oldCur, uint8_t cur){
  switch(oldCur){
  case 0:
    lcd.setCursor(3, 1);
    lcd.print(":");
    break;
  case 1:
    lcd.setCursor(6,1);
    lcd.print(":");
    break;
  case 2:
    lcd.setCursor(9, 1);
    lcd.print(" ");
    break;
  }
  switch(cur){
  case 0:
    lcd.setCursor(3, 1);
    break;
  case 1:
    lcd.setCursor(6,1);
    break;
  case 2:
    lcd.setCursor(9, 1);
    break;
  }
  lcd.write(byte(2));
}
