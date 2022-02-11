

#ifndef _AVR_GPIO_H
#define _AVR_GPIO_H

#include "GPIO.hpp"


class AVR : public GPIO
{
    public:
        void PinMode(unsigned char PinNum, unsigned char PinMode);
        void DigitalWrite(unsigned char PinNum, unsigned char Signal);
        unsigned char DigitalRead(unsigned char pinNum);

};


#endif