#ifndef AIR_H
#define AIR_H


#include "Arduino.h"
#include "config.h"
#include <HID-Project.h>


void setairkey(int light,int state);
void setlight(int light,int state);
int checkair(int light,uint8_t &air);

#endif
