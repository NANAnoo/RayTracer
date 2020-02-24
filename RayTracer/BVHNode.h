#pragma once
#include "Hitable.h"
//BVH½Úµã
class BVHNode :
	public Hitable
{
public:
	Hitable *left;
	Hitable *right;
	AABB Box;
	BVHNode();
	BVHNode(vector<Hitable*> objs);
	bool hit(Ray r, float t_min, float t_max, HitRecord &rec);
	bool BoundingBox(AABB &BOX);
private:
	void sort(vector<Hitable*> &objs);
	bool compare(Hitable *a, Hitable *b);
	AABB GetBox(AABB l, AABB r);
};

