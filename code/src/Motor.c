#include "Motor.h"
#include "LED.h"
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
                LED_2(LED_ON);          
            } else {
                Compare = FORWARD_LOW_DUTY;
                LED_3(LED_ON);
            }
            ALL_MOTOR_FORWARD;
            LED_6(LED_ON);
            break;
            
        case TURN_LEFT:
            // ��תʱ��������٣��Ҳ�������
            if (speed == HIGH_SPEED) {
                Compare = TURN_HIGH_DUTY;
                LED_2(LED_ON);
            } else {
                Compare = TURN_LOW_DUTY;
                LED_3(LED_ON);
            }
            LEFT_MOTOR_STOP;
            M2A = 1; M2B = 0; M4A = 1; M4B = 0;
            LED_5(LED_ON);
            break;
            
        case TURN_RIGHT:
            // ��תʱ�Ҳ������٣����������
            if (speed == HIGH_SPEED) {
                Compare = TURN_HIGH_DUTY;
                LED_2(LED_ON);
            } else {
                Compare = TURN_LOW_DUTY;
                LED_3(LED_ON);
            }
            RIGHT_MOTOR_STOP;
            M1A = 1; M1B = 0; M3A = 1; M3B = 0;
            LED_4(LED_ON);
            break;
    }
}
void stop(unsigned char i){
    if (i == 0) {
        M1A = 0; M1B = 0;
        M2A = 0; M2B = 0;
        M3A = 0; M3B = 0;
        M4A = 0; M4B = 0;
        LED_2(LED_ON);
        LED_3(LED_ON);
        LED_4(LED_ON);
        LED_5(LED_ON);
        LED_6(LED_ON);
        LED_7(LED_ON);
    }
}