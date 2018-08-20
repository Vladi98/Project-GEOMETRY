#ifndef _ELEMENT_H
#define _ELEMENT_H
#include <string>
#include <math.h>

using namespace std;

class Element
{
    public:
	    Element();
		istream & ext(istream & in);
		ostream & ins(ostream &out) const;
		bool operator==(const Element &);
		friend istream & operator >> (istream & is, Element & rhs)
		{
			return rhs.ext(is);
		}
		friend ostream & operator << (ostream & os, const Element & rhs)
		{
			return rhs.ins(os);
		}
		unsigned option(unsigned &) const;
	    virtual ~Element();

    protected:
		string name;

};

class Point: public Element
{
    public:
	    Point();
		void setPoint(double, double, double);
		void getPoint() const;
		istream & ext(istream & in);
		ostream & ins(ostream &out) const;
		friend istream & operator >> (istream & is, Point & rhs)
		{
			return rhs.ext(is);
		}
		friend ostream & operator << (ostream & os, const Point & rhs)
		{
			return rhs.ins(os);
		}
		bool operator==(const Point &);
	    virtual ~Point();

    protected:
		double x, y, z;
};

class Vector: public Point
{
    public:
		Vector();
		void setVector(float, float, float);
		void setVectorAB(float, float);
		void getVector() const;
		void getVectorAB() const;
		istream & ext(istream & in);
		ostream & ins(ostream &out) const;
		friend istream & operator >> (istream & is, Vector & rhs)
		{
			return rhs.ext(is);
		}
		friend ostream & operator << (ostream & os, const Vector & rhs)
		{
			return rhs.ins(os);
		}
		float vectorLength();
		int vectorDirection(int &);
		Vector vectorProection();
		bool nullVectorCheck();
		bool vectorParallelism(float, float, float);
		bool vectorPerpendicularity(float, float, float);
		float operator + (const Vector &rhs);
		float operator - (const Vector &rhs);
		float operator * (float &x);
		float operator * (const Vector &rhs);
		float operator ^ (const Vector &rhs);
		float operator ()(const Vector &, const Vector &, float &);


		virtual ~Vector();

    protected:
		float x, y, z;
		float pointA, pointB;
};

class Triangle: public Point
{
public:
	Triangle();
	istream & ext(istream & in);
	ostream & ins(ostream &out) const;
	friend istream & operator >> (istream & is, Triangle & rhs)
	{
		return rhs.ext(is);
	}
	friend ostream & operator << (ostream & os, const Triangle & rhs)
	{
		return rhs.ins(os);
	}
	void setTriangle(float, float, float);
	void getTriangle() const;
	bool operator==(const Triangle &);
	string triangleType(string &);
	float triangleArea();
	float trianglePerimeter();
	virtual ~Triangle();

protected:
	float x, y, z;
	
};

class Line: public Vector
{
public:
	Line();
	virtual ~Line();

private:

};

class Segment: public Line
{
public:
	Segment();
	void setSegment(float, float, float, Point &, Vector &);
	void getSegment() const;

	virtual ~Segment();

private:
	float x, y, z;

};


#endif