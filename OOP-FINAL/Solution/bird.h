#pragma once
#include "animal.h"

class bird: public animal
{
public:
	void outputvoice(); //pure virtual method
	
	bird();
	~bird();
};