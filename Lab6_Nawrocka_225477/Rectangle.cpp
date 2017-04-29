#include "stdafx.h"
#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string Name, string Color) :Figure(Name, Color)
{
	bool check = true;
	while (check)
	{
		Complement();
		if (way[2] != sqrt( pow(way[0], 2) + pow(way[1], 2) ))
		{
			cout << "It's not a square!" << endl << "Pick one more time: " << endl;
		}
		else check = false;
	}
}

float Rectangle::Perimeter()
{
	float perimeter = 2 * (way[0] + way[1]);
	return perimeter;
}

float Rectangle::Area()
{
	float area = way[0] * way[1];
	return area;
}

Rectangle::~Rectangle()
{
	delete[] pointers;
}
