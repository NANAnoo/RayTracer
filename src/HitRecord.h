#pragma once
#include "Ray.h"
#include "Texture.h"
#include "Material.h"
class Material;
class HitRecord
{
public:
	float t;
	Vec3 color;
	Vec3 pos;
	Vec3 normal;
	Material* M;
	HitRecord() {
		t = 0.0;
		color = Vec3(1, 1, 1);
		pos = Vec3(0.0, 0.0, 0.0);
		normal = Vec3(0.0, 0.0, 0.0);
		M = NULL;
	}
};
