#pragma once
#include"Figure.h"
class Rectangle :public Figure
{
public:
	Rectangle(string Name, string Color);

	float Perimeter() override;
	float Area() override;

	~Rectangle();
};

