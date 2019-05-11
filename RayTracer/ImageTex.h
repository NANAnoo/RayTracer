#pragma once
#include "Texture.h"
class ImageTex :
	public Texture
{
public:
	ImageTex();
	//ImageTex(const char * filename);
	Vec3 getPixel(float u, float v, Vec3 p);
	ImageTex(unsigned char * data,int w,int h,int n);
private:
	int width, height, nrChannels;
	unsigned char *data;
	/* = stbi_load("timg.jpg", &width, &height, &nrChannels, 0)*/
};

