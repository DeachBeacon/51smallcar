//���б���Ҫ���ʼ������
#include <STC89C5xRC.H>
#include "Motor.h"
#include "Delay.h"
#include "Track.h"
#include "LED.h"
#include "Speed.h"
#include "Show.h"

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
        display_speed(speed);
    }
}