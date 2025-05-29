#include "Track.h"
#include "Delay.h"

void Track_Control(void) {
    // 1. 检测是否所有传感器都看到黑线
    if (T0 == 0 && T1 == 0 && T2 == 0 && T3 == 0 && T4 == 0 && T5 == 0 && T6 == 0 && T7 == 0) {
        stop(0);  // 调用停止函数
        return;
    }
    
    // 2. 检测最右边传感器
    if (T7 == 0) {
        Control_Motion(TURN_RIGHT, LOW_SPEED);  // 低速右转
    }
    // 3. 检测右边第二传感器（且最右边没有检测到）
    else if ((T5 == 0 || T6 == 0) && T7 != 0) {
        Control_Motion(TURN_RIGHT, HIGH_SPEED); // 高速右转
    }
    // 4. 检测最左边传感器
    else if (T0 == 0) {
        Control_Motion(TURN_LEFT, LOW_SPEED);  // 低速左转
    }
    // 5. 检测左边第二传感器（且最左边没有检测到）
    else if ((T1 == 0 || T2 == 0) && T0 != 0) {
        Control_Motion(TURN_LEFT, HIGH_SPEED); // 高速左转
    }
    // 6. 检测中间传感器
    else if (T3 == 0 || T4 == 0) {
        Control_Motion(FORWARD, HIGH_SPEED);  // 高速前进
    }
    // 7. 其他情况保持前进（可选）
    else {
        Control_Motion(FORWARD, LOW_SPEED);
    }
    Delay(10);  // 短暂延时稳定动作
}