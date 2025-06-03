//所有变量要在最开始就声明
#include <STC89C5xRC.H>
#include "Motor.h"
#include "Delay.h"
#include "Track.h"
#include "LED.h"
#include "Speed.h"

void main()
{
    unsigned char i;
    unsigned char speed;
    LED_Init();
    Track_Init();
    Motor_Init();
    while(1){
        Track_Control();
        for (i = 0;i < 1000; i++){
            speed = Get_Speed();
        }
    }
}