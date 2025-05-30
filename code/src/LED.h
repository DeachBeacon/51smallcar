#ifndef LED_H
#define LED_H
#include <STC89C5xRC.H>
#include "Delay.h"

sbit LED2=P1^2;
sbit LED3=P1^3;
sbit LED4=P1^4;
sbit LED5=P1^5;
sbit LED6=P1^6;
sbit LED7=P1^7;

#define LED_ON   1
#define LED_OFF  0


void LED_Init(void);
void LED_2(unsigned char i);
void LED_3(unsigned char i);
void LED_4(unsigned char i);
void LED_5(unsigned char i);
void LED_6(unsigned char i);
void LED_7(unsigned char i);
#endif