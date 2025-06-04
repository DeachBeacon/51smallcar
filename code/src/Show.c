#include <STC89C5xRC.H>
#include "Show.h"

/**
 * @brief ���߶����������ʾ�ٶ�ֵ��0-99��
 * @param speed ��Ҫ��ʾ���ٶ�ֵ��0-99��
 */
void display_speed(unsigned char speed) 
{
    unsigned char tens = speed / 10;   // ��ȡʮλ��
    unsigned char ones = speed % 10;   // ��ȡ��λ��

    // ���ø�λ���ֵ�4λ���������
    SD0 = (ones >> 0) & 0x01;  // 1S - LSB
    SD1 = (ones >> 1) & 0x01;  // 2S
    SD2 = (ones >> 2) & 0x01;  // 3S
    SD3 = (ones >> 3) & 0x01;  // 4S - MSB

    // ����ʮλ���ֵ�4λ���������
    SD4 = (tens >> 0) & 0x01;  // 5S - LSB
    SD5 = (tens >> 1) & 0x01;  // 6S
    SD6 = (tens >> 2) & 0x01;  // 7S
    SD7 = (tens >> 3) & 0x01;  // 8S - MSB
}