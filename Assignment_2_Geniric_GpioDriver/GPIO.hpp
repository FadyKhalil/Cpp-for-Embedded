

#ifndef _GPIO_H_
#define _GPIO_H_


class GPIO 
{
    public:

        virtual void PinMode(unsigned char PinNum, unsigned char PinMode);
        virtual void DigitalWrite(unsigned char PinNum, unsigned char Signal);
        virtual unsigned char DigitalRead(unsigned char pinNum);

};


#endif