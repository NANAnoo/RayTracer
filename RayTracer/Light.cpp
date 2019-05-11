#include "pch.h"
#include "Light.h"


Light::Light()
{
	intensity = 0;
}

Light::Light(float i)
{
	intensity = i;
}

bool Light::scatter(Ray r, HitRecord rec, Ray & back)
{
	LC = rec.color*intensity;
	return false;
}

Vec3 Light::emmitted()
{
	return LC;
}
