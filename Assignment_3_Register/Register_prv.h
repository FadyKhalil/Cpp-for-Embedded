

#ifndef REGISTER_PRV_H_
#define REGISTER_PRV_H_

#define WRITEONLY    0x00000000
#define READONLY     0xFFFFFFFF

#define RESERVED     0x00000000
#define READWRITE    0xFFFFFFFF


typedef enum {

    write = 0,
    read,
    reserved = 0,
    readWrite

}statusOfReadWrite;

#endif