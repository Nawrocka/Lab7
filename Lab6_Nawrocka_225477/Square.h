#pragma once
#include"Figure.h"

class Square:public Figure
{
public:
	Square(string Name, string Color);
	Square();

	void virtual Introduce();
	float Perimeter() override;
	float Area() override;

	virtual ~Square();
};

