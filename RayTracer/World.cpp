#include "pch.h"
#include "World.h"
//#define FLT_MAX          3.402823466e+38F 

World::World()
{
}

World::World(vector<Hitable*> list,bool useBvh)
{
	unsigned char init[3] = { 0,0,0 };
	setSkyBox(init, init,init, init, init, init, 1, 3);
	type = NONE;
	if (useBvh) {
		Root = new BVHNode(list);
		useBVH = true;
	}
	else{
		List = list;
		useBVH = false;
	}
}

void World::setSkyBox(unsigned char * t, unsigned char *bu, unsigned char * f, unsigned char * b, unsigned char * l, unsigned char * r, int Width, int n)
{
	top = t;
	buttom = bu;
	front = f;
	back = b;
	left = l;
	right = r;
	width = Width;
	channel = n;
}


bool World::hit(Ray r, float t_min, float t_max, HitRecord & rec)
{
	if (useBVH) {
		return Root->hit(r, t_min, t_max, rec);
	}
	HitRecord tempRec;
	bool hitAnything = false;
	float closestSoFar = t_max;
	for (int i = 0; i < List.size(); i++) {
		if (List[i]->hit(r, t_min, closestSoFar, tempRec)) {
			hitAnything = true;
			closestSoFar = tempRec.t;
			rec.color = tempRec.color;
			rec.t = tempRec.t;
			rec.pos = tempRec.pos;
			rec.normal = tempRec.normal;
			rec.M = tempRec.M;
		}
	}
	return hitAnything;
}

Vec3 World::color(Ray r, int &depth)
{
	HitRecord rec;
	depth--;
	if (hit(r,0.0f, FLT_MAX,rec)){
		Ray target;
		if (depth > 0 && rec.M->scatter(r, rec, target))
			return color(target, depth).Mul(rec.color)+rec.M->emmitted();
		return rec.M->emmitted();
	}
	else {
		switch (type)
		{
		case NONE:{
			return Vec3(0, 0, 0);
			break;
		}
		case BLUE_SKY:{
			Vec3 dir = r.direction().normalize();
			float t = 0.5f*(dir.y() + 1.0f);
			return Vec3(1, 1, 1)*(1.0 - t) + Vec3(0.5, 0.7, 1.0)*t;
			break;
		}
		case SKY_BOX: {
			return Sky(r);
			break;
		}
		default: {
			return Vec3(0, 0, 0);
			break;
		}
		}
	}
}

void World::set_sky(SKYTYPE T)
{
	type = T;
}

Vec3 World::Sky(Ray r)
{
	Vec3 d = r.direction().normalize();
	int index = 0;
	float max = abs(d.x());
	if (max < abs(d.y())) {
		max = abs(d.y());
		index = 1;
	}
	if (max < abs(d.z())) {
		max = abs(d.z());
		index = 2;
	}
	unsigned char* img = NULL;
	float u, v;
	float temp = 1.0;
	float temp_2 = 2.0;
	switch (index)
	{
	case 0:
		if (d.x() > 0) {
			img = right;
			d = d * (1.0 / d.x());
			u = (d.z() + temp )/ temp_2;
			v = (d.y() + temp )/ temp_2;
		}
		else {
			d = d * ( - 1.0 / d.x());
			u = (temp - d.z())/ temp_2;
			v = (d.y() + temp) / temp_2;
			img = left;
		}
		break;
	case 1:
		if (d.y() > 0) {
			d = d * (1.0 / d.y());
			img = top;
			u = (d.x() + temp) / temp_2;
			v = (d.z() + temp) / temp_2;
		}
		else {
			d = d * ( - 1.0 / d.y());
			img = buttom; 
			u = (d.x() + temp) / temp_2;
			v = (temp - d.z()) / temp_2;
		}
		break;
	case 2:
		if (d.z() > 0) {
			d = d * (1.0 / d.z());
			img = back;
			u = (temp - d.x()) / temp_2;
			v = (d.y() + temp) / temp_2;
		}
		else {
			d = d * ( - 1.0 / d.z());
			img = front;
			u = (d.x() + temp) / temp_2;
			v = (d.y() + temp) / temp_2;
		}
		break;
	}
	if (img == NULL) {
		return Vec3(0, 0, 0);
	}
	int i = u * width;
	int j = width - v * width;
	index = (j * width + i)*channel;
	if (channel > 2) {
		return Vec3((float)img[index] / 255.0, (float)img[index + 1] / 255.0, (float)img[index + 2] / 255.0);
	}
	else {
		return Vec3((float)img[index] / 255.0, (float)img[index] / 255.0, (float)img[index] / 255.0);
	}
}
