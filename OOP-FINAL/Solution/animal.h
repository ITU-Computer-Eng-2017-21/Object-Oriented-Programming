#pragma once
#include <iostream>
#include <string>
#include "myDynamicArray.h"

#include "leg.h"

using namespace std;

class animal{
	public:
	string name;
	
	virtual void outputvoice() = 0; //pure virtual method
	
	animal();
	~animal();
		
};