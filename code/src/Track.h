#ifndef __TRACK_H__
#define __TRACK_H__

#include <STC89C5xRC.H>
#include "Motor.h"

// ���������Ŷ���
sbit T0 = P0^0;  // ����ߴ�����
sbit T1 = P0^1;   // ��ߵڶ�������
sbit T2 = P0^2;
sbit T3 = P0^3;   // �м䴫����1
sbit T4 = P0^4;   // �м䴫����2
sbit T5 = P0^5;
sbit T6 = P0^6;   // �ұߵڶ�������
sbit T7 = P0^7;   // ���ұߴ�����

// ѭ�����ƺ�������
void Track_Control(void);

#endif