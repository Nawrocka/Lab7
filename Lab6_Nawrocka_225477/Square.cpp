#include "stdafx.h" 
#include <iostream>
#include "Square.h"
using namespace std;

Square::Square(string Name, string Color):Figure( Name, Color)
{
	bool check = true;
	while(check)
	{
		if ((way[0] != way[1]) && (way[2] != way[0] * sqrt(2)))
		{
			cout << "It's not a square!" << endl << "Pick one more time: " << endl;
			Complement();
		}
		else check = false;
	}
}

Square::Square()
{
}

 float Square:: Perimeter()  
{
	float perimeter = 4 * way[0];
	return perimeter;
}

float Square::Area()
{
	float area = way[0] * way[1];
	return area;
}


Square::~Square()
{
	delete[] pointers;
}
