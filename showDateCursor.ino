//Показать курсор на дате
void showDateCursor(uint8_t oldCur, uint8_t cur){
  switch(oldCur){
  case 0:
    lcd.setCursor(3, 0);
    lcd.print(".");
    break;
  case 1:
    lcd.setCursor(6,0);
    lcd.print(".");
    break;
  case 2:
    lcd.setCursor(11, 0);
    lcd.print(" ");
    break;
  }
  switch(cur){
  case 0:
    lcd.setCursor(3, 0);
    break;
  case 1:
    lcd.setCursor(6,0);
    break;
  case 2:
    lcd.setCursor(11, 0);
    break;
  }
  lcd.write(byte(2));
}
