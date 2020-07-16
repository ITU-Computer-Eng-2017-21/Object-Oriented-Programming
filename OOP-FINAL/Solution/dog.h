#pragma once
#include "animal.h"
#include <string>

class dog: public animal
{
public:
	void outputvoice(); //pure virtual method
	
	dog();
	~dog();
};