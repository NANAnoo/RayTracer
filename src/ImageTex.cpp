#include "pch.h"
#include "ImageTex.h"
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

ImageTex::ImageTex()
{
}

//ImageTex::ImageTex(const char * filename)
//{
//	data = stbi_load(filename, &width, &height, &nrChannels, 0);
//}

ImageTex::ImageTex(unsigned char * d,int w,int h,int n)
{
	data = d;
	width = w;
	height = h;
	nrChannels = n;
}

Vec3 ImageTex::getPixel(float u, float v, Vec3 p)
{
	int i, j;
	i = u * width;
	j = height - v * height;
	if (data) {
		int index = (j * width + i)*nrChannels;
		if (nrChannels > 2) {
			return Vec3((float)data[index] / 255.0, (float)data[index + 1] / 255.0, (float)data[index + 2] / 255.0);
		}
		else {
			return Vec3((float)data[index] / 255.0, (float)data[index] / 255.0, (float)data[index] / 255.0);
		}
	}
	else {
		return Vec3(0, 0, 0);
	}
}
