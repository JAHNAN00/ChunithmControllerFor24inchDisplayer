#include <Wire.h>
#include "MPR121.h"
#include <HID-Project.h>
#include "air.h"

#ifndef _BV
#define _BV(bit) (point << (bit)) 
#endif

Adafruit_MPR121 capl = Adafruit_MPR121();
Adafruit_MPR121 capm = Adafruit_MPR121();
Adafruit_MPR121 capr = Adafruit_MPR121();

uint32_t lasttouched = 0;
uint32_t currtouched = 0;

uint32_t point = 1;

uint8_t air=0;


void setup() {

  //while (!Serial) { // needed to keep leonardo/micro from starting too fast!
  //  delay(10);
  //}
  setlight(1,1);
  setlight(2,1);
  setlight(3,1);
  setlight(4,1);
  setlight(5,1);
  setlight(6,1);
  
  capl.begin(0x5a);
  capm.begin(0x5b);
  capr.begin(0x5c);

  NKROKeyboard.releaseAll();
  
  //Serial.println("MPR121 found!");
}

void loop(){
  currtouched=capl.touched();
  currtouched|=(uint32_t(capm.touched()))<<12;
  currtouched|=(uint32_t(capr.touched()))<<24;
  
  //Serial.println(currtouched,BIN);
  uint8_t i;
  for(i=0;i<32;i++){
    if((currtouched&point<<i) && !(lasttouched&point<<i)){
      NKROKeyboard.add(i<26?0x41+i:0x34+i-26);
      //Serial.println(i<26?0x41+i:0x34+i-26);
    }
    if (!(currtouched &point<<i) && (lasttouched & point<<i) ) {
      NKROKeyboard.remove(i<26?0x41+i:0x34+i-26);
    }
  }
 
  
  for(i=1;i<=6;i++){
    setairkey(i,checkair(i,air));
    setlight(i+1,1);
    setlight(i,0);
    delay(1);
  }//

  NKROKeyboard.send();
  lasttouched = currtouched;
  currtouched = 0;
}
