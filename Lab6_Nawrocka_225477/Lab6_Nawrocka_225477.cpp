// Lab6_Nawrocka_225477.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Figure.h"
#include "Point.h"
#include "Square.h"
#include "Diamond.h"
#include "Quadrangle.h"
#include "Rectangle.h"

using namespace std;

bool IsItQuadrangle(Point* pointers)
{
	float y = pointers[2]._y;
	int check = 0;
	
	for (int i = 2; i < 4; i++)
	{
		if ((y == (pointers[1]._y - pointers[0]._y)*(pointers[i]._x - pointers[0]._x) / (pointers[1]._x - pointers[0]._x) + pointers[0]._y) && (pointers[1]._x != pointers[0]._x))
		{
			check++;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if ((y == (pointers[3]._y - pointers[2]._y)*(pointers[i]._x - pointers[2]._x) / (pointers[3]._x - pointers[2]._x) + pointers[2]._y) && (pointers[3]._x != pointers[2]._x))
		{
			check++;
		}
	}

	if (check == 4) return true;
	else return false;
}

float diagonal(Point * pointers, int i)
{
	float e = 0;
	if (i == 0)
	{
		e = sqrt(pow(pointers[0]._x - pointers[3]._x, 2) + pow(pointers[0]._y - pointers[3]._y, 2));
		return e;
	}
	else if (i==1)
	{
		e = sqrt(pow(pointers[i]._x - pointers[0]._x, 2) + pow(pointers[i]._y - pointers[0]._y, 2));
		return e;
	}
	else return e;
}

float Factor(Point *pointers,int i)
{
	float a = 0;
	
	if (i == 0 || i == 2)
	{
		a = (pointers[i + 1]._y - pointers[i]._y) / (pointers[i + 1]._x - pointers[i]._x);
		return a;
	}
	else return 0;
}

void LengthsOfSides(Point *pointers,float* way)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 3) way[i] = sqrt(pow(pointers[i]._x - pointers[0]._x, 2) + pow(pointers[i]._y - pointers[0]._y, 2));
		way[i] = sqrt(pow(pointers[i]._x - pointers[i + 1]._x, 2) + pow(pointers[i]._y - pointers[i + 1]._y, 2));
	}
}

float IsItDiamond(Point *pointers)
{
	float way[4];
	int check = 0;
	for (int i = 0; i < 4; i++)
	{
		if(i==3) way[i] = sqrt(pow(pointers[i]._x - pointers[0]._x, 2) + pow(pointers[i]._y - pointers[0]._y, 2));
		way[i] = sqrt(pow(pointers[i]._x - pointers[i+1]._x, 2) + pow(pointers[i]._y - pointers[i+1]._y, 2));
	}

	for (int j = 1; j < 4; j++)
	{
		if (way[0] == way[j]) check++;
	}

	if (check == 3) return way[0];
	return 0;
}

float distance(Point * pointers,int i)
{
	float way = 0;
	Point a = pointers[0];
	way=sqrt(pow(a._x - pointers[i]._x, 2) + pow(a._y - pointers[i]._y, 2));
	return way;
}

istream& operator>>(istream& o, Point& xy)
{
	cout << "Give 2 coordinates x & y: " << endl;
	o >> xy._x >> xy._y;
	return o; 
}

void ShowFIgure(Figure* figure);

int main()
{
	string name, color;
	cout << "Made 4 figures: square, rectangle, diamond and quadrangle." << endl;
	string Types[] = { "Square","Rectangle","Diamond","Quadrangle" };
	Figure tab[4];
	Figure* wskS=nullptr; 

	for (int i = 0; i < 4; i++)
	{
		cout << "Give a name of " << Types[i] << " : " << endl;
		cin >> name;
		cout << "Give a color " << Types[i] << " : " << endl;
		cin >> color;

		switch (i)
		{
		case 0:
		{
			Square kwadrat(name, color);
			wskS = &kwadrat;
			ShowFIgure(wskS);
			break;
		}
		case 1:
		{
			Rectangle prostok¹t(name, color);
			*wskS = prostok¹t;
			ShowFIgure(wskS);
			break;
		}
		case 2:
		{
			Diamond romb(name, color);
			*wskS = romb;
			ShowFIgure(wskS);
			break;
		}
		case 3:
		{
			Quadrangle czworokat(name, color);
			*wskS = czworokat;
			ShowFIgure(wskS);
			break;
		}
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void ShowFIgure(Figure* figure)
{
	figure->Introduce();
	cout << "Area = "<<figure->Area()<<endl;
	cout << "Perimeter = " << figure->Perimeter() << endl;
}


