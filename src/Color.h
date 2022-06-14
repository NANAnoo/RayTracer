#pragma once
#include "Vec3.h"
class Color
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;
	Color();
	Color(Vec3 V);
	Color(int r, int g, int b);
	Color(float r, float g, float b);
	Color operator*(float scale);
	void print();
};

