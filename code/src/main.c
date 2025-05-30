//测试test
//所有变量要在最开始就声明
#include <STC89C5xRC.H>
#include "Motor.h"
#include "Delay.h"
#include "Track.h"
#include "LED.h"

void main()
{
    LED_Init();
    stop(1);
    Track_Init();
    while(1)
    {
        Track_Control();
    }
}