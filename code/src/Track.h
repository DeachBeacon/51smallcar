#ifndef TRACK_H
#define TRACK_H 
#include <STC89C5xRC.H>
#include "Delay.h"
#include "Motor.h"

// 传感器引脚定义
sbit TC0 = P0^0;   // 左传感器
sbit TC1 = P0^1;   // 右传感器


// 循迹控制函数声明
void Track_Control(void);
void Track_Init(void);

#endif