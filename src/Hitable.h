#pragma once
#include "Ray.h"
#include "Texture.h"
#include "HitRecord.h"
#include "AABB.h"
class Hitable
{
public:
	//Hitable();
	virtual bool hit(Ray r, float t_min, float t_max, HitRecord &rec) = 0;
	virtual bool BoundingBox(AABB &BOX) = 0;
};

