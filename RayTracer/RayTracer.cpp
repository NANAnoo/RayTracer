// RayTracer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <opencv.hpp>

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
#include <future>
#include <thread>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define PI 3.1415926

float myRand(float down, float top) {
	return ((float)(rand() % 100) / 100.0)*(top - down) + down;
}

//demo1
vector<Hitable*> box() {
	vector<Hitable*> objs;
	unsigned char*data;
	int width, height, nrChannels;
	data = stbi_load("D:\\RT_result\\redstone_lamp.png", &width, &height, &nrChannels, 0);//加载图片
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

//demo2
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
			1.0,
			new Metal(0),
			new ConstantTexture(Vec3(1, 1, 1))
		)
	);
	objs.push_back(
		new Sphere(Vec3(3, 0, 0),
			0.6,
			new Lambertian(),
			new ConstantTexture(Vec3(0.7, 0.88, 0.9))
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
			new Metal(0.5),
			new ChessBoardTex(Vec3(0.1, 0.1, 0.1), Vec3(0.9, 0.9, 0.9))
		)
	);
	return objs;
}

//demo3
vector<Hitable*> manySphere(int size) {
	vector<Hitable*> objs;
	for (int i = 0; i < size; i++) {
		objs.push_back(
			new Sphere(Vec3(myRand(-2.5,2.5), myRand(-2.5, 2.5), myRand(-2.5, 2.5)),
				myRand(0.05, 0.1),
				new Dielectic(1.3),
				new ConstantTexture(Vec3(myRand(0, 1), myRand(0, 1), myRand(0, 1)))
			)
		);
	}
	for (int i = 0; i < size; i++) {
		objs.push_back(
			new Sphere(Vec3(myRand(-2.5, 2.5), myRand(-2.5, 2.5), myRand(-2.5, 2.5)),
				myRand(0.05, 0.1),
				new Lambertian(),
				new ConstantTexture(Vec3(myRand(0, 1), myRand(0, 1), myRand(0, 1)))
			)
		);
	}
	for (int i = 0; i < size; i++) {
		objs.push_back(
			new Sphere(Vec3(myRand(-2.5, 2.5), myRand(-2.5, 2.5), myRand(-2.5, 2.5)),
				myRand(0.05, 0.1),
				new Metal(1),
				new ConstantTexture(Vec3(myRand(0, 1), myRand(0, 1), myRand(0, 1)))
			)
		);
	}
	for (int i = 0; i < size; i++) {
		objs.push_back(
			new Sphere(Vec3(myRand(-2.5, 2.5), myRand(-2.5, 2.5), myRand(-2.5, 2.5)),
				myRand(0.05, 0.1),
				new Light(1),
				new ConstantTexture(Vec3(myRand(0, 1), myRand(0, 1), myRand(0, 1)))
			)
		);
	}
	return objs;
}

void get_color_line(World world, Camera cam, cv::Mat Mat, int WIDTH, int HEIGHT, int snns, int depth, int s,int c) {
	for (int i = s; i < HEIGHT; i += c) {
		for (int j = 0; j < WIDTH; j++) {
			Vec3 col(0, 0, 0);
			for (int k = 0; k < snns; k++) {
				float v = ((float)i + (float)rand() / RAND_MAX) / HEIGHT;
				float u = ((float)j + (float)rand() / RAND_MAX) / WIDTH;
				col = col + world.color(cam.GetRay(u, v), depth);
				depth = 10;
			}
			col = col * (1.0 / (float)snns);
			Mat.at<uchar>(i, 3 * j) = col.z() * 255;
			Mat.at<uchar>(i, 3 * j + 1) = col.y() * 255;
			Mat.at<uchar>(i, 3 * j + 2) = col.x() * 255;
		}
	}
}

void Get_color(World &world, Camera &cam, cv::Mat &Mat, int WIDTH, int HEIGHT, int snns, int depth, int core) {
	vector<future<void> > Threads(core);
	for (int t = 0; t < core;t++) {
		Threads[t] = async(get_color_line,world,cam,Mat,WIDTH,HEIGHT,snns,depth,t,core);
	}
	for (auto &t : Threads)t.wait();
}

int main()
{
	int max_thread = thread::hardware_concurrency();
	int WIDTH = 600;
	int HEIGHT = 600;
	vector<vector<Color> >mat(HEIGHT,vector<Color>(WIDTH));
	//初始化世界（被观察对象均在此
	World world(init(), false);
	world.set_sky(BLUE_SKY);
	Camera cam;
	int snns = 100;//每个像素计算次数（曝光次数
	int depth = 10;
	cv::Mat frame(WIDTH,HEIGHT,CV_8UC3);
	//get_color(world, cam, mat, snns, depth);
	Vec3 center(2,-1,-2);
	float R = 12,alpha = 0;
	int f_r = 60;
	cv::VideoWriter writer("D:\\RT_result\\test.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'), f_r, cv::Size(WIDTH,HEIGHT), true);
	int f_size = 60 * f_r;
	float h = 4;
	while (f_size--) {
		cam.LookAt(center + Vec3(R*sinf(alpha), h, R*cosf(alpha)), center, Vec3(0, -1, 0), 40.0, (float)WIDTH / (float)HEIGHT);
		alpha += PI / 1800;
		Get_color(world, cam, frame, WIDTH, HEIGHT, snns, depth, max_thread);
		cv::imshow("frame", frame);
		writer.write(frame);
		if (cv::waitKey(10) > 0)break;
	}
	writer.release();
	cv::destroyAllWindows();
	system("pause");
	return 0;
}



































