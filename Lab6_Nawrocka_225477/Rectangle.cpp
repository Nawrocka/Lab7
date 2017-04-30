#include "stdafx.h"
#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string Name, string Color) :Figure(Name, Color)
{
	bool check = true;
	while (check)
	{
		if ((way[2] != sqrt(pow(way[0], 2) + pow(way[1], 2))) || (way[0]==0))
		{
			Complement();
			cout << "It's not a square!" << endl << "Pick one more time: " << endl;
		}
		else check = false;
	}
}

Rectangle::Rectangle():Figure()
{
}

void Rectangle::Introduce()
{
	cout << "I'm a Rectangle " << name << endl;
	cout << "My color is beautifull:  " << color << endl;
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
}
