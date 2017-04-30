#pragma once
#include<string>
#include"Point.h"

using namespace std;

class Figure
{
protected:
	string name;
	string color;
	Point* pointers;
	float way[3];

public:
	Figure(string Name, string Color);
	Figure();
	void Complement();
	void virtual Introduce()=0;
	float virtual Perimeter()=0;
	float virtual Area()=0;
	friend float distance(Point *pointers,int i);
	void quicksort(float* way, int left, int right);

	friend istream& operator>>(istream& o, Point& xy);

	virtual ~Figure();
};

