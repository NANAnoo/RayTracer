#pragma once
#include "pch.h"
#include "BVHNode.h"

enum SKYTYPE {
	NONE=0,
	BLUE_SKY = 1,
	SKY_BOX = 2
};

class World
{
public:
	Hitable *Root;
	vector<Hitable*> List;
	unsigned char *top;
	unsigned char *buttom;
	unsigned char *front;
	unsigned char *back;
	unsigned char *left;
	unsigned char *right;
	int width;
	int channel;
	World();
	World(vector<Hitable*> list,bool useBvh);
	void setSkyBox(unsigned char *t, unsigned char *bu, unsigned char *f, unsigned char *b, unsigned char *l, unsigned char *r,int width,int n);
	bool hit(Ray r, float t_min, float t_max, HitRecord &rec);
	Vec3 color(Ray r,int &depth);
	void set_sky(SKYTYPE T);
private:
	Vec3 Sky(Ray r);
	bool useBVH;
	SKYTYPE type;
};

