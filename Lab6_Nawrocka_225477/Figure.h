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
	void Introduce();
	float virtual Perimeter();
	float virtual Area();
	friend float distance(Point *pointers,int i);
	void quicksort(float* way, int left, int right);

	friend istream& operator>>(istream& o, Point& xy);

	~Figure();
};

