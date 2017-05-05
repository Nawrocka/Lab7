 #include "stdafx.h"
#include <iostream>
#include "Quadrangle.h"
#include <math.h>

using namespace std;

Quadrangle::Quadrangle(string Name, string Color) :Figure(Name, Color)
{
	float a1, a2;
	float tan_angle;

	do
	{
		Complement();

		a1 = Factor(pointers, 0);
		a2 = Factor(pointers, 2);

		tan_angle = abs((a1 - a2) / (1 + a1*a2));
		angle = atan(tan_angle);

		e = diagonal(pointers, 0);
		f = diagonal(pointers, 1);

	} while ((angle > 90) && (IsItQuadrangle(pointers)));
}

Quadrangle::Quadrangle():Figure()
{
}

void Quadrangle::Introduce()
{
	cout << "I'm a Quadrangle " << name << endl;
	cout << "My color is beautifull:  " << color << endl;
}

float Quadrangle::Perimeter()
{
	float way[4];
	float sum = 0;
	LengthsOfSides(pointers, way);

	for (int i = 0; i < 4; i++)
	{
		sum = sum + way[i];
	}

	return sum;
}

float Quadrangle::Area()
{
	float area = 0;
	
	area = (e*f) / 2 * sin(angle);

	return area;
	
}

bool Quadrangle :: IsItQuadrangle(Point* pointers)
{
	float y = pointers[2].GetY();
	int check = 0;
	
	for (int i = 2; i < 4; i++) 
	{
		if ((y == (pointers[1].GetX() - pointers[0].GetY())*(pointers[i].GetX() - pointers[0].GetX()) / (pointers[1].GetX() - pointers[0].GetX()) + pointers[0].GetY()) && (pointers[1].GetX() != pointers[0].GetX()))
		{
			check++;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if ((y == (pointers[3].GetY() - pointers[2].GetY())*(pointers[i].GetX() - pointers[2].GetX()) / (pointers[3].GetX() - pointers[2].GetX()) + pointers[2].GetY()) && (pointers[3].GetX() != pointers[2].GetX()))
		{
			check++;
		}
	}

	if (check == 4) return true;
	else return false;
}

float Quadrangle::diagonal(Point * pointers, int i)
{
	float e = 0;
	if (i == 0)
	{
		e = sqrt(pow(pointers[0].GetX() - pointers[3].GetX(), 2) + pow(pointers[0].GetY() - pointers[3].GetY(), 2));
		return e;
	}
	else if (i == 1)
	{
		e = sqrt(pow(pointers[i].GetX() - pointers[0].GetX(), 2) + pow(pointers[i].GetY() - pointers[0].GetY(), 2));
		return e;
	}
	else return e;
}


float Quadrangle::Factor(Point *pointers, int i)
{
	float a = 0;

	if (i == 0 || i == 2)
	{
		a = (pointers[i + 1].GetY() - pointers[i].GetY()) / (pointers[i + 1].GetX() - pointers[i].GetX());
		return a;
	}
	else return 0;
}


void Quadrangle:: LengthsOfSides(Point *pointers, float* way)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 3) way[i] = sqrt(pow(pointers[i].GetX() - pointers[0].GetX(), 2) + pow(pointers[i].GetY() - pointers[0].GetY(), 2));
		way[i] = sqrt(pow(pointers[i].GetX() - pointers[i + 1].GetX(), 2) + pow(pointers[i].GetY() - pointers[i + 1].GetY(), 2));
	}
}

Quadrangle::~Quadrangle()
{
}
