#pragma once
#include "Hitable.h"
class Sphere:
public Hitable
{
public:
	Vec3 center;
	float radius;
	Material *M;
	Texture *Tex;

	Sphere();
	Sphere(Vec3 c, float r, Material *m,Texture *tex);
	//Sphere(Vec3 ld,Vec3 w,Vec3 h, Material m);
	bool hit(Ray r, float t_min, float t_max, HitRecord &rec);
	bool BoundingBox(AABB &BOX);
//private:
//	int type;
};

