#include <iostream>
#include "Std_types.h"
#include "Register.hpp"

using std::cout;
using std::endl;

int main()
{
    u8 regValue = 255;
    u8 value;

    Register <u8>UART(255, RESERVED);
    UART.clearBit(0);
    UART.setRegisterValue(regValue);
    UART.getRegisterValue(value);
    printf("%d", value);
    
    return 0;
}

