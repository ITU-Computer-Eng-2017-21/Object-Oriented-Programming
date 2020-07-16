#pragma once
#include "animal.h"
#include <string>

class cat: public animal
{
public:
	void outputvoice(); //pure virtual method
	
	cat();
	~cat();
};