#ifndef __MOTOR_H__
#define __MOTOR_H__

#include <STC89C5xRC.H>
#include "Delay.h"

sbit M1A=P2^0;                            //������ǰ�������A��
sbit M1B=P2^1;                            //������ǰ�������B��
sbit M2A=P2^2;                            //������ǰ�������A��
sbit M2B=P2^3;                            //������ǰ�������B��
sbit M3A=P2^4;                            //�������������A��
sbit M3B=P2^5;                            //�������������B��
sbit M4A=P2^6;                            //�����Һ�������A��
sbit M4B=P2^7;                            //�����Һ�������B��

// ���������
#define FORWARD     1
#define TURN_LEFT   2
#define TURN_RIGHT  3

// �ٶȵ�λ����
#define HIGH_SPEED  1
#define LOW_SPEED   2

// PWMռ�ձ����ã���λ��1%��
#define FORWARD_HIGH_DUTY  40    // ǰ�����ٵ�ռ�ձ�70%
#define FORWARD_LOW_DUTY   20    // ǰ�����ٵ�ռ�ձ�40%
#define TURN_HIGH_DUTY     20    // ת����ٵ�ռ�ձ�30%
#define TURN_LOW_DUTY      10    // ת����ٵ�ռ�ձ�20%

// ���������ƺ�
#define ALL_MOTOR_FORWARD {M1A=1; M1B=0; M2A=1; M2B=0; M3A=1; M3B=0; M4A=1; M4B=0;}
#define LEFT_MOTOR_STOP   {M1A=0; M1B=0; M3A=0; M3B=0;}
#define RIGHT_MOTOR_STOP  {M2A=0; M2B=0; M4A=0; M4B=0;}

// ��������
void stop(unsigned char i);
void Motor_Init(void);           //main��Ҫ�ȵ��������ʼ��PWM
void Control_Motion(unsigned char direction, unsigned char speed);

#endif
