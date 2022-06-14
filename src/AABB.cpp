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
		float t0 = fmin(
			(min.Array[i] - r.origin().Array[i]) / r.direction().Array[i],
			(max.Array[i] - r.origin().Array[i]) / r.direction().Array[i]);
		float t1 = fmax(
			(min.Array[i] - r.origin().Array[i]) / r.direction().Array[i],
			(max.Array[i] - r.origin().Array[i]) / r.direction().Array[i]);
		tmin = fmax(t0, tmin);
		tmax = fmin(t1, tmax);
		if (tmax < tmin) {
			return false;
		}
	}
	return true;
}
