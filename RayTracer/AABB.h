#pragma once
#include "Ray.h"
//AABBÅö×²ºÐ
class AABB
{
public:
	AABB();
	AABB(Vec3 mi, Vec3 ma);
	bool Hit(Ray r, float tmin, float tmax);
	Vec3 min;
	Vec3 max;
};

