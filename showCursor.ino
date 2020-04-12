//Показать курсор меню
void showCursor(){
  if(menu==1){
    lcd.setCursor(0,cur);
    lcd.write(byte(1));
  }
}
