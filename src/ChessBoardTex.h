#pragma once
#include "Texture.h"
//Œ∆¿Ì/∆Â≈ÃŒ∆¿Ì
class ChessBoardTex :
	public Texture
{
public:
	Vec3 a;
	Vec3 b;
	ChessBoardTex();
	ChessBoardTex(Vec3 A, Vec3 B);
	Vec3 getPixel(float u, float v, Vec3 p);
};

