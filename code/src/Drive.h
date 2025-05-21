#ifndef DRIVE_H
#define DRIVE_H
#include <STC89C5xRC.H>

sbit M1A=P2^0;                            //定义左前电机驱动A端
sbit M1B=P2^1;                            //定义左前电机驱动B端
 
sbit M2A=P2^2;                            //定义右前电机驱动A端
sbit M2B=P2^3;                            //定义右前电机驱动B端
 
sbit M3A=P2^4;                            //定义左后电机驱动A端
sbit M3B=P2^5;                            //定义左后电机驱动B端
 
sbit M4A=P2^6;                            //定义右后电机驱动A端
sbit M4B=P2^7;                            //定义右后电机驱动B端

void stop(int i){
    if (i == 0) {
        M1A = 0;
        M1B = 0;
        M2A = 0;
        M2B = 0;
        M3A = 0;
        M3B = 0;
        M4A = 0;
        M4B = 0;
    }
}
#endif