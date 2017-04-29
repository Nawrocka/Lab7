#pragma once
#include <iostream>
using namespace std;
class Figure;

class Point
{
private:
	float _x, _y;
public:
	Point();
	Point(float X1, float Y1);

	Point& operator=(const Point& right);
	friend istream& operator>>(istream& o, Point& xy);
	
	friend float IsItDiamond(Point *pointers);
	friend float distance(Point *pointers, int i);

	friend void LengthsOfSides(Point *pointers,float* way);
	friend float Factor(Point *pointers, int i);
	friend float diagonal(Point * pointers, int i);
	friend bool IsItQuadrangle(Point* pointers);
	
	~Point();
};

