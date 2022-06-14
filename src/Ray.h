#pragma once
#include "Vec3.h"
class Ray
{
public:
	Ray();
	Ray(Vec3 o, Vec3 d);
	Vec3 origin();
	Vec3 direction();
	Vec3 posAt(float T);
private:
	Vec3 Origin;
	Vec3 Direction;

};

