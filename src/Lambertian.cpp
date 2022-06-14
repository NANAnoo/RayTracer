#include "pch.h"
#include "Lambertian.h"


Lambertian::Lambertian()
{
}

bool Lambertian::scatter(Ray r, HitRecord rec, Ray & back)
{
	Vec3 target = rec.normal + randomInUnitSphere();
	back = Ray(rec.pos, target);
	return true;
}

Vec3 Lambertian::randomInUnitSphere()
{
	float x = 2.0f*(float)rand() / RAND_MAX - 1.0f;
	float y = 2.0f*(float)rand() / RAND_MAX - 1.0f;
	float z = 2.0f*(float)rand() / RAND_MAX - 1.0f;
	float s = (float)rand() / RAND_MAX;
	return Vec3(x, y, z).normalize()*s;
}