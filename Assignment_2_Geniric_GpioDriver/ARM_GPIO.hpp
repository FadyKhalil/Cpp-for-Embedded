

#ifndef _ARM_GPIO_H
#define _ARM_GPIO_H

#include "GPIO.hpp"


class ARM : public GPIO
{
    public:
        void PinMode(unsigned char PinNum, unsigned char PinMode);
        void DigitalWrite(unsigned char PinNum, unsigned char Signal);
        unsigned char DigitalRead(unsigned char pinNum);

};

#endif