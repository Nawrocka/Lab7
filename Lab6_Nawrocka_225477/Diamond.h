#pragma once
#include"Figure.h"

class Diamond :public Figure
{
	float e, f, a;
public:
	Diamond(string Name, string Color);
	Diamond();

	void virtual Introduce();
	float Perimeter() override;
	float Area() override;
	friend float IsItDiamond(Point *pointers);

	virtual ~Diamond();
};

