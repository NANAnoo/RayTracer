#include "pch.h"
#include "BVHNode.h"


BVHNode::BVHNode()
{
}

BVHNode::BVHNode(vector<Hitable*> objs)
{
	sort(objs);
	int size = objs.size();	
	switch (size)
	{
	case 1:
		left = objs[0];
		right = NULL;
		break;
	case 2:
		left = objs[0];
		right = objs[1];
		break;
	default:
		left = new BVHNode(vector<Hitable*>(objs.begin(),objs.begin() + size/2));
		right = new BVHNode(vector<Hitable*>(objs.begin() + size / 2, objs.end()));
		break;
	}
	AABB l, r;
	left->BoundingBox(l);
	if (right != NULL)
		right->BoundingBox(r);
	else
		r = l;
	Box = GetBox(l, r);
}

bool BVHNode::hit(Ray r, float t_min, float t_max, HitRecord & rec)
{
	if (Box.Hit(r, t_min, t_max)) {
		HitRecord l_rec,r_rec;
		bool hit_left = left->hit(r, t_min, t_max, l_rec);
		bool hit_right;
		if (right != NULL)
			hit_right = right->hit(r, t_min, t_max, r_rec);
		else
			hit_right = false;
		if (hit_left&&hit_right) {
			rec = l_rec.t < r_rec.t ? l_rec : r_rec;
			return true;
		}
		if (hit_left) {
			rec = l_rec;
			return true;
		}
		if (hit_right) {
			rec = r_rec;
			return true;
		}
		return false;
	}
	return false;
}

bool BVHNode::BoundingBox(AABB & BOX)
{
	BOX = Box;
	return true;
}

void BVHNode::sort(vector<Hitable*> &objs)
{
	Hitable* min;
	int size = objs.size();
	for (int i = 0; i < size - 1; i++) {
		min = objs[i];
		int index = i;
		for (int j = i + 1; j < size; j++) {
			if (compare(min, objs[j])) {
				min = objs[j];
				index = j;
			}
		}
		objs[index] = objs[i];
		objs[i] = min;
	}
}

bool BVHNode::compare(Hitable * a, Hitable * b)
{
	int index = rand() % 3;
	AABB l, r;
	a->BoundingBox(l);
	b->BoundingBox(r);
	return l.min.Array[index] > r.min.Array[index];
}

AABB BVHNode::GetBox(AABB l, AABB r)
{
	Vec3 min(
		std::fmin(l.min.x(), r.min.x()),
		std::fmin(l.min.y(), r.min.y()),
		std::fmin(l.min.z(), r.min.z())
	);
	Vec3 max(
		std::fmax(l.max.x(), r.max.x()),
		std::fmax(l.max.y(), r.max.y()),
		std::fmax(l.max.z(), r.max.z())
	);
	return AABB(min, max);
}


