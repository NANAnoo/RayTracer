#pragma once
#include "Vec3.h"
class Texture
{
public:
	virtual Vec3 getPixel(float u,float v, Vec3 p) = 0;
};

