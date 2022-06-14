#pragma once
#include "Hitable.h"
class Rectangle :
	public Hitable
{
public:
	Vec3 LD;
	Vec3 RT;
	Vec3 LT;
	Vec3 RD;
	Vec3 W;
	Vec3 H;
	Vec3 normal;
	Material *M;
	Texture *Tex;

	Rectangle();
	Rectangle(Vec3 ld, Vec3 w, Vec3 h, Material* m, Texture *tex);
	bool BoundingBox(AABB &BOX);
	bool hit(Ray r, float t_min, float t_max, HitRecord &rec);
private:
	float Min(float a, float b, float c, float d);
	float Max(float a, float b, float c, float d);
};

