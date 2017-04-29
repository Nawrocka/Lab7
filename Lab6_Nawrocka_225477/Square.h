#pragma once
#include"Figure.h"

class Square:public Figure
{
public:
	Square(string Name, string Color);
	Square();

	float Perimeter() override;
	float Area() override;

	~Square();
};

