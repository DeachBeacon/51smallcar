#ifndef __SPEED_H__
#define __SPEED_H__

#include <STC89C5xRC.H>

// 测速模块引脚定义
sbit SP4 = P0^4;   // 测速模块A0输出（备用）
sbit SP5 = P0^5;   // 测速模块D0输出（主用）

// 内外轮半径定义（单位：毫米，根据实际调整）
#define INNER_RADIUS  50   // 内轮半径
#define OUTER_RADIUS  80   // 外轮半径

// 车轮小孔数量（根据实际车轮设计修改）
#define HOLES_PER_REVOLUTION 20

// 函数声明
unsigned char Get_Speed(void);

#endif // __SPEED_H__