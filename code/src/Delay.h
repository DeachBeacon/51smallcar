#ifndef DELAY_H
#define DELAY_H
#include <STC89C5xRC.H>

                        

void Delay(unsigned int t)
{
    while(t--);
}

#endif