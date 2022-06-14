#include "pch.h"
#include "Curve.h"


Curve::Curve()
{
}

Curve::Curve(Vec3 c, Vec3 r, float scale, Material * m, Texture * tex)
{
	center = c;
	Radius = r;
	Scale = scale;
	M = m;
	Tex = tex;
}

bool Curve::hit(Ray r, float t_min, float t_max, HitRecord & rec)
{
	float radius = Radius.lenth();
	Vec3 oc = r.origin() - center;
	float a = r.direction()*r.direction();
	float b = 2.0f * (oc *r.direction());
	float c = oc * oc - radius * radius;
	float discriminant = b * b - 4 * a*c;
	if (discriminant > 0) {
		float delta = sqrt(discriminant);
		float temp = (-b - delta) / (2.0f*a);
		if (temp<t_max && temp > t_min) {
			Vec3 pos = r.posAt(temp);
			Vec3 p_c = pos - center;
			float cosine = p_c * Radius / (radius * p_c.lenth());
			if (cosine > Scale) {
				rec.t = temp;
				rec.pos = pos;
				rec.normal = (rec.pos - center) * (1.0f / radius);
				rec.M = M;
				rec.color = Tex->getPixel(0, 0, rec.pos);
				return true;
			}
		}
	}
	return false;
}

bool Curve::BoundingBox(AABB & BOX)
{
	float radius = Radius.lenth();
	BOX = AABB(center - Vec3(radius, radius, radius), center + Vec3(radius, radius, radius));
	return true;
}
