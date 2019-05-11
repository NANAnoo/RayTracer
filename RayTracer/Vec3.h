#pragma once
class Vec3
{
public:
	float Array[3];
	Vec3();
	Vec3(float x, float y, float z);
	Vec3 operator+(Vec3 V);
	Vec3 operator+(float bias);
	Vec3 operator-(Vec3 V);
	Vec3 operator-(float bias);
	Vec3 operator*(float s);
	float operator*(Vec3 V);
	Vec3 Mul(Vec3 V);
	Vec3 Cross(Vec3 V);
	Vec3 normalize();
	float lenth();
	float x();
	float y();
	float z();
	//...
};

