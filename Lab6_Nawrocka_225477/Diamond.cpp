#include "stdafx.h"
#include <iostream>
#include "Diamond.h"
using namespace std;

Diamond::Diamond(string name, string color) :Figure(name, color)
{
	bool check = true;
	
	while (check)
	{
		a = IsItDiamond(pointers);

		if ((a==0) || (way[2] == way[0] * sqrt(2)))
		{
			cout << "It's not a square!" << endl << "Pick one more time: " << endl;
			Complement();
		}
		else check = false;
	}
}

Diamond::Diamond():Figure()
{
}

void Diamond::Introduce()
{
	cout << "I'm a Diamond " << name << endl;
	cout << "My color is beautifull:  " << color << endl;
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


float Diamond::IsItDiamond(Point *pointers)
{
	float way[4];
	int check = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i == 3) way[i] = sqrt(pow(pointers[i].GetX() - pointers[0].GetX(), 2) + pow(pointers[i].GetY() - pointers[0].GetY(), 2));
		else way[i] = sqrt(pow(pointers[i].GetX()- pointers[i + 1].GetX(), 2) + pow(pointers[i].GetY() - pointers[i + 1].GetY(), 2));
	}

	for (int j = 1; j < 4; j++)
	{
		if (way[0] == way[j]) check++;
	}

	if (check == 3) return way[0];
	return 0;
}

Diamond::~Diamond()
{
}
