#ifndef SHOW_H
#define SHOW_H
#include <STC89C5xRC.H>

// 定义数码管控制引脚
sbit SD0 = P1^0;  // 1S
sbit SD1 = P1^1;  // 2S
sbit SD2 = P3^2;  // 3S
sbit SD3 = P3^3;  // 4S
sbit SD4 = P3^4;  // 5S
sbit SD5 = P3^5;  // 6S
sbit SD6 = P3^6;  // 7S
sbit SD7 = P3^7;  // 8S

void display_speed(unsigned char speed);

#endif