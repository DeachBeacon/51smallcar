#include <STC89C5xRC.H>
#include "Delay.h"

void Delay1ms(void){
    unsigned char i = 4;   // ���ѭ������
    unsigned char j;       // �ڲ�ѭ������
    
    while(i--){
        j = 249;           // �ڲ�ѭ������ = 249+1 = 250��
        while(j--);        // 250��*2���� = 500��������
    }
}

void Delay(unsigned int ms){
    while(ms--){
        Delay1ms();        // ����1ms������ʱ����
    }
}