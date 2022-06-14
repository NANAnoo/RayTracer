#pragma once
#include "HitRecord.h"
class Metal :
	public Material
{
public:
	float fuzz;
	Metal();
	Metal(float f);
	bool scatter(Ray r, HitRecord rec, Ray &back);
	Vec3 emmitted() { return Vec3(0, 0, 0); };
private:
	Vec3 reflect(Ray r, HitRecord rec,bool &flag);
	Vec3 randomInUnitSphere();
};

