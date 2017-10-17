#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class ImageManager
{
	public:
		ImageManager();
		void readImage(char* name);
		void writeImage(unsigned char* writeImageBuffer, char* name);
		unsigned char* getImageBuffer();
		int  getImgSize();
	private:
		unsigned char* readImageBuffer;
		int imageSize;

};
