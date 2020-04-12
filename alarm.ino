void alarmEnable(){
  uint8_t tmp=EEPROM.read(0);
  bitSet(tmp,7);
  EEPROM.write(0, tmp);
  alarmEnabled=true;
}

void alarmDisable(){
  uint8_t tmp=EEPROM.read(0);
  bitClear(tmp,7);
  EEPROM.write(0, tmp);  
  alarmEnabled=false;
}

void alarmInvert(){
  if(alarmEnabled){
    alarmDisable();
  }
  else{
    alarmEnable();
  }
  showAlarm();
}


#ifdef MUSIC
//Функция издает писк буззером когда будильник включен и когда часы и минуты совпадают с часами и минутами будильника
void workAlarm(){
  if(alarmEnabled && alarmHours == rtc.getHours() && alarmMinutes == rtc.getMinutes()){
    if(!enabledDisplay){
      enabledDisplay=true;
      currMillisDisplay=millis();
    }
    enabledSound=true;
    uint32_t currMillis = millis();
    if(currMillis < currMillisAlarm){
      currMillisAlarm = currMillis;
    } 
    else {
      if((currMillis - currMillisAlarm) >= NOTE_DELAY){
        if(melodyPos==31){
          melodyPos=0;
        }
        else{
          melodyPos++;
        }
        currMillisAlarm=currMillis;
        noTone(8);
        //Код для воспроизведения
        uint16_t note;
        switch(melodyPos){
        case 0:
          note=NOTE_B4;
          break;
        case 1:
          note=NOTE_NONE;
          break;
        case 2:
          note=NOTE_FS5;
          break;
        case 3:
          note=NOTE_B4;
          break;
        case 4:
          note=NOTE_G5;
          break;
        case 5:
          note=NOTE_NONE;
          break;
        case 6:
          note=NOTE_FS5;
          break;
        case 7:
          note=NOTE_E5;
          break;
        case 8:
          note=NOTE_FS5;
          break;
        case 9:
          note=NOTE_NONE;
          break;
        case 10:
          note=NOTE_E5;
          break;
        case 11:
          note=NOTE_FS5;
          break;
        case 12:
          note=NOTE_G5;
          break;
        case 13:
          note=NOTE_G5;
          break;
        case 14:
          note=NOTE_FS5;
          break;
        case 15:
          note=NOTE_E5;
          break;
        case 16:
          note=NOTE_B4;
          break;
        case 17:
          note=NOTE_NONE;
          break;
        case 18:
          note=NOTE_FS5;
          break;
        case 19:
          note=NOTE_B4;
          break;
        case 20:
          note=NOTE_G5;
          break;
        case 21:
          note=NOTE_NONE;
          break;
        case 22:
          note=NOTE_FS5;
          break;
        case 23:
          note=NOTE_E5;
          break;
        case 24:
          note=NOTE_D5;
          break;
        case 25:
          note=NOTE_NONE;
          break;
        case 26:
          note=NOTE_E5;
          break;
        case 27:
          note=NOTE_D5;
          break;
        case 28:
          note=NOTE_CS5;
          break;
        case 29:
          note=NOTE_CS5;
          break;
        case 30:
          note=NOTE_D5;
          break;
        case 31:
          note=NOTE_CS5;
          break;
        }
        if(note!=0){
          tone(8,note);
        }
      }
    }
  }
  else{
    if(enabledSound){
      enabledSound = false;
      noTone(8);
    }
  }
}
#endif

#ifndef MUSIC
void workAlarm(){
  if(alarmEnabled && alarmHours == rtc.getHours() && alarmMinutes == rtc.getMinutes()){
    if(!enabledDisplay){
      enabledDisplay=true;
      currMillisDisplay=millis();
    }
    uint32_t currMillis = millis();
    if(currMillisAlarm > currMillis) {
      currMillisAlarm=currMillis;
    } 
    uint32_t moded = (currMillis - currMillisAlarm) % 1000;
    if(moded >=0 && moded < 500){
      enabledSound=true;
      tone(8,440);
    }
    if(moded >= 500 && moded < 1000){
      enabledSound=false;
      noTone(8);
    }
  }
  else if(enabledSound){
    enabledSound=false;
    noTone(8);
  }
}

#endif









