#include "stdafx.h"
#include <iostream>
#include "Diamond.h"
using namespace std;

Diamond::Diamond(string name, string color) :Figure(name, color)
{
	bool check = true;
	
	while (check)
	{
		Complement();
		a = IsItDiamond(pointers);

		if ((a==0) && (way[2] == way[0] * sqrt(2)))
		{
			cout << "It's not a square!" << endl << "Pick one more time: " << endl;
		}
		else check = false;
	}
}

float Diamond::Perimeter()
{
	float perimeter = 4 * way[0];
	return perimeter;
}

float Diamond::Area()
{
	float perimeter;

	for (int i = 0; i < 3; i++)
	{
		if (way[i]!=a)
		{
			e = way[i];
		}
	}
		
	f = sqrt((pow(a, 2) - (1 / 4)*pow(e, 2)) * 4);

	perimeter=(e*f)/2;

	return perimeter;
}

Diamond::~Diamond()
{
	delete[] pointers;
}
