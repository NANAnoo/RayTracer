#include "pch.h"
#include "Rectangle.h"


Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Vec3 ld, Vec3 w, Vec3 h, Material *m,Texture *tex)
{
	LD = ld;
	LT = ld + h;
	RD = ld + w;
	RT = ld + w + h;
	normal = w.Cross(h).normalize();
	W = w;
	H = h;
	M = m;
	Tex = tex;
}

bool Rectangle::BoundingBox(AABB & BOX)
{
	Vec3 min(
		Min(LD.x(), LT.x(), RD.x(), RT.x()),
		Min(LD.y(), LT.y(), RD.y(), RT.y()),
		Min(LD.z(), LT.z(), RD.z(), RT.z())
	);
	Vec3 max(
		Max(LD.x(), LT.x(), RD.x(), RT.x()),
		Max(LD.y(), LT.y(), RD.y(), RT.y()),
		Max(LD.z(), LT.z(), RD.z(), RT.z())
	);
	BOX = AABB(min, max);
	return true;
}

bool Rectangle::hit(Ray r, float t_min, float t_max, HitRecord & rec)
{
	float bias = (r.origin() - LD)*normal;
	if (bias == 0) {
		bias = (r.origin() - RT)*normal;
	}
	float K = r.direction()*normal;
	if (K*bias < 0) {
		float t = -bias / K;
		if (t > t_min&&t < t_max) {
			Vec3 pos = r.posAt(t);
			Vec3 LP = pos - LD;
			Vec3 RP = pos - RT;
			if (LP*W > 0 && LP*H > 0 && RP*W < 0 && RP*H < 0) {
				rec.t = t;
				rec.pos = r.posAt(t);
				rec.normal = normal;
				rec.M = M;
				float u, v;
				u = LP * (W.normalize()) / sqrt(W*W);
				v = LP * (H.normalize()) / sqrt(H*H);
				rec.color = Tex->getPixel(u,v,Vec3(0,0,0));
				return true;
			}
		}

	}
	return false;
}

float Rectangle::Min(float a, float b, float c, float d)
{
	float min = a;
	if (min > b) min = b;
	if (min > c) min = c;
	if (min > d) min = d;
	return min;
}

float Rectangle::Max(float a, float b, float c, float d)
{
	float max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	return max;
}
