#include "imageManager.h"

ImageManager::ImageManager()
{

}

int  ImageManager::getImgSize()
{
  return imageSize;
}

void ImageManager::readImage(char* name)
{
  imageSize = 512 * 512;
  this->readImageBuffer = (unsigned char*)calloc(imageSize,sizeof(unsigned char));
  FILE *fp;
   if ((fp = fopen(name, "rb")) == NULL)
      printf("Bad name of file");
  else fread(this->readImageBuffer,imageSize,1,fp);
}

void ImageManager::writeImage(unsigned char* writeImageBuffer, char* name)
{
  FILE *fp2;
  fp2 = fopen(name, "w"); //If not exist then creates it
  fwrite(writeImageBuffer,1,imageSize,fp2);
}

unsigned char* ImageManager::getImageBuffer()
{
  return this->readImageBuffer;
}
