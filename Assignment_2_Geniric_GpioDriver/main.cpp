#include "GPIO.hpp"
#include "ARM_GPIO.hpp"
#include "AVR_GPIO.hpp"
#include <iostream>

/***
 * @a The default Board is AVR
 * @a To Chose ARM make sure you don't include the Header file of AVR
 * @a Use only the header file of the board you want to use
*/

#ifdef _AVR_GPIO_H
    #warning "You working on AVR Board"
#elif _ARM_GPIO_H
    //#warning "You working on ARM Board"
    printf("You using AVR");
#endif


int main (void) {

    return 0;

}

