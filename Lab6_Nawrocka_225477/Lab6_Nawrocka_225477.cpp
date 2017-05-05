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
	//chcia³am zrobiæ tablice obiektow, ale po co kopiowaæ zawartoœci, pamiêæ zjadaæ, aby tyle obiektów tworzyæ, wiêc na potrzeby tego programu to wystarcza
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
			wskS = &prostok¹t;
			ShowFIgure(wskS);
			break;
		}
		case 2:
		{
			Diamond romb(name, color);
			wskS = &romb;
			ShowFIgure(wskS);
			break;
		}
		case 3:
		{
			Quadrangle czworokat(name, color);
			wskS = &czworokat;
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


