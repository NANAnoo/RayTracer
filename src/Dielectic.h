#pragma once
#include "Material.h"
class Dielectic :
	public Material
{
public:
	float ref_idx;//光疏/光密 ，空气为1.0f
	Dielectic();
	Dielectic(float idx);
	bool scatter(Ray r, HitRecord rec, Ray &back);
	Vec3 emmitted() { return Vec3(0, 0, 0); };
private:
	bool refract(Vec3 in,Vec3 n,float nt,Vec3 &ref);
	Vec3 reflect(Ray r, HitRecord rec);
	//获取反射系数
	float schlick(float consine, float ref_idx);
};

