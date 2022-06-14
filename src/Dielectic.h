#pragma once
#include "Material.h"
class Dielectic :
	public Material
{
public:
	float ref_idx;//����/���� ������Ϊ1.0f
	Dielectic();
	Dielectic(float idx);
	bool scatter(Ray r, HitRecord rec, Ray &back);
	Vec3 emmitted() { return Vec3(0, 0, 0); };
private:
	bool refract(Vec3 in,Vec3 n,float nt,Vec3 &ref);
	Vec3 reflect(Ray r, HitRecord rec);
	//��ȡ����ϵ��
	float schlick(float consine, float ref_idx);
};

