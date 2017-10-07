#include <stdio.h>
#include <png.h>
#include "execute.h"
#include "memory.h"
#include "vectorProcessor.h"
#include <stdlib.h>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;


void unitTest_image(){
  Fetch fetch;
  int imageSize = fetch.getMemorySize();
  string* instructionMemory;
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
  string* instructionMemory = new string[INST_MEM_SIZE];
  instructionMemory = fetch.getInstructionMemory();
  //SumV Rv0 Rv1 Rv2
  instructionMemory[0] = "00000000000101000000000000000000";
  //SumV Rv0 Rv1 Rv2
  instructionMemory[1] = "00010000000101000000000000000000";

  printf("Do Instruction Memory: ");
  while(contador <= 60){
    fetch.run();
    cout << fetch.Do << "\n";
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

void unitTest_VectorProcessor()
{
  VectorProcessor vp;
  vp.run();
}

void unitTest_IntegerToBinaryString()
{
  char u = stoi("1010",nullptr,2);
  printf("%d\n", u);
  string s = bitset< 32 >(12).to_string();
  cout << s << '\n';

}

string* returnString()
{
  string* str = new string[10];
  str[0] = "aa";
  str[2] = "ab";
  str[3] = "ac";
  str[4] = "ar";
  return str;
}

void printString(string* aa)
{
  cout << aa[0][0] << "\n";
  cout << aa[2][1] << "\n";
  cout << aa[3][1] << "\n";
}

void unitTest_FetchDecoder()
{
  Fetch fetch;
  int contador = 0;
  string* instructionMemory = new string[INST_MEM_SIZE];
  instructionMemory = fetch.getInstructionMemory();
  //SumV Rv0 Rv1 Rv2
  instructionMemory[0] = "00000000000101000000000000000000";
  //SumV Rv0 Rv1 Rv2
  instructionMemory[1] = "00010000000101000000000000000000";
  Fetch_Decoder_Register fetch_decoder_register;
  
  while(contador <= 60){
    printf("___________________\n");
    fetch.run();
    fetch_decoder_register.saveRegister(fetch.Do);
    usleep(1000000);
    contador = contador + 1;
    printf("------Datos de salida------\n");
    printf("---------------------------\n");
    cout << "OpDo" << fetch_decoder_register.OpDo << "\n";
    cout << "FDo" << fetch_decoder_register.FDo << "\n";
    cout << "RvgDo" << fetch_decoder_register.RvgDo << "\n";
    cout << "RvsDo" << fetch_decoder_register.RvsDo << "\n";
    cout << "RvpDo" << fetch_decoder_register.RvpDo << "\n";
    cout << "ImmNumDo" << fetch_decoder_register.ImmNumDo << "\n";
    fetch_decoder_register.changeOutPutRegisters();
  }
}


int main(){
  //printString(returnString());
  unitTest_FetchDecoder();

  /*
  string str[100]; 
  str[0] = "asdfasdf";
  str[1] = "asdfasdf";
  str[2] = "asdfasdf";
  cout << str[0][2] << "\n";
  cout << str[1][5] << "\n";
  cout << str[2] << "\n";
  */

  //unitTest_VectorProcessor();
  //unitTest_ScalarRegisters();
  //unitTest_DecoderRegisters();
  //unitTest_image();
  //unitTest_fetch();
  //unitTest_Execute();
  
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