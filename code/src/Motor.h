#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <STC89C5xRC.H>

// 电机引脚定义
sbit M1A = P2^0; // 左前电机A
sbit M1B = P2^1; // 左前电机B
sbit M2A = P2^2; // 右前电机A
sbit M2B = P2^3; // 右前电机B
sbit M3A = P2^4; // 左后电机A
sbit M3B = P2^5; // 左后电机B
sbit M4A = P2^6; // 右后电机A
sbit M4B = P2^7; // 右后电机B

// 运动模式定义
#define STOP     0
#define FORWARD  1
#define LEFT     2
#define RIGHT    3

// 函数声明
void Motor_Init(void);
void Motor_Control(unsigned char cmd);

#endif