#pragma once
#include "Hitable.h"
class Curve :
	public Hitable
{
public:
	Vec3 center;
	Vec3 Radius;
	Material *M;
	Texture *Tex;
	
	Curve();
	Curve(Vec3 c, Vec3 r,float scale, Material*m, Texture *tex);
	bool hit(Ray r, float t_min, float t_max, HitRecord &rec);
	bool BoundingBox(AABB &BOX);
private:
	float Scale;
};

