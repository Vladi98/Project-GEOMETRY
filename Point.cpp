#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <exception>
#include "Element.h"
using namespace std;
 
Point::Point()
{
}

void Point::setPoint(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Point::getPoint() const
{
	cout << "Point" << endl;
	cout << "x: " << x << " " << "y: " << y << " " << "z: " << z << endl;
	return;
}

istream & Point::ext(istream & in)
{
	cout << "Values of x, y, z: ";
	in >> x >> y >> z;
	return in;
}

ostream & Point::ins(ostream &out) const
{
	return out << "Values of x, y, z: " << x << " " << y << " " << z << " " << endl;
}

bool Point::operator == (const Point &a)
{
	if ((this->x == a.x) && (this->y == a.y) && (this->z = a.z))
		return true;
	return false;
}
Point::~Point()
{
}