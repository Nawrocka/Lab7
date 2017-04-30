#pragma once
#include"Figure.h"
class Rectangle :public Figure
{
public:
	Rectangle(string Name, string Color);
	Rectangle();

	void virtual Introduce();
	float Perimeter() override;
	float Area() override;

	virtual ~Rectangle();
};

