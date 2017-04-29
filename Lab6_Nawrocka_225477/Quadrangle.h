#pragma once
#include"Figure.h"

class Quadrangle : public Figure
{
	float e, f, angle;;
public:
	Quadrangle(string Name, string Color);

	float Perimeter() override;
	float Area() override;

	friend void LengthsOfSides(Point *pointers, float* way);
	friend float Factor(Point *pointers,int i);
	friend float diagonal(Point * pointers, int i);
	friend bool IsItQuadrangle(Point* pointers);

	~Quadrangle();
};

