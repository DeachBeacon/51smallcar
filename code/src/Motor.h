#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <STC89C5xRC.H>

// ������Ŷ���
sbit M1A = P2^0; // ��ǰ���A
sbit M1B = P2^1; // ��ǰ���B
sbit M2A = P2^2; // ��ǰ���A
sbit M2B = P2^3; // ��ǰ���B
sbit M3A = P2^4; // �����A
sbit M3B = P2^5; // �����B
sbit M4A = P2^6; // �Һ���A
sbit M4B = P2^7; // �Һ���B

// �˶�ģʽ����
#define STOP     0
#define FORWARD  1
#define LEFT     2
#define RIGHT    3

// ��������
void Motor_Init(void);
void Motor_Control(unsigned char cmd);

#endif