#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <exception>
#include "Element.h"

Segment::Segment()
{
}

void Segment::setSegment(float x, float y, float z, Point &p, Vector &v)
{
	this->x = x;
	this->y = y;
	this->z = z;
	return;
}

void Segment::getSegment() const
{
	cout << x << y << z;
	return;
}
Segment::~Segment()
{
}