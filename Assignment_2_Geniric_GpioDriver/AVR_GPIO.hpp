#ifndef _AVR_GPIO_H
#define _AVR_GPIO_H


void AVR_PinMode(unsigned char PinNum, unsigned char PinMode);
void AVR_digitalWrite(unsigned char PinNum, unsigned char Signal);
unsigned char AVR_digitalRead(unsigned char pinNum);


#endif