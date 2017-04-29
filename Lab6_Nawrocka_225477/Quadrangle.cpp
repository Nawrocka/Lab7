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

	} while ((angle > 90) && (IsItQuadrangle));
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

Quadrangle::~Quadrangle()
{
	delete[] pointers;
}
