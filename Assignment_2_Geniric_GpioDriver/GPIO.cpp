#include <iostream>
#include "AVR_GPIO.hpp"
#include "ARM_GPIO.hpp"

using namespace std;



typedef enum {

    AVR = 0,
    ARM

}MicroType;


class GPIO {

    protected:
        MicroType mT;
    public:

        GPIO ()
        {
            this->mT = AVR;
        }

        GPIO(MicroType mT)
        {
            this->mT = mT;
        }
        void PinMode_init(unsigned char PinNum, unsigned char PinMode);
        void digital_Write(unsigned char PinNum, unsigned char signal);
        unsigned char digital_Read(unsigned char pinNum);
};


void GPIO::PinMode_init(unsigned char PinNum, unsigned char PinMode)
{
    switch(mT) {

        case AVR:
        {
            AVR_PinMode(PinNum, PinMode);
            cout << "AVR PinMode Initialized" << endl;
            break;
        }
        
        case ARM:
        {
            ARM_PinMode(PinNum, PinMode);
            cout << "ARM PinMode Initialized" << endl;
            break;
        }

        default:
        {
            cout << "your action is wrong" << endl;
        }

    }
}

void GPIO::digital_Write(unsigned char PinNum, unsigned char signal){

    switch(mT) {

        case AVR:
        {
            AVR_digitalWrite(PinNum, signal);
            cout << "AVR writed on the pin" << endl;
            break;
        }
        
        case ARM:
        {
            ARM_digitalWrite(PinNum, signal);
            cout << "ARM writed on the pin" << endl;
            break;
        }

        default:
        {
            cout << "your action is wrong" << endl;
        }

    }

}

unsigned char GPIO::digital_Read(unsigned char PinNum){

    switch(mT) {

        case AVR:
        {
            AVR_digitalRead(PinNum);
            cout << "AVR Read from the pin" << endl;
            break;
        }
        
        case ARM:
        {
            ARM_digitalRead(PinNum);
            cout << "ARM Read from the pin" << endl;
            break;
        }

        default:
        {
            cout << "your action is wrong" << endl;
        }

    }

    return 0;

}




