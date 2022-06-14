#include "pch.h"
#include "ConstantTexture.h"


ConstantTexture::ConstantTexture()
{
}

ConstantTexture::ConstantTexture(Vec3 c)
{
	Color = c;
}

Vec3 ConstantTexture::getPixel(float u, float v, Vec3 p)
{
	return Color;
}
