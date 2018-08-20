#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <math.h>
#include "Element.h"


using namespace std;

int main()
{

	unsigned option;
	int vecDirection, nullVector;
	string type;
	
	Element element1, element2;
	Point point1, point2;
	Vector vector1, vector2;
	Triangle triangleA, triangleB, triangleC, triangleType;
	Line line1, line2;
	Segment segment1, segment2;

	/* Element's Name */
	cout << "Elements list: Point(1), Vector(2), Triangle(3), Line(4), Segment(5)" << endl;
	cin >> element1;
	cout << element1;

	/* Get option */
	element1.option(option);
	
		switch (option) 
		{
		case 1:
			/* Set and Get Point */
			/* Point 1 */
			point1.setPoint(4, 5, 7);
			point1.getPoint();

			/* Point 2 */
			// point2.setPoint(4, 5, 7);
			// point2.getPoint();
			cin >> point2;
			if (point1 == point2)
			{
				cout << "Equal Points!" << endl;
			}
			else
			{
				cout << "Points aren't equal!" << endl;
			}
			break;
		case 2:
			/* Set and Get Vector x, y, z */
			vector1.setVector(5, 5, 7);
			//vector2.setVector(7, 1, 2);
			vector1.getVector();
			//vector2.getVector();

			cout << "Vector 2" << endl;
			cin >> vector2; 
			/* Set and Get Vector A and B */
			vector1.setVectorAB(5, 2);
			vector1.getVectorAB();

			/* Vector Length calculation */
			cout << "Vector Length: " << vector1.vectorLength();
			cout << endl;

			/* Single or NULL Vector */
			cout << "Vector Direction: " << vector1.vectorDirection(vecDirection);
			cout << endl;

			/* Null Vector */
			vector1.nullVectorCheck();

			/* Vector Parallelism */
			vector1.vectorParallelism(4, 5, 7);
			cout << endl;

			/* Vector Perpendicularity */
			vector1.vectorPerpendicularity(4, 5, 7);
			cout << endl;

			/* Sum of Vectors */
			cout << "Sum of both vectors is: ";
			cout << vector1 + vector2 << endl;

			/* Subtract Vectors */
			cout << "Subtraction of both vectors is: ";
			cout << vector1 - vector2 << endl;

			/* Multiplication with float number */
			cout << "Multiplication with float number! ";
			float x;
			cout << vector1 * x << endl;

			/* Multiplication of 2 vectors */
			cout << "Multiplication of both vectors is: ";
			cout << vector1 * vector2 << endl;

			/* Vector's multiplication of 2 vectors */
			cout << "Vector's multiplication of both vectors is: ";
			// cout << vector1 ^ vector2;
			cout << endl;

			/* Mixed multiplication of 3 vectors */
			cout << "Mixed multiplication of 3 vectors is: ";
			float result;
			cout << vector1.operator()(vector1, vector2, result) << endl;
			break;
		case 3:
			/* Set and Get Triangle Points */
			triangleA.setTriangle(3, 5, 7);
			cout << "TriangleA: " << endl;
			triangleA.getTriangle();
			triangleB.setTriangle(2, 4, 5);
			cout << "TriangleB: " << endl;
			triangleB.getTriangle();

			/* Input Triangle C */
			cout << "TriangleC: " << endl;
			cin >> triangleC;
			cout << triangleC;

			/* Equal Points Verification */
			try 
			{
				if ((triangleA == triangleB) || (triangleA == triangleC) || (triangleB == triangleC))
				{
					throw exception("Triangle points are equal!");
				}
				else
				{
					cout << "Triangle points aren't equal!" << endl;
				}
			}
			catch (exception &e)
			{
				cerr << e.what() << typeid(e).name() << endl;
			}
			cout << endl;

			/* Triangle Type */
			cout << "Type: " << triangleType.triangleType(type) << endl;

			/* Triangle Perimeter */
			cout << "TriangleC perimeter: " << triangleC.trianglePerimeter() << endl;

			/* Triangle Area */
			cout << "TriangleC area: " << triangleC.triangleArea() << endl;
			break;
		case 4:
			/* Line */
			cout << "No options for line, sorry!\n";
			break;

		case 5:
			/* Segment */
			cout << "No options for segment, sorry!\n";
			break;
		case 0:
			return 0;
			break;
		}


	system("PAUSE");
	return 0;
}