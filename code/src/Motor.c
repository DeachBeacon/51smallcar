
#include "Motor.h"
#include "LED.h"
#include "Delay.h"
#include <STC89C5xRC.H>

// 初始化所有电机控制引脚
void Motor_Init(void) {
    M1A = 0; M1B = 0;
    M2A = 0; M2B = 0;
    M3A = 0; M3B = 0;
    M4A = 0; M4B = 0;
}

// 电机控制函数
void Motor_Control(unsigned char cmd) {
    if(cmd == FORWARD){
        M1A = 1; M1B = 0; // 左前正转
        M2A = 1; M2B = 0; // 右前正转
        M3A = 1; M3B = 0; // 左后正转
        M4A = 1; M4B = 0; // 右后正转
        LED_2(LED_ON);
        DelayMs(1);
        Motor_Init();
        DelayMs(9);
    }
    else if(cmd == RIGHT){
        M1A = 1; M1B = 0; // 左前正转
        M2A = 0; M2B = 1; // 右前反转
        M3A = 1; M3B = 0; // 左后正转
        M4A = 0; M4B = 1; // 右后反转
        LED_4(LED_ON);
        DelayMs(1);
        Motor_Init();
        DelayMs(6);
    }
    else if(cmd == LEFT){
        M1A = 0; M1B = 1; // 左前反转
        M2A = 1; M2B = 0; // 右前正转
        M3A = 0; M3B = 1; // 左后反转
        M4A = 1; M4B = 0; // 右后正转
        LED_3(LED_ON);
        DelayMs(1);
        Motor_Init();
        DelayMs(6);
    }
    else if(cmd == STOP){
        M1A = 0; M1B = 0;
        M2A = 0; M2B = 0;
        M3A = 0; M3B = 0;
        M4A = 0; M4B = 0;
        LED_5(LED_ON);
        LED_6(LED_ON);
        DelayMs(10);
    }          
    LED_Init();
}