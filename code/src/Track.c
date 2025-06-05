#include "Track.h"
#include "Delay.h"
#include <STC89C5xRC.H>

void Track_Init(void) {
    P0 = 0xFF;     // ����P0����������Ϊ�ߵ�ƽ�������ڲ�����
}

void Track_Control(void) {
    // ����Ƿ����д���������������
    if (TC0 == 1 && TC1 == 1 ) {
        Motor_Control(STOP);  
        return;
    }
    
    // ����ұߴ�����
    if (TC1 == 1) {
        Motor_Control(RIGHT);  
    }
    // �����ߴ�����
    else if (TC0 == 1) {
        Motor_Control(LEFT);  
    }
    // �����������ǰ��
    else {
        Motor_Control(FORWARD);
    }
}