#pragma once
#include "animal.h"
#include <string>

class dog: public animal
{
	void outputvoice(); //pure virtual method
	
	dog();
	~dog();
}