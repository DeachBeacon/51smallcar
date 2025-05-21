#ifndef DRIVE_H
#define DRIVE_H
#include <STC89C5xRC.H>

sbit M1A=P2^0;                            //������ǰ�������A��
sbit M1B=P2^1;                            //������ǰ�������B��
 
sbit M2A=P2^2;                            //������ǰ�������A��
sbit M2B=P2^3;                            //������ǰ�������B��
 
sbit M3A=P2^4;                            //�������������A��
sbit M3B=P2^5;                            //�������������B��
 
sbit M4A=P2^6;                            //�����Һ�������A��
sbit M4B=P2^7;                            //�����Һ�������B��

void stop(int i){
    if (i == 0) {
        M1A = 0;
        M1B = 0;
        M2A = 0;
        M2B = 0;
        M3A = 0;
        M3B = 0;
        M4A = 0;
        M4B = 0;
    }
}
#endif