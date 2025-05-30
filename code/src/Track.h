#ifndef TRACK_H
#define TRACK_H 
#include <STC89C5xRC.H>
#include "Delay.h"
#include "Motor.h"

// ���������Ŷ���
sbit TC0 = P0^0;   // �󴫸���
sbit TC1 = P0^1;   // �Ҵ�����


// ѭ�����ƺ�������
void Track_Control(void);
void Track_Init(void);

#endif