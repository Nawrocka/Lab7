#pragma once
#include"Figure.h"

class Quadrangle : public Figure
{
	float e, f, angle;;
public:
	Quadrangle(string Name, string Color);
	Quadrangle();

	void virtual Introduce();
	float Perimeter() override;
	float Area() override;

	void LengthsOfSides(Point *pointers, float* way);
	float Factor(Point *pointers,int i);
	float diagonal(Point * pointers, int i);
	bool IsItQuadrangle(Point* pointers);

	virtual ~Quadrangle();
};

