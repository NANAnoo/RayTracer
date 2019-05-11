#pragma once
#include "pch.h"
#include "Color.h"
class Image
{
public:
	Image();
	Image(int w, int h, char *buffer);
	Image(vector<vector<Color>> MAT);
	void save(const char* filename);
	~Image();
private:
	int WIDTH;
	int HEIGHT;
	unsigned char *Buffer;
};

