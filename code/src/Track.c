#include "Track.h"
#include "Delay.h"

void Track_Control(void) {
    // 1. ����Ƿ����д���������������
    if (T0 == 0 && T1 == 0 && T2 == 0 && T3 == 0 && T4 == 0 && T5 == 0 && T6 == 0 && T7 == 0) {
        stop(0);  // ����ֹͣ����
        return;
    }
    
    // 2. ������ұߴ�����
    if (T7 == 0) {
        Control_Motion(TURN_RIGHT, LOW_SPEED);  // ������ת
    }
    // 3. ����ұߵڶ��������������ұ�û�м�⵽��
    else if ((T5 == 0 || T6 == 0) && T7 != 0) {
        Control_Motion(TURN_RIGHT, HIGH_SPEED); // ������ת
    }
    // 4. �������ߴ�����
    else if (T0 == 0) {
        Control_Motion(TURN_LEFT, LOW_SPEED);  // ������ת
    }
    // 5. �����ߵڶ����������������û�м�⵽��
    else if ((T1 == 0 || T2 == 0) && T0 != 0) {
        Control_Motion(TURN_LEFT, HIGH_SPEED); // ������ת
    }
    // 6. ����м䴫����
    else if (T3 == 0 || T4 == 0) {
        Control_Motion(FORWARD, HIGH_SPEED);  // ����ǰ��
    }
    // 7. �����������ǰ������ѡ��
    else {
        Control_Motion(FORWARD, LOW_SPEED);
    }
    Delay(10);  // ������ʱ�ȶ�����
}