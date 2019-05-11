#pragma once
#include "Material.h"
class Light :
	public Material
{
public:
	Light();
	Light(float i);
	bool scatter(Ray r, HitRecord rec, Ray &back);
	Vec3 emmitted();
private:
	Vec3 LC;
	float intensity;
};

