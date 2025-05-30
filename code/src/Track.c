#include "Track.h"
#include "Delay.h"
#include <STC89C5xRC.H>

void Track_Init(void) {
    P0 = 0xFF;     // 设置P0口所有引脚为高电平，启用内部上拉
}
void Track_Control(void) {
    // 1. 检测是否所有传感器都看到黑线
    if (TC0 == 0 && TC1 == 0 && TC2 == 0 && TC3 == 0 && TC4 == 0 && TC5 == 0 && TC6 == 0 && TC7 == 0) {
        stop(0);  // 调用停止函数
        return;
    }
    
    // 2. 检测最右边传感器
    if (TC7 == 0) {
        Control_Motion(TURN_RIGHT, LOW_SPEED);  // 低速右转
    }
    // 3. 检测右边第二传感器（且最右边没有检测到）
    else if ((TC5 == 0 || TC6 == 0) && TC7 != 0) {
        Control_Motion(TURN_RIGHT, HIGH_SPEED); // 高速右转
    }
    // 4. 检测最左边传感器
    else if (TC0 == 0) {
        Control_Motion(TURN_LEFT, LOW_SPEED);  // 低速左转
    }
    // 5. 检测左边第二传感器（且最左边没有检测到）
    else if ((TC1 == 0 || TC2 == 0) && TC0 != 0) {
        Control_Motion(TURN_LEFT, HIGH_SPEED); // 高速左转
    }
    // 6. 检测中间传感器
    else if (TC3 == 0 || TC4 == 0) {
        Control_Motion(FORWARD, HIGH_SPEED);  // 高速前进
    }
    // 7. 其他情况保持前进（可选）
    else {
        Control_Motion(FORWARD, LOW_SPEED);
    }
    Delay(10);  // 短暂延时稳定动作
}