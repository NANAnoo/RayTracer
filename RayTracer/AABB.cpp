#include "pch.h"
#include "AABB.h"


AABB::AABB()
{
}

AABB::AABB(Vec3 mi, Vec3 ma)
{
	max = ma;
	min = mi;
}

bool AABB::Hit(Ray r, float tmin, float tmax)
{
	for (int i = 0; i < 3; i++) {
		float t0 = std::fmin(
			(min.Array[i] - r.origin().Array[i]) / r.direction().Array[i],
			(max.Array[i] - r.origin().Array[i]) / r.direction().Array[i]);
		float t1 = std::fmax(
			(min.Array[i] - r.origin().Array[i]) / r.direction().Array[i],
			(max.Array[i] - r.origin().Array[i]) / r.direction().Array[i]);
		tmin = std::fmax(t0, tmin);
		tmax = std::fmin(t1, tmax);
		if (tmax < tmin) {
			return false;
		}
	}
	return true;
}
