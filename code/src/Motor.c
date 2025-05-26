#include "Motor.h"
#include <STC89C5xRC.H>

unsigned char Compare = 0;   // PWM比较值
unsigned char Counter = 0;   // 计数器

// 定时器0初始化（用于PWM生成）
void Motor_Init(void) {     // 在main.c里要先调用这个函数来初始化PWM
    TMOD |= 0x02;           // 设置定时器0为模式2（8位自动重载）
    TH0 = 0x00;             // 设置初始值（2MHz时钟，1us计数周期）
    TL0 = 0x00;
    ET0 = 1;                // 使能定时器0中断
    EA = 1;                 // 全局中断使能
    TR0 = 1;                // 启动定时器0
}

// 运动控制函数
void Control_Motion(unsigned char direction, unsigned char speed) {
    switch(direction) {
        case FORWARD:
            // 根据速度档位设置占空比
            if (speed == HIGH_SPEED) {
                Compare = FORWARD_HIGH_DUTY;
            } else {
                Compare = FORWARD_LOW_DUTY;
            }
            ALL_MOTOR_FORWARD;
            break;
            
        case TURN_LEFT:
            // 左转时左侧电机减速，右侧电机保持
            if (speed == HIGH_SPEED) {
                Compare = TURN_HIGH_DUTY;
            } else {
                Compare = TURN_LOW_DUTY;
            }
            LEFT_MOTOR_STOP;
            M2A = 1; M2B = 0; M4A = 1; M4B = 0;
            break;
            
        case TURN_RIGHT:
            // 右转时右侧电机减速，左侧电机保持
            if (speed == HIGH_SPEED) {
                Compare = TURN_HIGH_DUTY;
            } else {
                Compare = TURN_LOW_DUTY;
            }
            RIGHT_MOTOR_STOP;
            M1A = 1; M1B = 0; M3A = 1; M3B = 0;
            break;
    }
}
void stop(unsigned int i){
    if (i == 0) {
        M1A = 0; M1B = 0;
        M2A = 0; M2B = 0;
        M3A = 0; M3B = 0;
        M4A = 0; M4B = 0;
    }
}