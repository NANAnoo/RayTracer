#include "pch.h"
#include "Color.h"

Color::Color()
{
	R = 0;
	G = 0;
	B = 0;
}

Color::Color(Vec3 V)
{
	int r = (int)(V.x()*255.59);
	int g = (int)(V.y()*255.59);
	int b = (int)(V.z()*255.59);
	if (r < 0) {
		this->R = 0;
	}
	else if (r > 255) {
		this->R = 255;
	}
	else {
		this->R = r;
	}
	if (g < 0) {
		this->G = 0;
	}
	else if (g > 255) {
		this->G = 255;
	}
	else {
		this->G = g;
	}
	if (b < 0) {
		this->B = 0;
	}
	else if (b > 255) {
		this->B = 255;
	}
	else {
		this->B = b;
	}
}

Color::Color(int r, int g, int b)
{
	if (r < 0) {
		this->R = 0;
	}
	else if (r > 255) {
		this->R = 255;
	} else {
		this->R = r;
	}
	if (g < 0) {
		this->G = 0;
	}
	else if (g > 255) {
		this->G = 255;
	}
	else {
		this->G = g;
	}
	if (b < 0) {
		this->B = 0;
	}
	else if (b > 255) {
		this->B = 255;
	}
	else {
		this->B = b;
	}
}

Color::Color(float r, float g, float b)
{
	r = (int)(r*255.59);
	g = (int)(g*255.59);
	b = (int)(b*255.59);
	if (r < 0) {
		this->R = 0;
	}
	else if (r > 255) {
		this->R = 255;
	}
	else {
		this->R = r;
	}
	if (g < 0) {
		this->G = 0;
	}
	else if (g > 255) {
		this->G = 255;
	}
	else {
		this->G = g;
	}
	if (b < 0) {
		this->B = 0;
	}
	else if (b > 255) {
		this->B = 255;
	}
	else {
		this->B = b;
	}
}

Color Color::operator*(float scale)
{
	int r = scale * this->R;
	int g = scale * this->G;
	int b = scale * this->B;
	return Color(r, g, b);
}

void Color::print()
{
	cout << (int)R << " " << (int)G << " " << (int)B << " "<<endl;
}

