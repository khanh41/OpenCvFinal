#pragma once
#include<iostream>
#include <iomanip>
#include"Image.h"
using namespace std;
#define CHANNEL_RGB_COLOR 3
#define CHANNEL_R_COLOR 0
class Change
{
public:
	int rows, cols;
	int*** a;
	int*** b;
public:
	Change();
	Change(Image);
	Change(const Change&);
	void output();
	void set(Image&);
	void hoanvi(int& a, int& b);
	int trungvi(int* a, int k);
	~Change();
};

