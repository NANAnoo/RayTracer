#pragma once
#include "Hitable.h"
class Lambertian :
	public Material
{
public:
	Lambertian();
	bool scatter(Ray r, HitRecord rec, Ray &back);
	Vec3 emmitted() { return Vec3(0, 0, 0); };
private:
	Vec3 randomInUnitSphere();
};

