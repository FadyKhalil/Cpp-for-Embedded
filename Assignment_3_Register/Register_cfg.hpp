
#ifndef REGISTER_CFG_HPP_
#define REGISTER_CFG_HPP_

#include "Std_types.h"


typedef enum
{
    ReadOnly = 0,
    WriteOnly,
    Reserved,
    BitNotAvailable,
    NoError

}ErrorStatus;

typedef union
{
    struct
    {
        u32 bit00 : 1;
        u32 bit01 : 1;
        u32 bit02 : 1;
        u32 bit03 : 1;
        u32 bit04 : 1;
        u32 bit05 : 1;
        u32 bit06 : 1;
        u32 bit07 : 1;
        u32 bit08 : 1;
        u32 bit09 : 1;
        u32 bit10 : 1;
        u32 bit11 : 1;
        u32 bit12 : 1;
        u32 bit13 : 1;
        u32 bit14 : 1;
        u32 bit15 : 1;
        u32 bit16 : 1;
        u32 bit17 : 1;
        u32 bit18 : 1;
        u32 bit19 : 1;
        u32 bit20 : 1;
        u32 bit21 : 1;
        u32 bit22 : 1;
        u32 bit23 : 1;
        u32 bit24 : 1;
        u32 bit25 : 1;
        u32 bit26 : 1;
        u32 bit27 : 1;
        u32 bit28 : 1;
        u32 bit29 : 1;
        u32 bit30 : 1;
        u32 bit31 : 1;
    }BitStatus;

    u32 status;

}Byte_Read_Write;


#endif