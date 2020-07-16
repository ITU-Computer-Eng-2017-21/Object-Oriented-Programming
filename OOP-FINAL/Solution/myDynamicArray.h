#pragma once
#include <iostream>

template <class type>
class myDynamicArray
{
private:
    int size;
    int capacity;
    type * DynamicArray;
public:
    myDynamicArray();
    ~myDynamicArray();

    int getsize();
    int getcapacity();
    type* gethead();

    void add( type );
    type remove();
    void print();
};