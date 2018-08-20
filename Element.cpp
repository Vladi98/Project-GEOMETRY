#include "Element.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <exception>

using namespace std;
Element::Element()
{

}

istream & Element::ext(istream & in)
{
	cout << "Enter the name of the figure: ";
	in >> name;
	if (!((this->name == "point") || (this->name == "vector") || (this->name == "triangle") || (this->name == "segment") || (this->name == "line")))
	{
		cout << "No such element as " << name << endl;
	}
	else 
	{
		return in;
	}
}

ostream & Element::ins(ostream &out) const
{
	if ((this->name == "point") || (this->name == "vector") || (this->name == "triangle") || (this->name == "segment") || (this->name == "line"))
	{
		return out << "Figure Name: " << name << endl;
	}
}

bool Element::operator==(const Element &rhs)
{
	if ((this->name == "point") || (this->name == "vector") || (this->name == "triangle") || (this->name == "segment") || (this->name == "line"))
	    return true;
	return false;
}

unsigned Element::option(unsigned & option) const
{
	if (this->name == "point")
		option = 1;
	if (this->name == "vector")
		option = 2;
	if (this->name == "triangle")
		option = 3;
	if (this->name == "line")
		option = 4;
	if (this->name == "segment")
		option = 5;

	return option;
}
Element::~Element()
{
}
