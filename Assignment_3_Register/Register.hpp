
#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include "Std_types.h"


using std::cout;
using std::endl;


typedef enum {

    read =0,
    write,
    readWrite,
    reserved

}Permission;

template<typename T>
class Register
{
private:
    T reg;
    Permission permission;
public:

    /*Constructor*/
    Register ();
    Register (T reg, Permission permission);

    /*Method for the class*/
    void setRegisterValue(T bit);
    T getRegisterValue();
    void setBit(T bit);
    void clearBit(T bit);
    T getBit(T bit);
    void setPermission(Permission permission);


};

template<typename T>
Register<T> :: Register()
{
    this->reg = reg;
    this->permission = readWrite;
}


template<typename T>
Register<T> :: Register(T reg, Permission permission)
{
    this->reg = reg;
    this->permission = permission;
}


template<typename T>
void Register<T> :: setRegisterValue(T bit)
{
    if (this->permission == read || this->permission == reserved)
    {
        cout << "Your permission is denied" << endl;
        return;
    }   
    else
    {
        reg = bit;
        return;
    }
}


template<typename T>
T Register<T> :: getRegisterValue()
{
    if (permission == write || permission == reserved)
    {
        cout << "Your permission is denied" << endl;
        return 0;
    }  
    else
        return reg;
}


template<typename T>
void Register<T> :: setBit(T bit)
{
    if (permission == read || permission == reserved)
    {
        cout << "Your permission is denied" << endl;
        return;
    }  
    else if(bit < sizeof(reg) && bit >=0)
        {
            reg |= (1 << bit);
        }
    else 
    {
        cout << "Your permission is denied" << endl;
        return; 
    }
}


template<typename T>
T Register<T> :: getBit(T bit)
{
    if (permission == write || permission == reserved)
    {
        cout << "Your permission is denied" << endl;
        return 0;
    }  
    else
        return ((reg >> bit) & 1);
}


template<typename T>
void Register<T> :: clearBit(T bit)
{
    if (permission == read || permission == reserved)
    {
        cout << "Your permission is denied" << endl;
        return;
    }  
    else if(bit <sizeof(reg) && bit >=0)
        {
            reg &= (~(1 << bit));
        }
    else
    {
        cout << "Your permission is denied" << endl;
        return;
    }  
}


template<typename T>
void Register<T> :: setPermission(Permission permission)
{
    this->permission = permission;
}


#endif