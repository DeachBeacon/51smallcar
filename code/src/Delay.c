#include <STC89C5xRC.H>
#include "Delay.h"

void Delay1ms(void){
    unsigned char i = 4;   // 外层循环次数
    unsigned char j;       // 内层循环变量
    
    while(i--){
        j = 249;           // 内层循环次数=249+1=250次
        while(j--);        // 250次*2周期=500机器周期
    }
}

void DelayMs(unsigned char ms){
    while(ms--){
        Delay1ms();        // 调用1ms基础延时函数
    }
}

void Delay(void){
    unsigned char i = 3;   // 外层循环次数
    unsigned char t;       // 内层循环变量
    while(t--){
        t = 249;           // 内层循环次数=249+1=250次
        while(t--); 
    }
}