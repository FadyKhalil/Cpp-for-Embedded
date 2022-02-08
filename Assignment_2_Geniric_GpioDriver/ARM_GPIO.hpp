#ifndef _ARM_GPIO_H
#define _ARM_GPIO_H


void ARM_PinMode(unsigned char PinNum, unsigned char PinMode);
void ARM_digitalWrite(unsigned char PinNum, unsigned char Signal);
unsigned char ARM_digitalRead(unsigned char pinNum);


#endif