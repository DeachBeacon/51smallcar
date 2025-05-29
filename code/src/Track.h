#ifndef __TRACK_H__
#define __TRACK_H__

#include <STC89C5xRC.H>
#include "Motor.h"

// 传感器引脚定义
sbit T0 = P0^0;  // 最左边传感器
sbit T1 = P0^1;   // 左边第二传感器
sbit T2 = P0^2;
sbit T3 = P0^3;   // 中间传感器1
sbit T4 = P0^4;   // 中间传感器2
sbit T5 = P0^5;
sbit T6 = P0^6;   // 右边第二传感器
sbit T7 = P0^7;   // 最右边传感器

// 循迹控制函数声明
void Track_Control(void);

#endif