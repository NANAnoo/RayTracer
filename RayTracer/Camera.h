#pragma once
#include "Ray.h"
class Camera
{
public:
	Vec3 lower_left;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 origin;

	Camera();
	Camera(Vec3 LL, Vec3 H, Vec3 V,Vec3 O);
	// lookfrom, lookat,Vup
	Camera(Vec3 Lookfrom, Vec3 Lookat, Vec3 Vup, float vfov,float aspect);
	void LookAt(Vec3 Lookfrom, Vec3 Lookat, Vec3 Vup, float vfov, float aspect);
	Ray GetRay(float u, float v);

};

