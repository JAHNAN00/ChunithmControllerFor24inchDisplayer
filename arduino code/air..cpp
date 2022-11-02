#include "air.h"


void setairkey(int light,int state){
  if (state==-1) return;//维持当前状态不变；
  switch(light){
    case 1:
      if(state) NKROKeyboard.add('[');
      else NKROKeyboard.remove('[');
      break;
    case 2:
      if(state) NKROKeyboard.add(']');
      else NKROKeyboard.remove(']');
      break;
    case 3:
      if(state) NKROKeyboard.add(';');
      else NKROKeyboard.remove(';');
      break;
    case 4:
      if(state) NKROKeyboard.add('\'');
      else NKROKeyboard.remove('\'');
      break;
    case 5:
      if(state) NKROKeyboard.add('.');
      else NKROKeyboard.remove('.');
      break;
    case 6:
      if(state) NKROKeyboard.add('/');
      else NKROKeyboard.remove('/');
      break;
  }
  return;
}

void setlight(int light,int state){//0表示熄灭，1表示点亮
  switch(light){
    case 1:
    case 7:
      digitalWrite(SEND1,(state==1)?HIGH:LOW);
      break;
    case 2:
      digitalWrite(SEND2,(state==1)?HIGH:LOW);
      break;
    case 3:
      digitalWrite(SEND3,(state==1)?HIGH:LOW);
      break;
    case 4:
      digitalWrite(SEND4,(state==1)?HIGH:LOW);
      break;
    case 5:
      digitalWrite(SEND5,(state==1)?HIGH:LOW);
      break;
    case 6:
      digitalWrite(SEND6,(state==1)?HIGH:LOW);
      break;
  }
}

int checkair(int light,uint8_t &air){
  int temp;
  switch(light){
    case 1:
      temp=analogRead(RECE1);
      break;
    case 2:
      temp=analogRead(RECE2);
      break;
    case 3:
      temp=analogRead(RECE3);
      break;
    case 4:
      temp=analogRead(RECE4);
      break;
    case 5:
      temp=analogRead(RECE5);
      break;
    case 6:
      temp=analogRead(RECE6);
      break;
  }
  if(temp<LEVELON&&!(air&(1<<light))){ 
    air|=1<<light;
    return 1;
  }
  else if(temp>LEVELOFF&&(air&(1<<light))){ 
    air&=~(1<<light);
    return 0;
  }
  else return -1;//维持当前状态不变
}
