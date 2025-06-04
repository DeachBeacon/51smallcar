
#include "Motor.h"
#include "LED.h"
#include "Delay.h"
#include <STC89C5xRC.H>

// ��ʼ�����е����������
void Motor_Init(void) {
    M1A = 0; M1B = 0;
    M2A = 0; M2B = 0;
    M3A = 0; M3B = 0;
    M4A = 0; M4B = 0;
}

// ������ƺ���
void Motor_Control(unsigned char cmd) {
    if(cmd == FORWARD){
        M1A = 1; M1B = 0; // ��ǰ��ת
        M2A = 1; M2B = 0; // ��ǰ��ת
        M3A = 1; M3B = 0; // �����ת
        M4A = 1; M4B = 0; // �Һ���ת
        LED_2(LED_ON);
        DelayMs(1);
        Motor_Init();
        DelayMs(9);
    }
    else if(cmd == RIGHT){
        M1A = 1; M1B = 0; // ��ǰ��ת
        M2A = 0; M2B = 1; // ��ǰ��ת
        M3A = 1; M3B = 0; // �����ת
        M4A = 0; M4B = 1; // �Һ�ת
        LED_4(LED_ON);
        DelayMs(1);
        Motor_Init();
        DelayMs(6);
    }
    else if(cmd == LEFT){
        M1A = 0; M1B = 1; // ��ǰ��ת
        M2A = 1; M2B = 0; // ��ǰ��ת
        M3A = 0; M3B = 1; // ���ת
        M4A = 1; M4B = 0; // �Һ���ת
        LED_3(LED_ON);
        DelayMs(1);
        Motor_Init();
        DelayMs(6);
    }
    else if(cmd == STOP){
        M1A = 0; M1B = 0;
        M2A = 0; M2B = 0;
        M3A = 0; M3B = 0;
        M4A = 0; M4B = 0;
        LED_5(LED_ON);
        LED_6(LED_ON);
        DelayMs(10);
    }          
    LED_Init();
}