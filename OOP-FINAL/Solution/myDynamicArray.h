#pragma once
#include <iostream>

template <class type>

class myDynamicArray
{
public:
    int size;
    int capacity;
    type * DynamicArray;

    int getsize();
    int getcapacity();
    type* gethead();
    
    void add( type );
    type remove();
    
    myDynamicArray();
    ~myDynamicArray();
};