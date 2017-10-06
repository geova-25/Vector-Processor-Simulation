#include <stdio.h>
#include <png.h>
#include "fetch.h"
#include "decoder.h"
#include "execute.h"
#include "memory.h"
#include <stdlib.h>


void unitTest_image(){
  Fetch fetch;
  int imageSize = fetch.getMemorySize();
  unsigned char* instructionMemory = (unsigned char*)malloc(sizeof(char)*fetch.getMemorySize());
  instructionMemory = fetch.getInstructionMemory();
  FILE *fp;
  FILE *fp2;
   if ((fp = fopen("cat.data", "rb")) == NULL)
      printf("No abierta"); 

  fp2 = fopen("catAux2.data", "w"); //If not exist then creates it
  fread(instructionMemory,imageSize,1,fp);
  fwrite(instructionMemory,1,imageSize,fp2);
}

void unitTest_fetch(){
  Fetch fetch;
  int contador = 0;
  unsigned char* instructionMemory = (unsigned char*)malloc(sizeof(char)*fetch.getMemorySize());
  instructionMemory = fetch.getInstructionMemory();

  for (int i = 0; i < 4; ++i)
  {
    instructionMemory[i] = '0';
  }
  for (int i = 4; i < 6; ++i)
  {
    instructionMemory[i] = '1';
  }
  for (int i = 6; i < 8; ++i)
  {
    instructionMemory[i] = '0';
  }
  for (int i = 8; i < 12; ++i)
  {
    instructionMemory[i] = '1';
  }
  printf("Do Instruction Memory: ");
  while(contador <= 60){
    fetch.run();
    for (int i = 0; i < 32; ++i)
    {
        printf("%c",fetch.Do[i]);
    }
    printf("\n");
    usleep(1000000);
    contador = contador + 1;
  }
}

void unitTest_DecoderRegisters()
{

  Decoder decoder;
  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba1[0] = 'h';
  vectorPrueba1[1] = 'o';
  vectorPrueba1[2] = 'l';
  vectorPrueba1[3] = 'a';
  vectorPrueba1[4] = 'M';
  vectorPrueba1[5] = 'u';
  vectorPrueba1[6] = 'n';
  vectorPrueba1[7] = 'd';

  decoder.setVectorRegister(7,vectorPrueba1); 
  decoder.printVectorRegisters();

  vectorPrueba2 = decoder.getVectorRegisterB(7);;
  decoder.printVectorRegisters();
  printf("vectorPrueba2: %s\n",vectorPrueba2);

  vectorPrueba2[3] = '7' ;
  decoder.printVectorRegisters();
  printf("vectorPrueba2: %s\n",vectorPrueba2);


}


void unitTest_ScalarRegisters(){
  Decoder decoder;
  decoder.setScalarRegister(0,'p');
  decoder.setScalarRegister(1,'a');
  decoder.setScalarRegister(2,'p');
  decoder.setScalarRegister(3,'u');
  decoder.printScalarRegisters();

  char test1 = decoder.getScalarRegister(2);
  printf("test: %c\n",test1);
  test1 = 'g';
  printf("test: %c\n",test1);
  decoder.printScalarRegisters();
}

void unitTest_Execute()
{
  Execute exe;
  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba1[0] = 1;
  vectorPrueba1[1] = 4;
  vectorPrueba1[2] = 5;
  vectorPrueba1[3] = 5;
  vectorPrueba1[4] = 6;
  vectorPrueba1[5] = 7;
  vectorPrueba1[6] = 3;
  vectorPrueba1[7] = 9;

  vectorPrueba2[0] = 9;
  vectorPrueba2[1] = 8;
  vectorPrueba2[2] = 1;
  vectorPrueba2[3] = 2;
  vectorPrueba2[4] = 1;
  vectorPrueba2[5] = 2;
  vectorPrueba2[6] = 3;
  vectorPrueba2[7] = 3;
  exe.sum(vectorPrueba1,vectorPrueba2);
   printf("vectorPrueba1: ");
  for (int i = 0; i < 8; ++i)
  {
   printf("%c",vectorPrueba1[i]);  
  }
  printf("\nvectorPrueba2: ");
  for (int i = 0; i < 8; ++i)
  {
    printf("%c",vectorPrueba2[i]);  
  }
  printf("\n");
  printf("%d\n",exe.result[0]);
  printf("%d\n",exe.result[1]);
  printf("%d\n",exe.result[2]);
  printf("%d\n",exe.result[3]);
  printf("%d\n",exe.result[4]);
  printf("%d\n",exe.result[5]);
  printf("%d\n",exe.result[6]);
  printf("%d\n",exe.result[7]);  
}


int main(){


  //unitTest_ScalarRegisters();
  //unitTest_DecoderRegisters();
  //unitTest_image();
  //unitTest_fetch();
  unitTest_Execute();

  /*

  int* a = (int *)malloc(sizeof(int)*4);
  int* b = (int *)malloc(sizeof(int)*4);
  a[1] = 7;
  b[1] = a[1];
  b[1] = 8;
  printf("a: %d\n",a[1]);
  printf("b: %d\n",b[1]);

  */


  return 0;
}