#include "pch.h"
#include "Metal.h"


Metal::Metal()
{
}

Metal::Metal(float f)
{
	fuzz = f;
}

bool Metal::scatter(Ray r, HitRecord rec, Ray & back)
{
	bool flag;
	Vec3 ref = reflect(r, rec, flag);
	if (flag) {
		back = Ray(rec.pos,ref);
	}
	return flag;
}

Vec3 Metal::reflect(Ray r, HitRecord rec, bool & flag)
{
	Vec3 v = r.direction();
	Vec3 n = rec.normal.normalize();
	Vec3 ref = v - n * (v*n)*2.0f;
	flag = ref * n > 0;
	return ref + randomInUnitSphere()*std::fmin(fuzz,ref.normalize()*n);
}

Vec3 Metal::randomInUnitSphere()
{
	float x = 2.0f*(float)rand() / RAND_MAX - 1.0f;
	float y = 2.0f*(float)rand() / RAND_MAX - 1.0f;
	float z = 2.0f*(float)rand() / RAND_MAX - 1.0f;
	float s = (float)rand() / RAND_MAX;
	return Vec3(x, y, z).normalize()*s;
}
