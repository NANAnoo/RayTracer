#include "pch.h"
#include "Sphere.h"


Sphere::Sphere()
{
}

Sphere::Sphere(Vec3 c, float r, Material *m, Texture *tex)
{
	center = c;
	radius = r;
	M = m;
	Tex = tex;
}

//Sphere::Sphere(Vec3 ld, Vec3 w, Vec3 h, Material m)
//{
//	LD = ld;
//	RT = ld + w + h;
//	normal = w.Cross(h).normalize();
//	W = w;
//	H = h;
//	M = m;
//}

bool Sphere::hit(Ray r, float t_min, float t_max, HitRecord &rec)
{
	Vec3 oc = r.origin() - center;
	float a = r.direction()*r.direction();
	float b = 2.0f * (oc *r.direction());
	float c = oc * oc - radius * radius;
	float discriminant = b * b - 4 * a*c;
	if (discriminant > 0) {
		float delta = sqrt(discriminant);
		float temp = (-b - delta) / (2.0f*a);
		if (temp<t_max && temp > t_min) {
			rec.t = temp;
			rec.pos = r.posAt(temp);
			rec.normal = (rec.pos - center) * (1.0f / radius);
			rec.M = M;
			rec.color = Tex->getPixel(0, 0, rec.pos);
			return true;
		}
	}
	//else if (type == 1) {
	//	float bias = (r.origin() - LD)*normal;
	//	if (bias == 0) {
	//		bias = (r.origin() - RT)*normal;
	//	}
	//	float K = r.direction()*normal;
	//	if (K*bias < 0) {
	//		float t = -bias / K;
	//		if (t > t_min&&t < t_max) {
	//			Vec3 pos = r.posAt(t);
	//			Vec3 LP = pos - LD;
	//			Vec3 RP = pos - RT;
	//			if (LP*W > 0 && LP*H > 0 && RP*W < 0 && RP*H < 0) {
	//				rec.t = t;
	//				rec.pos = r.posAt(t);
	//				rec.normal = normal;
	//				return true;
	//			}
	//		}

	//	}
	//}
	
	return false;
}

bool Sphere::BoundingBox(AABB & BOX)
{
	BOX = AABB(center - Vec3(radius, radius, radius), center + Vec3(radius, radius, radius));
	return true;
}
