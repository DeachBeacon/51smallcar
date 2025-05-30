#ifndef __TRACK_H__
#define __TRACK_H__

#include <STC89C5xRC.H>
#include "Motor.h"

// ���������Ŷ���
sbit TC0 = P0^0;   // ����ߴ�����
sbit TC1 = P0^1;   // ��ߵڶ�������
sbit TC2 = P0^2;
sbit TC3 = P0^3;   // �м䴫����1
sbit TC4 = P0^4;   // �м䴫����2
sbit TC5 = P0^5;
sbit TC6 = P0^6;   // �ұߵڶ�������
sbit TC7 = P0^7;   // ���ұߴ�����

// ѭ�����ƺ�������
void Track_Control(void);
void Track_Init(void);
#endif