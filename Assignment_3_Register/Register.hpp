
#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include "Std_types.h"
#include "Register_cfg.hpp"
#include "Register_prv.h"
#include "Bit_utils.h"


using std::cout;
using std::endl;


template<typename T>
class Register
{
private:
    Byte_Read_Write accessRW;
    Byte_Read_Write accessR_RW;
    T reg;
public:

    /*Constructor*/
    Register ();
    Register (T reg, u32 permission);

    /*Method for the class*/
    ErrorStatus setRegisterValue(T byte);
    ErrorStatus getRegisterValue(T & Add_reg);
    ErrorStatus setBit(u8 bit);
    ErrorStatus clearBit(u8 bit);
    ErrorStatus getBit(u8 bit, u8 & Add_bit);
    //ErrorStatus setPermission(Permission permission);


};

template<typename T>
Register<T> :: Register()
{
    this->reg = 0x00;
    this->accessRW.status = READONLY;
    this->accessRW = RESERVED;
}


template<typename T>
Register<T> :: Register(T reg, u32 permission)
{

    this->reg = reg;
    if (permission != RESERVED || permission != READONLY || permission != WRITEONLY || permission != READWRITE)
    {
        this->reg = 0x00;
        this->accessRW.status = READONLY;
        this->accessRW.status = RESERVED;
    }
    else
    {
        this->reg = reg;
        this->accessRW.status = READONLY;
        this->accessRW.status = RESERVED;

    }
}


template<typename T>
ErrorStatus Register<T> :: setRegisterValue(T byte)
{
    ErrorStatus Loc_ErrorStatus = NoError;
    if (accessRW.status == READONLY)
    {
        Loc_ErrorStatus = ReadOnly;
    }
    else if (accessR_RW.status == RESERVED)
    {
        Loc_ErrorStatus = Reserved;
    }
    else
    {
        reg = byte;
    }
    return Loc_ErrorStatus;
}


template<typename T>
ErrorStatus Register<T> :: getRegisterValue(T & Copy_reg)
{
    ErrorStatus Loc_ErrorStatus = NoError;
    if (this->accessRW.status == WRITEONLY)
    {
        Loc_ErrorStatus = WriteOnly;
    }
    else if (this->accessR_RW.status == RESERVED)
    {
        Loc_ErrorStatus = Reserved;
    }
    else
    {
        Copy_reg = this->reg;
    }
    return Loc_ErrorStatus;
}


template<typename T>
ErrorStatus Register<T> :: setBit(u8 bit)
{
    ErrorStatus Loc_ErrorStatus = NoError;
    if (bit > (sizeof(reg)*8)-1)
    {
        Loc_ErrorStatus = BitNotAvailable;
    }
    else if (GET_BIT(this->accessRW.status, bit) == read)
    {
        Loc_ErrorStatus = ReadOnly;
    }
    else if (GET_BIT(this->accessR_RW.status, bit) == reserved)
    {
        Loc_ErrorStatus = Reserved;
    }
    else
    {
        SET_BIT(reg,bit);
    }
    return Loc_ErrorStatus;
}


template<typename T>
ErrorStatus Register<T> :: getBit(u8 bit, u8 & Add_bit)
{
    ErrorStatus Loc_ErrorStatus = NoError;
    if (bit > (sizeof(reg)*8)-1)
    {
        Loc_ErrorStatus = BitNotAvailable;
    }
    else if (GET_BIT(this->accessRW.status, bit) == write)
    {
        Loc_ErrorStatus = WriteOnly;
    }
    else if (GET_BIT(this->accessR_RW.status, bit) == reserved)
    {
        Loc_ErrorStatus = Reserved;
    }
    else
    {
        Add_bit = GET_BIT(reg,bit);
    }
    return Loc_ErrorStatus;
}


template<typename T>
ErrorStatus Register<T> :: clearBit(u8 bit)
{
   ErrorStatus Loc_ErrorStatus = NoError;
    if (bit > (sizeof(reg)*8)-1)
    {
        Loc_ErrorStatus = BitNotAvailable;
    }
    else if (GET_BIT(this->accessRW.status, bit) == read)
    {
        Loc_ErrorStatus = ReadOnly;
    }
    else if (GET_BIT(this->accessR_RW.status, bit) == reserved)
    {
        Loc_ErrorStatus = Reserved;
    }
    else
    {
        CLR_BIT(reg,bit);
    }
    return Loc_ErrorStatus;
}


// template<typename T>
// void Register<T> :: setPermission(Permission permission)
// {
//     this->permission = permission;
// }


#endif