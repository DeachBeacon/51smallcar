#include "Speed.h"
#include "Delay.h"

// 获取小车速度（返回值：0-255，表示速度等级）
unsigned char Get_Speed(void) {
    unsigned long pulse_count = 0;  // 脉冲计数器
    unsigned char current_state, last_state;
    unsigned long time_ms = 100;    // 测量时间（单位：ms）
    unsigned int radius;            // 内外半径平均值
    unsigned long velocity;         // 线速度（单位：毫米/秒）
    unsigned char speed_norm;       // 归一化速度（0-255）

    // 初始化输入状态
    SP5 = 1;                        // 配置为输入模式（需先置高电平）
    last_state = SP5;               // 读取初始状态

    // 统计指定时间内的脉冲数
    while(time_ms--) {
        DelayMs(1);
        current_state = SP5;
        // 检测上升沿（小孔通过）
        if(current_state != last_state) {
            if(current_state == 1) {
                pulse_count++;
            }
            last_state = current_state;
        }
    }

    // 计算内外半径平均值
    radius = INNER_RADIUS / 2;

    // 计算线速度（单位：毫米/秒）
    // 公式：速度 = (脉冲数 * 10 / HOLES_PER_REVOLUTION) * 2 * π * radius
    // 近似处理：π ≈ 3.14 → 31416 / 10000
    // 速度 = (pulse_count * 10) * 2 * 31416 * radius / (HOLES_PER_REVOLUTION * 10000)
    velocity = (pulse_count * 10L) * 2L * 31416L * (unsigned long)radius;
    velocity /= (HOLES_PER_REVOLUTION * 10000L);

    // 归一化到0-255范围（假设最大速度为10000mm/s）
    speed_norm = (velocity > 10000) ? 255 : (unsigned char)(velocity * 255 / 10000);

    return speed_norm;
}