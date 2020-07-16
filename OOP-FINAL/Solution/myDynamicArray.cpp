#include "myDynamicArray.h"

using namespace std;

template <class type>
int myDynamicArray<type>::getsize(){
    return size;
}
template <class type>
int myDynamicArray<type>::getcapacity(){
    return capacity;
}
template <class type>
type* myDynamicArray<type>::gethead(){
    return DynamicArray;
}

template <class type>
void myDynamicArray<type>::add(type input){
    if (size < capacity){
        DynamicArray[size] = input;
        size++;
    }
    else{
        capacity = capacity * 2;
        type * newarray = new type[capacity];
        for (int i = 0; i < size; i++)
        {
            newarray[i] = DynamicArray[i];
        }

        delete [] DynamicArray;
        DynamicArray = newarray;

        DynamicArray[size] = input;
        size++;
        cout << "array resized " << capacity << endl;
    }
}

template <class type>
type myDynamicArray<type>::remove(){
    if (size <= capacity/2){
        capacity = capacity / 2;
        type * newarray = new type[capacity];
        for (int i = 0; i < size; i++)
        {
            newarray[i] = DynamicArray[i];
        }

        type result = DynamicArray[size-1];

        delete [] DynamicArray;
        DynamicArray = newarray;
        DynamicArray[size-1] = 0;
        size--;
        cout << "array resized " << capacity << endl;
        return result;
    }
    else
    {
    	type result = DynamicArray[size-1];
        DynamicArray[size-1] = 0;
        size--;
        return result;
    }
}

template <class type>
myDynamicArray<type>::myDynamicArray()
{
    capacity = 5;
    size = 0;
    DynamicArray = new type[capacity];
    cout << "new array of capacity=" << capacity << " has been created" << endl;
}

template <class type>
myDynamicArray<type>::~myDynamicArray()
{
    delete[] DynamicArray;
    cout << "a dynamic array has been destroyed" << endl;
}

template <class type>
void myDynamicArray<type>::print()
{
    
}