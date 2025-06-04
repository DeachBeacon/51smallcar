#include <STC89C5xRC.H>
#include "Show.h"

/**
 * @brief 在七段数码管上显示速度值（0-99）
 * @param speed 需要显示的速度值（0-99）
 */
void display_speed(unsigned char speed) 
{
    unsigned char tens = speed / 10;   // 获取十位数
    unsigned char ones = speed % 10;   // 获取个位数

    // 设置个位数字的4位二进制输出
    SD0 = (ones >> 0) & 0x01;  // 1S - LSB
    SD1 = (ones >> 1) & 0x01;  // 2S
    SD2 = (ones >> 2) & 0x01;  // 3S
    SD3 = (ones >> 3) & 0x01;  // 4S - MSB

    // 设置十位数字的4位二进制输出
    SD4 = (tens >> 0) & 0x01;  // 5S - LSB
    SD5 = (tens >> 1) & 0x01;  // 6S
    SD6 = (tens >> 2) & 0x01;  // 7S
    SD7 = (tens >> 3) & 0x01;  // 8S - MSB
}