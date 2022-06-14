#include "pch.h"
#include "Image.h"

Image::Image()
{
}

Image::Image(int w, int h, char * buffer)
{
	WIDTH = w;
	HEIGHT = h;
	int size = w * h * 3;
	Buffer = new unsigned char[size];
	for (int i = 0; i < size; i++)
		Buffer[i] = buffer[i];
}

Image::Image(vector<vector<Color> > MAT)
{
	HEIGHT = MAT.size();
	WIDTH = MAT[0].size();
	int size = HEIGHT * WIDTH * 3;
	int index;
	Buffer = new unsigned char[size];
	for (int i =0; i < HEIGHT ; i ++) {
		for (int j = 0; j < WIDTH; j++) {
			index = i * WIDTH + j;
			Buffer[3 * index] = MAT[i][j].B;
			Buffer[3 * index + 1] = MAT[i][j].G;
			Buffer[3 * index + 2] = MAT[i][j].R;
		}
	}
}

void Image::save(const char *filename)
{
	int l = (WIDTH * 3 + 3) / 4*4;
	int bmi[] = { l*HEIGHT + 54,0,54,40,WIDTH,HEIGHT,1 | 3 * 8 << 16,0,l*HEIGHT,0,0,100,0 };
	FILE *fp = fopen(filename, "wb");
	fprintf(fp, "BM");
	fwrite(&bmi, 52, 1, fp);
	fwrite(Buffer, 1, l*HEIGHT, fp);
	fclose(fp);
}


Image::~Image()
{
	delete[]Buffer;
}
