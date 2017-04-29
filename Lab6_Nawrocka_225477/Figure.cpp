#include "stdafx.h"
#include "Figure.h"
#include <iostream>

using namespace std;

void Figure::quicksort(float * way, int left, int right)
{
	float v = way[(left + right) / 2];
	int i, j;
	float x;
	i = left;
	j = right;
	do {
		while (way[i] < v) i++;
		while (way[j] > v) j--;
		if (i <= j) {
			x = way[i];
			way[i] = way[j];
			way[j] = x;
			i++; j--;
		}
	} while (i <= j);
	if (j > left) quicksort(way, left, j);
	if (i < right) quicksort(way, i,right);
}

Figure::Figure()
{
	name = "";
	color = "";
	pointers= new Point[4];
	//wyzeruj
}

Figure::Figure(string Name, string Color)
{
	name = Name;
	color = Color;	
	pointers = new Point[4];
	Complement();
}

void Figure::Complement()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> pointers[i];
	}

	for (int j = 0; j < 3; j++)
	{
		way[j] = distance(pointers, j + 1);
	}

	quicksort(way, 0, 2);
}

void Figure::Introduce()
{
	cout << "I'm a " << name << endl;
}

float Figure::Perimeter()
{
	return 0.0f;
}

float Figure::Area()
{
	return 0.0f;
}

Figure& Figure::operator=(const Figure& right)
{
	if (this == &right)
	{
		return *this;
	}

	if (pointers != nullptr) //skad ten blad, co o za blad???
	{
		delete[] pointers;
		pointers = nullptr;
	}

	pointers = new Point[4];
	for (int index = 0; index < 4; ++index)
	{
		pointers[index] = right.pointers[index]; //operator przyrownania jest w point.h wiec dobrze?
	}

	return *this;
}

Figure::~Figure()
{
	delete[] pointers;
}
