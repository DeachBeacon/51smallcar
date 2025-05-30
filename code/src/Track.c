#include "Track.h"
#include "Delay.h"
#include <STC89C5xRC.H>

void Track_Init(void) {
    P0 = 0xFF;     // ����P0����������Ϊ�ߵ�ƽ�������ڲ�����
}
void Track_Control(void) {
    // 1. ����Ƿ����д���������������
    if (TC0 == 0 && TC1 == 0 && TC2 == 0 && TC3 == 0 && TC4 == 0 && TC5 == 0 && TC6 == 0 && TC7 == 0) {
        stop(0);  // ����ֹͣ����
        return;
    }
    
    // 2. ������ұߴ�����
    if (TC7 == 0) {
        Control_Motion(TURN_RIGHT, LOW_SPEED);  // ������ת
    }
    // 3. ����ұߵڶ��������������ұ�û�м�⵽��
    else if ((TC5 == 0 || TC6 == 0) && TC7 != 0) {
        Control_Motion(TURN_RIGHT, HIGH_SPEED); // ������ת
    }
    // 4. �������ߴ�����
    else if (TC0 == 0) {
        Control_Motion(TURN_LEFT, LOW_SPEED);  // ������ת
    }
    // 5. �����ߵڶ����������������û�м�⵽��
    else if ((TC1 == 0 || TC2 == 0) && TC0 != 0) {
        Control_Motion(TURN_LEFT, HIGH_SPEED); // ������ת
    }
    // 6. ����м䴫����
    else if (TC3 == 0 || TC4 == 0) {
        Control_Motion(FORWARD, HIGH_SPEED);  // ����ǰ��
    }
    // 7. �����������ǰ������ѡ��
    else {
        Control_Motion(FORWARD, LOW_SPEED);
    }
    Delay(10);  // ������ʱ�ȶ�����
}