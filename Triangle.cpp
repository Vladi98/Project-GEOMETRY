#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <exception>
#include "Element.h"

using namespace std;

Triangle::Triangle() {}

void Triangle::setTriangle(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Triangle::getTriangle() const
{
	cout << "x: " << x << " " << "y: " << y << " " << "z: " << z << endl;
	return;
}

istream & Triangle::ext(istream & in)
{
	cout << "Values of x, y, z: ";
	in >> x >> y >> z;
	return in;
}

ostream & Triangle::ins(ostream &out) const
{
	return out << "Values of x, y, z: " << x << " " << y << " " << z << " " << endl;
}

bool Triangle::operator == (const Triangle &a)
{
	if ((this->x == a.x) && (this->y == a.y) && (this->z = a.z))
		return true;
	return false;
}

string Triangle::triangleType(string & type)
{
	do 
	{
		cout << "Triangle type (isoceles, equilateral, angled, rectangular, thong): ";
		cin >> type;
	} while (!((type == "isosceles") || (type == "equilateral") || (type == "angled") || (type == "rectangular") || (type == "thong")));
	return type;
}
float Triangle::triangleArea()
{
	float h;
	string type;
	if (this->triangleType(type) == "isosceles" || (this->triangleType(type) == "equilateral"))
	{
		h = sqrt(((this->z * this->z) - ((this->y)*(this->y)) / 2));
		return (this->y * h) / 2;
	}
}
float Triangle::trianglePerimeter()
{
	return this->x + this->y + this->z;
}

Triangle::~Triangle() {}