#include "Track.h"
#include "Delay.h"
#include <STC89C5xRC.H>

void Track_Init(void) {
    P0 = 0xFF;     // 设置P0口所有引脚为高电平，启用内部上拉
}

void Track_Control(void) {
    // 检测是否所有传感器都看到黑线
    if (TC0 == 1 && TC1 == 1 ) {
        Motor_Control(STOP);  
        return;
    }
    
    // 检测右边传感器
    if (TC1 == 1) {
        Motor_Control(RIGHT);  
    }
    // 检测左边传感器
    else if (TC0 == 1) {
        Motor_Control(LEFT);  
    }
    // 其他情况保持前进
    else {
        Motor_Control(FORWARD);
    }
}