#include <stdio.h>
#include <png.h>
#include "vectorProcessor.h"
#include "parser.h"
#include "imageManager.h"
#include <stdlib.h>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;

void unitTest_imgClass_dup_vectorProcessor()
{
  //----------------------------------------------------Declarations
  ImageManager imgManager;
  VectorProcessor processor;
  string nameOfFile, nameOfImg, nameOfResultingImage;

  printf("-------------------Welcome to the vector processor simulator-------------------------\n");

  /*std::cout << "If you want to decript with SUMASIMPLE the name of the image will have no effect it will work with ./Result_Images/resultDesencriptationSumaSimple.data" << '\n';
  std::cout << "Type the name of the image to encript(without the extension .data): " << "\n";
  std::cin >> nameOfImg;
  nameOfImg = "./Raw_Images/" + nameOfImg + ".data";*/

  nameOfImg = "./Raw_Images/lena.data";
  int typeOfAlgoritm;

  cout << "Type the type of algoritm you want to apply to the Image:" << '\n';
  std::cout << "1:XOR" << '\n';
  std::cout << "2:Shift left" << '\n';
  std::cout << "3:Shift rigth" << '\n';
  std::cout << "4:Shift circular left" << '\n';
  std::cout << "5:Shift circular right" << '\n';
  std::cout << "6:Suma Simple" << '\n';
  std::cout << "7:Desencriptacion Suma Simple" << '\n';
  std::cin >> typeOfAlgoritm;

  //---------------------------------------------------Parser Code


  switch (typeOfAlgoritm)
  {
    case 1:
      nameOfFile = "./Codes/XOR35.txt";
      nameOfResultingImage = "./Result_Images/resultXOR.data";
      break;
    case 2:
      nameOfFile = "./Codes/SHFLF1.txt";
      nameOfResultingImage = "./Result_Images/resultShiftLeft.data";
      break;
    case 3:
      nameOfFile = "./Codes/SHFRG1.txt";
      nameOfResultingImage = "./Result_Images/resultShiftRight.data";
      break;
    case 4:
      nameOfFile = "./Codes/SHFCLF5.txt";
      nameOfResultingImage = "./Result_Images/resultShiftLeftCircular.data";
      break;
    case 5:
      nameOfFile = "./Codes/SHFCRG5.txt";
      nameOfResultingImage = "./Result_Images/resultShiftRightCircular.data";
      break;
    case 6:
      nameOfFile = "./Codes/SUMASIMPLE.txt";
      nameOfResultingImage = "./Result_Images/resultSumaSimple.data";
      break;
    case 7:
      nameOfFile = "./Codes/SUMASIMPLEDESENCRIPTACION.txt";
      nameOfResultingImage = "./Result_Images/resultDesencriptationSumaSimple.data";
      nameOfImg = "./Result_Images/resultSumaSimple.data";
      break;
    default:
      nameOfFile = "./Codes/XOR35.txt";
      break;
  }

  Parser* parser  = new Parser(nameOfFile);
  parser->parse();
  //----------------------------------------------------Get image

  imgManager.readImage((char *)nameOfImg.c_str());

  //----------------------------------------------------Set data memory

  processor.setInstructionMemory(parser->instructions);
  processor.setDataMemory(imgManager.getImageBuffer(),imgManager.getImgSize());

  //-----------------------------------------------------Run the proccessor

  processor.run(parser->totalInstructionsNumber);
  //----------------------------------------------------Save resulting image

  unsigned char* writeImageBuffer = (unsigned char*)calloc(imgManager.getImgSize(),sizeof(unsigned char));

  for (int i = DATA_MEM_IMAGE_INIT_POSITION; i < DATA_MEM_IMAGE_INIT_POSITION + imgManager.getImgSize(); i++) {
    writeImageBuffer[i] = processor.getDataMemory()[i];
  }

  imgManager.writeImage(writeImageBuffer,(char*)nameOfResultingImage.c_str());

}

int main()
{
  unitTest_imgClass_dup_vectorProcessor();
}
