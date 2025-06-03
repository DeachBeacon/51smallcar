#include "Speed.h"
#include "Delay.h"

// ��ȡС���ٶȣ�����ֵ��0-255����ʾ�ٶȵȼ���
unsigned char Get_Speed(void) {
    unsigned long pulse_count = 0;  // ���������
    unsigned char current_state, last_state;
    unsigned long time_ms = 100;    // ����ʱ�䣨��λ��ms��
    unsigned int radius;            // ����뾶ƽ��ֵ
    unsigned long velocity;         // ���ٶȣ���λ������/�룩
    unsigned char speed_norm;       // ��һ���ٶȣ�0-255��

    // ��ʼ������״̬
    SP5 = 1;                        // ����Ϊ����ģʽ�������øߵ�ƽ��
    last_state = SP5;               // ��ȡ��ʼ״̬

    // ͳ��ָ��ʱ���ڵ�������
    while(time_ms--) {
        DelayMs(1);
        current_state = SP5;
        // ��������أ�С��ͨ����
        if(current_state != last_state) {
            if(current_state == 1) {
                pulse_count++;
            }
            last_state = current_state;
        }
    }

    // ��������뾶ƽ��ֵ
    radius = INNER_RADIUS / 2;

    // �������ٶȣ���λ������/�룩
    // ��ʽ���ٶ� = (������ * 10 / HOLES_PER_REVOLUTION) * 2 * �� * radius
    // ���ƴ����� �� 3.14 �� 31416 / 10000
    // �ٶ� = (pulse_count * 10) * 2 * 31416 * radius / (HOLES_PER_REVOLUTION * 10000)
    velocity = (pulse_count * 10L) * 2L * 31416L * (unsigned long)radius;
    velocity /= (HOLES_PER_REVOLUTION * 10000L);

    // ��һ����0-255��Χ����������ٶ�Ϊ10000mm/s��
    speed_norm = (velocity > 10000) ? 255 : (unsigned char)(velocity * 255 / 10000);

    return speed_norm;
}