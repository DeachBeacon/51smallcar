#include "Motor.h"
#include <STC89C5xRC.H>

unsigned char Compare = 0;   // PWM�Ƚ�ֵ
unsigned char Counter = 0;   // ������

// ��ʱ��0��ʼ��������PWM���ɣ�
void Motor_Init(void) {     // ��main.c��Ҫ�ȵ��������������ʼ��PWM
    TMOD |= 0x02;           // ���ö�ʱ��0Ϊģʽ2��8λ�Զ����أ�
    TH0 = 0x00;             // ���ó�ʼֵ��2MHzʱ�ӣ�1us�������ڣ�
    TL0 = 0x00;
    ET0 = 1;                // ʹ�ܶ�ʱ��0�ж�
    EA = 1;                 // ȫ���ж�ʹ��
    TR0 = 1;                // ������ʱ��0
}

// �˶����ƺ���
void Control_Motion(unsigned char direction, unsigned char speed) {
    switch(direction) {
        case FORWARD:
            // �����ٶȵ�λ����ռ�ձ�
            if (speed == HIGH_SPEED) {
                Compare = FORWARD_HIGH_DUTY;
            } else {
                Compare = FORWARD_LOW_DUTY;
            }
            ALL_MOTOR_FORWARD;
            break;
            
        case TURN_LEFT:
            // ��תʱ��������٣��Ҳ�������
            if (speed == HIGH_SPEED) {
                Compare = TURN_HIGH_DUTY;
            } else {
                Compare = TURN_LOW_DUTY;
            }
            LEFT_MOTOR_STOP;
            M2A = 1; M2B = 0; M4A = 1; M4B = 0;
            break;
            
        case TURN_RIGHT:
            // ��תʱ�Ҳ������٣����������
            if (speed == HIGH_SPEED) {
                Compare = TURN_HIGH_DUTY;
            } else {
                Compare = TURN_LOW_DUTY;
            }
            RIGHT_MOTOR_STOP;
            M1A = 1; M1B = 0; M3A = 1; M3B = 0;
            break;
    }
}
void stop(unsigned int i){
    if (i == 0) {
        M1A = 0; M1B = 0;
        M2A = 0; M2B = 0;
        M3A = 0; M3B = 0;
        M4A = 0; M4B = 0;
    }
}