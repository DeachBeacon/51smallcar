#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <STC89C5xRC.H>
#include "Delay.h"

sbit M1A=P2^0;                            //定义左前电机驱动A端
sbit M1B=P2^1;                            //定义左前电机驱动B端
sbit M2A=P2^2;                            //定义右前电机驱动A端
sbit M2B=P2^3;                            //定义右前电机驱动B端
sbit M3A=P2^4;                            //定义左后电机驱动A端
sbit M3B=P2^5;                            //定义左后电机驱动B端
sbit M4A=P2^6;                            //定义右后电机驱动A端
sbit M4B=P2^7;                            //定义右后电机驱动B端

// 电机方向定义
#define FORWARD     1
#define TURN_LEFT   2
#define TURN_RIGHT  3

// 速度档位定义
#define HIGH_SPEED  1
#define LOW_SPEED   2

// PWM占空比配置（单位：1%）
#define FORWARD_HIGH_DUTY  40    // 前进高速档占空比70%
#define FORWARD_LOW_DUTY   20    // 前进低速档占空比40%
#define TURN_HIGH_DUTY     20    // 转向高速档占空比30%
#define TURN_LOW_DUTY      10    // 转向低速档占空比20%

// 电机方向控制宏
#define ALL_MOTOR_FORWARD {M1A=1; M1B=0; M2A=1; M2B=0; M3A=1; M3B=0; M4A=1; M4B=0;}
#define LEFT_MOTOR_STOP   {M1A=0; M1B=0; M3A=0; M3B=0;}
#define RIGHT_MOTOR_STOP  {M2A=0; M2B=0; M4A=0; M4B=0;}

// 函数声明
void stop(unsigned char i);
void Motor_Init(void);           //main里要先调用这个初始化PWM
void Control_Motion(unsigned char direction, unsigned char speed);

#endif
