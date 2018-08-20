#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <exception>
#include "Element.h"

using namespace std;

Vector::Vector() {}

void Vector::setVector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Vector::setVectorAB(float pointA, float pointB)
{
	this->pointA = pointA;
	this->pointB = pointB;
	return;
}

void Vector::getVector() const
{
	cout << "Vector" << endl;
	cout << "x: " << x << " " << "y: " << y << " " << "z: " << z << endl;
	return;
}

void Vector::getVectorAB() const
{
	cout << "PointA: " << pointA << " " << "PointB: " << pointB << endl;
	return;
}
istream & Vector::ext(istream & in)
{
	cout << "Values of x, y, z: ";
	in >> x >> y >> z;
	return in;
}

ostream & Vector::ins(ostream &out) const
{
	return out << "Values of x, y, z: " << x << " " << y << " " << z << " " << endl;
}
float Vector::vectorLength()
{
	float vectorLength = 0;
	vectorLength = sqrt(x*x + y*y + z*z);
	return vectorLength;
}

int Vector::vectorDirection(int & vecDirection)
{
	vecDirection = vectorLength();
	if ((vecDirection) == 1) {
		cout << "Single Vector! Vector direction: ";
		return vecDirection;
	}
	try {
		if (vecDirection == 0)
		{
			throw exception("Vector length is 0!");
		}
	}
	catch (exception &e)
	{
		cerr << e.what() << typeid(e).name() << endl;
	}
	return vecDirection;
}

bool Vector::nullVectorCheck()
{
	int nullVector = vectorLength();
	if (nullVector == 0)
	{
		cout << "NULL Vector!" << endl;
		return true;
	}
	cout << "Vector is not NULL!" << endl;
	return false;
}

bool Vector::vectorParallelism(float x, float y, float z)
{
	int vecLength = vectorLength();
	if ((this->x == x) && (this->y == y) && (this->z == z)) {
		cout << "Vectors Parallelism exists!";
		return true;
	}
	cout << "Vectors Parallelism doesn't exists!";
	try {
		if (vecLength == 0)
		{
			throw exception("Vector length is 0!");
		}
	}
	catch (exception &e)
	{
		cerr << e.what() << typeid(e).name() << endl;
	}
	return false;
}

bool Vector::vectorPerpendicularity(float x, float y, float z)
{
	int vecLength = vectorLength();
	if ((this->x*x+this->y*y+this->z*z) == 0) {
		cout << "Vectors Perpendicularity exists!";
		return true;
	}
	cout << "Vectors Perpendicularity doesn't exists!";
	try {
		if (vecLength == 0)
		{
			throw exception("Vector length is 0!");
		}
	}
	catch (exception &e)
	{
		cerr << e.what() << typeid(e).name() << endl;
	}
	return false;
}

float Vector::operator +(const Vector &rhs)
{
	return ((this->x + rhs.x) + (this->y + rhs.y) + (this->z + rhs.z));
}

float Vector::operator -(const Vector &rhs)
{
	return ((this->x - rhs.x) + (this->y - rhs.y) + (this->z - rhs.z));
}

float Vector::operator *(float &x)
{
	cout << "Enter the value of x: ";
	cin >> x;
	cout << "r * a = ";
	float xX = (this->x*x);
	float xY = (this->y*x);
	float xZ = (this->z*x);
	cout << "(" << xX << "," << xY << "," << xZ << ")" << endl;
	return 0;
}
float Vector::operator *(const Vector &rhs)
{
	return ((this->x * rhs.x) + (this->y * rhs.y) + (this->z * rhs.z));
}

float Vector::operator ^(const Vector &rhs)
{
	cout << "(" << ((this->y * rhs.z) - (this->z * rhs.y)) << ", " << (-(this->x*rhs.z)) + (this->z*rhs.x) << ", " << (this->x*rhs.y) - (this->y - rhs.x) << ")" << endl;
		return 0;
}

float Vector::operator()(const Vector &x, const Vector &y, float &result)
{
	result = ((x.x)*(y.x) + (x.y)*(y.y) + (x.z)*(y.z)) * ((this->x), (this->y), (this->z));
	return result;
}


Vector::~Vector() {}