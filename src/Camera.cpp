#include "pch.h"
#include "Camera.h"
#define PI 3.1415926535F

Camera::Camera()
{
	lower_left = Vec3(-2, -1, -1);
	horizontal = Vec3(4, 0, 0);
	vertical = Vec3(0, 2, 0);
	origin = Vec3(0, 0, 0);
}

Camera::Camera(Vec3 LL, Vec3 H, Vec3 V, Vec3 O)
{
	lower_left = LL;
	horizontal = H;
	vertical = V;
	origin = O;
}

Camera::Camera(Vec3 Lookfrom, Vec3 Lookat, Vec3 Vup, float vfov, float aspect)
{
	Vec3 u, v, w;
	float theta = vfov * PI / 180;

	float half_height = tan(theta / 2.0f);
	float half_width = half_height*aspect;
	origin = Lookfrom;
	w = (Lookfrom - Lookat).normalize();
	u = Vup.Cross(w).normalize();
	v = w.Cross(u).normalize();
	lower_left = origin - u * half_width - v * half_height - w;
	horizontal = u * 2.0f*half_width;
	vertical = v * 2.0f*half_height;
}

void Camera::LookAt(Vec3 Lookfrom, Vec3 Lookat, Vec3 Vup, float vfov, float aspect)
{
	Vec3 u, v, w;
	float theta = vfov * PI / 180;

	float half_height = tan(theta / 2.0f);
	float half_width = half_height * aspect;
	origin = Lookfrom;
	w = (Lookfrom - Lookat).normalize();
	u = Vup.Cross(w).normalize();
	v = w.Cross(u).normalize();
	lower_left = origin - u * half_width - v * half_height - w;
	horizontal = u * 2.0f*half_width;
	vertical = v * 2.0f*half_height;
}



Ray Camera::GetRay(float u, float v)
{
	Ray r = Ray(origin, (lower_left + horizontal * u + vertical * v - origin).normalize());
	return r;
}
