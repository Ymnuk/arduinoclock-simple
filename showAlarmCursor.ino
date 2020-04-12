void showAlarmCursor(uint8_t oldCur, uint8_t cur){
  if(oldCur==0){
    lcd.setCursor(4,2);
    lcd.print(":");
  }
  else if(oldCur==1){
    lcd.setCursor(7,2);
    lcd.print(" ");
  }
  switch(cur){
  case 0:
    lcd.setCursor(4,2);
    break;
  case 1:
    lcd.setCursor(7,2);
    break;
  }
  lcd.write(byte(2));
}

