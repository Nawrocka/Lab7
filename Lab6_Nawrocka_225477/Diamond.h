#pragma once
#include"Figure.h"

class Diamond :public Figure
{
	float e, f, a;
public:
	Diamond(string Name, string Color);

	float Perimeter() override;
	float Area() override;
	friend float IsItDiamond(Point *pointers);

	~Diamond();
};

