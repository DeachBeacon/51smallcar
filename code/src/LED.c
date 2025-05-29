#include <STC89C5xRC.H>
#include "Delay.h"
#include "LED.h"

void LED_Init(void){
    LED2 = LED_OFF; 
    LED3 = LED_OFF;
    LED4 = LED_OFF;
    LED5 = LED_OFF;
    LED6 = LED_OFF;
    LED7 = LED_OFF;
}
void LED_2(unsigned char i){
    if (i == 1){
        LED2 = LED_ON;
    }
    else{
        LED2 = LED_OFF;
    }
}

void LED_3(unsigned char i){
    if (i == 1){
        LED3 = LED_ON;
    }
    else{
        LED3 = LED_OFF;
    }
}
void LED_4(unsigned char i){
    if (i == 1){
        LED4 = LED_ON;
    }
    else{
        LED4 = LED_OFF;
    }
}
void LED_5(unsigned char i){
    if (i == 1){
        LED5 = LED_ON;
    }
    else{
        LED5 = LED_OFF;
    }
}
void LED_6(unsigned char i){
    if (i == 1){
        LED6 = LED_ON;
    }
    else{
        LED6 = LED_OFF;
    }
}
void LED_7(unsigned char i){
    if (i == 1){
        LED7 = LED_ON;
    }
    else{
        LED7 = LED_OFF;
    }
}
