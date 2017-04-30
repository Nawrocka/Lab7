#include "stdafx.h"
#include "Point.h"
#include <iostream>
#include <math.h>
using namespace std;

Point::Point():_x(0),_y(0)
{
}

Point::Point(float X1, float Y1)
{
	_x = X1;
	_y = Y1;
}

Point& Point::operator=(const Point& right)
{
	if (this == &right)
	{
		return *this;
	}

	_x = right._x;
	_y = right._y;
	return *this;
}

void Point::operator=(const int number)
{
	this->_x = 0;
	this->_y = 0;
}

Point::~Point()
{
}
