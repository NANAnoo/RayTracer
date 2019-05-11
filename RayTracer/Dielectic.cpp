#include "pch.h"
#include "Dielectic.h"


Dielectic::Dielectic()
{
	ref_idx = 1.7;
}

Dielectic::Dielectic(float idx)
{
	ref_idx = idx;
}

bool Dielectic::scatter(Ray r, HitRecord rec, Ray & back)
{
	Vec3 outward_normal;
	Vec3 reflected = reflect(r, rec);
	float ni_over_nt;
	float reflect_pro;
	float cosine;
	if (r.direction()*rec.normal > 0) {
		outward_normal = rec.normal * (-1.0f);
		ni_over_nt = ref_idx;
		cosine = r.direction()*rec.normal / (r.direction().lenth()*rec.normal.lenth());
	}
	else
	{
		outward_normal = rec.normal;
		ni_over_nt = 1.0f / ref_idx;
		cosine = 0.0f - r.direction()*rec.normal / (r.direction().lenth()*rec.normal.lenth());
	}
	Vec3 ret;
	if (refract(r.direction(), outward_normal, ni_over_nt, ret)) {
		reflect_pro = schlick(cosine, ref_idx);
	}
	else {
		reflect_pro = 1.0;
	}
	if ((float)rand() / RAND_MAX < reflect_pro) {
		back = Ray(rec.pos, reflected);
	}
	else {
		back = Ray(rec.pos,ret);
	}
	return true;
}

bool Dielectic::refract(Vec3 in, Vec3 n, float nt, Vec3 & ref)
{
	Vec3 nin = in.normalize();
	float cos_a1 = -1.0f*(nin*n);
	float temp = 1.0f - nt * nt*(1.0f - cos_a1 * cos_a1);
	if (temp > 0) {
		ref = nin * nt + n * (nt*cos_a1 - sqrt(temp));
		return true;
	}
	return false;
}

Vec3 Dielectic::reflect(Ray r, HitRecord rec)
{
	Vec3 v = r.direction();
	Vec3 n = rec.normal.normalize();
	Vec3 ref = v - n * (v*n)*2.0f;
	return ref;
}

float Dielectic::schlick(float consine, float ref_idx)
{
	float r0 = (1.0 - ref_idx) / (1.0 + ref_idx);
	r0 = r0 * r0;
	return (r0 + (1 - r0)*pow((1 - consine), 5));
}

