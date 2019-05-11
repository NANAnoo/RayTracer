#pragma once
#include "Texture.h"
class ConstantTexture :
	public Texture
{
public:
	Vec3 Color;
	ConstantTexture();
	ConstantTexture(Vec3 c);
	Vec3 getPixel(float u, float v, Vec3 p);
};

