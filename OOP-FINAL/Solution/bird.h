#pragma once
#include "animal.h"

class bird: public animal
{
	void outputvoice(); //pure virtual method
	
	bird();
	~bird();
};