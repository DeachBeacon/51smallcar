//测试test
//所有变量要在最开始就声明
#include <STC89C5xRC.H>
#include "Motor.h"
#include "Delay.h"

sbit LED1=P1^2; // ?????????
sbit LED2=P1^3;
sbit LED3=P1^4;
sbit LED4=P1^5;
sbit LED5=P1^6;
sbit LED6=P1^7;

void main()
{
    unsigned int Time,i;
    stop(1);
    Control_Motion(1,1);
    while(1)
    {
        for(Time=0;Time<100;Time++) // ??????,????
        {
            for(i=0;i<20;i++) // ????
            {
                LED1=0x00;       // LED?
							  LED2=0x00;
							  LED3=0x00;
								LED4=0x00;
								LED5=0x00;
								LED6=0x00;
                Delay(Time);  // ??Time
							  LED1=0xff;       // LED?
							  LED2=0xff;
							  LED3=0xff;
								LED4=0x00;
								LED5=0x00;
								LED6=0x00;
                Delay(100-Time); // ??100-Time
            }
        }
        
        for(Time=100;Time>0;Time--) // ??????,????
        {
            for(i=0;i<20;i++) // ????
            {
                LED1=0x00;       // LED?
							  LED2=0x00;
							  LED3=0x00;
							  LED4=0x00;
								LED5=0x00;
								LED6=0x00;
                Delay(Time);  // ??Time
								LED1=0xff;       // LED?
							  LED2=0xff;
							  LED3=0xff;
								LED4=0x00;
								LED5=0x00;
								LED6=0x00;
                Delay(100-Time); // ??100-Time
            }
        }
    }
}