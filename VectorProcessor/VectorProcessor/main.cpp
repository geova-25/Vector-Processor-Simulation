#include "mainwindow.h"
#include <QApplication>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
//#include "vectorProcessor.h"
#include "parser.h"
#include "imageManager.h"
#include <stdlib.h>
#include <string>
#include <bitset>
#include <iostream>
#include <QTextStream>
using namespace std;

VectorProcessor processor;

void* runProcessor(void* stringParameters)
{
    //----------------------------------------------------Declarations
    ImageManager imgManager;
    //VectorProcessor processor;
    string nameOfFile, nameOfImg, nameOfResultingImage;



    string* dataInputByUser = (string*)stringParameters;
    nameOfImg = "./Raw_Images/";
    nameOfFile = "./Codes/";
    nameOfImg.append(dataInputByUser[1]);
    nameOfFile.append(dataInputByUser[0]);
    nameOfResultingImage = "./Result_Images/";
    nameOfResultingImage.append(dataInputByUser[2]);


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
    return NULL;
}

void* test(void*)
{
    QTextStream out(stdout);
    while(1)
    {

        cout  << processor.fetch.Do << "\n";
        //sleep(1000);
    }
}


int main(int argc, char *argv[])
{
    printf("-------------------Welcome to the vector processor simulator-------------------------\n");
    string args[3];
    string nameOfCode, nameOfImage,nameOfImageResult;
    std::cout << "Ingrese el nombre del codigo a ejecutar: " << '\n';
    std::cin >> nameOfCode;
    args[0] = nameOfCode;
    std::cout << "Ingrese el nombre de la imagen a procesar: " << '\n';
    std::cin >> nameOfImage;
    args[1] = nameOfImage;
    std::cout << "Ingrese el nombre de la imagen resultante: " << '\n';
    std::cin >> nameOfImageResult;
    args[2] = nameOfImageResult;
    QApplication a(argc,argv);
    MainWindow w;
    pthread_t threadProcessor;
    w.setProcessor(&processor);
    pthread_create(&threadProcessor,NULL,runProcessor,(void*)args);
    w.show();
    a.exec();
    exit(0);
    pthread_exit(NULL);
    return 0;
}

