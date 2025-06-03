#ifndef __SPEED_H__
#define __SPEED_H__

#include <STC89C5xRC.H>

// ����ģ�����Ŷ���
sbit SP4 = P0^4;   // ����ģ��A0��������ã�
sbit SP5 = P0^5;   // ����ģ��D0��������ã�

// �����ְ뾶���壨��λ�����ף�����ʵ�ʵ�����
#define INNER_RADIUS  50   // ���ְ뾶
#define OUTER_RADIUS  80   // ���ְ뾶

// ����С������������ʵ�ʳ�������޸ģ�
#define HOLES_PER_REVOLUTION 20

// ��������
unsigned char Get_Speed(void);

#endif // __SPEED_H__