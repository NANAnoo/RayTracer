// RayTracer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Color.h"
#include "Image.h"
#include "Ray.h"
#include "World.h"
#include "Sphere.h"
#include "Rectangle.h"
#include "Curve.h"
#include "Camera.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Light.h"
#include "Dielectic.h"
#include "ConstantTexture.h"
#include "ChessBoardTex.h"
#include "ImageTex.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
//
//float hitSphere(Vec3 center, float radius, Ray r) {
//	Vec3 oc = r.origin()-center;
//	float a = r.direction()*r.direction();
//	float b = 2.0f * (oc *r.direction());
//	float c = oc * oc - radius * radius;
//	float discriminant = b * b - 4 * a*c;
//	if (discriminant < 0) {
//		return -1.0f;
//	}
//	else {
//		return (-b - sqrt(discriminant)) / (2.0f * a);
//	}
//}
//
//
//Color color(Ray ray) {
//	Vec3 center(0, 0, -1);
//	float t = hitSphere(center, 0.5f, ray);
//	if (t > 0.0f) {
//		Vec3 N = (ray.posAt(t) - center).normalize();
//		Color c((N + 1.0f)*0.5f);
//		return c;
//	}
//	Vec3 dir = ray.direction().normalize();
//	t = 0.5f*(dir.y() + 1.0f);
//	return Color(Vec3(1, 1, 1)*(1.0 - t) + Vec3(0.5, 0.7, 1.0)*t);
//}
//
vector<Hitable*> box() {
	vector<Hitable*> objs;
	unsigned char*data;
	int width, height, nrChannels;
	data = stbi_load("D:\\RT_result\\redstone_lamp.png", &width, &height, &nrChannels, 0);
	objs.push_back(
		//Light_white
		new Rectangle(Vec3(-0.5, 1, -1.5), Vec3(1, 0, 0), Vec3(0, 0, -1),
			new Light(1),
			new ImageTex(data,width,height,nrChannels
			)));
	objs.push_back(
		//Light_white
		new Rectangle(Vec3(-0.5, 1, -1.5), Vec3(1, 0, 0), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		//Light_white
		new Rectangle(Vec3(0.5, 1, -2.5), Vec3(-1, 0, 0), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		//Light_white
		new Rectangle(Vec3(0.5, 1, -2.5), Vec3(0, 0, 1), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		//Light_white
		new Rectangle(Vec3(0.5, 1, -1.5), Vec3(0, 0, -1), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		//buttom__white_lam
		new Rectangle(Vec3(-2, -2, 0), Vec3(4, 0, 0), Vec3(0, 0, -4),
			new Lambertian(),
			new ConstantTexture(Vec3(1, 1, 1)
			)));
	objs.push_back(
		//top__white_lam
		new Rectangle(Vec3(-2, 2, 0), Vec3(0, 0, -4), Vec3(4, 0, 0),
			new Lambertian(),
			new ConstantTexture(Vec3(1, 1, 1)
			)));
	objs.push_back(
		//left__green_lam
		new Rectangle(Vec3(-2, -2, 0), Vec3(0, 0, -4), Vec3(0, 4, 0),
			new Lambertian(),
			new ConstantTexture(Vec3(0, 1, 0)
			)));
	objs.push_back(
		//right__red_lam
		new Rectangle(Vec3(2, -2, 0), Vec3(0, 4, 0), Vec3(0, 0, -4),
			new Lambertian(),
			new ConstantTexture(Vec3(1, 0, 0)
			)));
	objs.push_back(
		//back__white_lam
		new Rectangle(Vec3(-2, -2, -4), Vec3(4, 0, 0), Vec3(0, 4, 0),
			new Lambertian(),
			new ConstantTexture(Vec3(1, 1, 1)
			)));
	objs.push_back(
		new Curve(Vec3(0, 0.5, -2), Vec3(0, -sqrt(1.25), 0), 2.0/sqrt(5.0), new Dielectic(1.7), new ConstantTexture(Vec3(1, 1, 1)))
	);
	objs.push_back(
		new Curve(Vec3(0, -1.5, -2), Vec3(0, sqrt(1.25), 0), 2.0/sqrt(5.0), new Dielectic(1.7), new ConstantTexture(Vec3(1, 1, 1)))
	);
	return objs;
}

vector<Hitable*> init() {
	vector<Hitable*> objs;
	unsigned char*data;
	int width, height, nrChannels;
	data = stbi_load("D:\\RT_result\\redstone_lamp.png", &width, &height, &nrChannels, 0);
	{
	objs.push_back(
		new Rectangle(Vec3(0.5, 0, -0.5), Vec3(0, 0, -1), Vec3(1, 0, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		new Rectangle(Vec3(0.5, -1, -0.5), Vec3(1, 0, 0), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		new Rectangle(Vec3(1.5, -1, -1.5), Vec3(-1, 0, 0), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		new Rectangle(Vec3(0.5, -1, -1.5), Vec3(0, 0, 1), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	objs.push_back(
		new Rectangle(Vec3(1.5, -1, -0.5), Vec3(0, 0, -1), Vec3(0, 1, 0),
			new Light(1),
			new ImageTex(data, width, height, nrChannels
			)));
	}
	{
		objs.push_back(
			new Rectangle(Vec3(0.5, 0, -3), Vec3(0, 0, -1), Vec3(1, 0, 0),
				new Light(1),
				new ImageTex(data, width, height, nrChannels
				)));
		objs.push_back(
			new Rectangle(Vec3(0.5, -1, -3), Vec3(1, 0, 0), Vec3(0, 1, 0),
				new Light(1),
				new ImageTex(data, width, height, nrChannels
				)));
		objs.push_back(
			new Rectangle(Vec3(1.5, -1, -4), Vec3(-1, 0, 0), Vec3(0, 1, 0),
				new Light(1),
				new ImageTex(data, width, height, nrChannels
				)));
		objs.push_back(
			new Rectangle(Vec3(0.5, -1, -4), Vec3(0, 0, 1), Vec3(0, 1, 0),
				new Light(1),
				new ImageTex(data, width, height, nrChannels
				)));
		objs.push_back(
			new Rectangle(Vec3(1.5, -1, -3), Vec3(0, 0, -1), Vec3(0, 1, 0),
				new Light(1),
				new ImageTex(data, width, height, nrChannels
				)));
	}
	objs.push_back(
		new Sphere(Vec3(3, 0, -3),
			1,
			new Lambertian(),
			new ConstantTexture(Vec3(0.9, 0.6, 0.9))
		)
	);
	objs.push_back(
		new Sphere(Vec3(1, -0.5, -2.25),
			0.5,
			new Dielectic(1.3),
			new ConstantTexture(Vec3(1,1,1))
		)
	);
	objs.push_back(
		new Rectangle(
			Vec3(-2, -1, 2), Vec3(8, 0, 0), Vec3(0, 0, -8),
			new Metal(1),
			new ChessBoardTex(Vec3(0.1, 0.1, 0.1), Vec3(0.9, 0.9, 0.9))
		)
	);
	return objs;
}
int main()
{
	int WIDTH = 800;
	int HEIGHT = 800;
	float sq2 = sqrt(2.0);
	float lmda = 1.3;
	vector<vector<Color>> Mat;
	vector<Color> Line;
	vector<Hitable*> objs;
	World world(box());

	//int width, height, nrChannels;
	//unsigned char* top = stbi_load("D:\\RT_result\\textures\\Sky\\bluesky\\bluesky_top.jpg", &width, &height, &nrChannels, 0);
	//unsigned char* back = stbi_load("D:\\RT_result\\textures\\Sky\\bluesky\\bluesky_back.jpg", &width, &height, &nrChannels, 0);
	//unsigned char* front = stbi_load("D:\\RT_result\\textures\\Sky\\bluesky\\bluesky_front.jpg", &width, &height, &nrChannels, 0);
	//unsigned char* left = stbi_load("D:\\RT_result\\textures\\Sky\\bluesky\\bluesky_left.jpg", &width, &height, &nrChannels, 0);
	//unsigned char* right = stbi_load("D:\\RT_result\\textures\\Sky\\bluesky\\bluesky_right.jpg", &width, &height, &nrChannels, 0);
	//world.setSkyBox(top, top, front, back, left, right, width, nrChannels);

	Camera cam(Vec3(0,0,8),Vec3(0, 0, 0),Vec3(0,1,0),30.0, (float)WIDTH / (float)HEIGHT);
	int snns = 100;
	int depth = 10;
	for (int i = 0; i < HEIGHT; i++) {
		Line.clear();
		for (int j = 0; j < WIDTH; j++) {
			Vec3 col(0, 0, 0);
			for (int k = 0; k < snns; k++) {
				float v = ((float)i + (float)rand() / RAND_MAX) / HEIGHT;
				float u = ((float)j + (float)rand() / RAND_MAX) / WIDTH;
				col = col + world.color(cam.GetRay(u, v), depth);
				depth = 10;
			}                                                                           
			col = col * (1.0 / (float)snns);
			Line.push_back(col);
		}
		Mat.push_back(Line);
	}
	Image img(Mat);
	img.save("D:\\RT_result\\test25.bmp");

}



































