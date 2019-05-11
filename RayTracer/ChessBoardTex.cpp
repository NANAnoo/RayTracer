#include "pch.h"
#include "ChessBoardTex.h"


ChessBoardTex::ChessBoardTex()
{
	a = Vec3(0, 0, 0);
	b = Vec3(1, 1, 1);
}

ChessBoardTex::ChessBoardTex(Vec3 A, Vec3 B)
{
	a = A;
	b = B;
}

Vec3 ChessBoardTex::getPixel(float u, float v, Vec3 p)
{
	int X = (int)(u / 0.1);
	int Y = (int)(v / 0.1);
	X = X + Y;
	Y = X / 2;
	if (X == Y * 2) {
		return a;
	}
	else
	{
		return b;
	}
}
