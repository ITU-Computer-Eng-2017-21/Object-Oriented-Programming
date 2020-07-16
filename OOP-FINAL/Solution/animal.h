#pragma once
#include <iostream>
#include <string>
#include "myDynamicArray.h"

#include "leg.h"

using namespace std;

class animal
{
private:
	string name;
public:
	virtual void outputvoice() = 0; //pure virtual method
	void setName(string);
	string getName()const {return name;}
	animal();
	~animal();
	friend ostream& operator<<(ostream&, const animal&);
};

ostream& operator <<(ostream& out, const animal& a1)  // Overloading <<
{
	out << a1.getName() << endl;
	return out;
};