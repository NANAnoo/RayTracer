#pragma once
#include "Ray.h"
#include "Texture.h"
#include "HitRecord.h"

class HitRecord;
class Material
{
public:
	virtual bool scatter(Ray r, HitRecord rec, Ray &back) = 0;
	virtual Vec3 emmitted() = 0;
};