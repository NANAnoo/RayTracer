#include "pch.h"
#include "Ray.h"


Ray::Ray()
{
}

Ray::Ray(Vec3 o, Vec3 d)
{
	Origin = o;
	Direction = d;
}

Vec3 Ray::origin()
{
	return Origin;
}

Vec3 Ray::direction()
{
	return Direction;
}

Vec3 Ray::posAt(float T)
{
	return Origin + Direction * T;
}
