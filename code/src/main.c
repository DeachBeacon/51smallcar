//���б���Ҫ���ʼ������
#include <STC89C5xRC.H>
#include "Motor.h"
#include "Delay.h"
#include "Track.h"
#include "LED.h"

void main()
{

    LED_Init();
    Track_Init();
    Motor_Init();
    while(1){
        Track_Control();

    }
}