#include <iostream>
#include "Std_types.h"
#include "Register.hpp"

using std::cout;
using std::endl;

int main()
{
    u8 regValue = 0;

    Register <u8>UART(84, reserved);
    // UART.setPermission(reserved);
    UART.setPermission(readWrite); 
    // printf("%d\n", UART.getRegisterValue());
    UART.setRegisterValue(34);
    regValue = UART.getRegisterValue();
    printf("%d\n", regValue);
    return 0;
}

