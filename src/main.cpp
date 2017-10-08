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


void unitTest_DecoderRegisters()
{

  Decoder decoder;
  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba1 = (unsigned char*)"DrStein";
  vectorPrueba2 = (unsigned char*)"Halloween";
  /*
  vectorPrueba1[0] = 'h';
  vectorPrueba1[1] = 'o';
  vectorPrueba1[2] = 'l';
  vectorPrueba1[3] = 'a';
  vectorPrueba1[4] = 'M';
  vectorPrueba1[5] = 'u';
  vectorPrueba1[6] = 'n';
  vectorPrueba1[7] = 'd';
  */

  decoder.setVectorRegister(7,vectorPrueba1); 
  decoder.printVectorRegisters();

  vectorPrueba2 = decoder.getVectorRegisterB(7);
  decoder.printVectorRegisters();
  printf("vectorPrueba2: %s\n",vectorPrueba2);

  vectorPrueba2[3] = '7' ;
  decoder.printVectorRegisters();
  printf("vectorPrueba2: %s\n",vectorPrueba2);
}


void unitTest_FetchDecoderRegisters()
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

void unitTest_DecoderExecuteRegister()
{
  Decoder_Execute_Register der;
  unsigned char* DoVA;
  unsigned char* DoVB;
  DoVA = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
  DoVB = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
  DoVA = (unsigned char*)"Jojojo";
  DoVB = (unsigned char*)"Jajaja";
  unsigned char DoSA = 'j';
  unsigned char DoSB = 'h';
  
  for (int i = 0; i < 3; ++i)
  {
    if(i == 1)
    {
      DoVA = (unsigned char*)"ewewew";
      DoVB = (unsigned char*)"saaap";
    }
    if(i == 2)
    {
      DoVA = (unsigned char*)"luke";
      DoVB = (unsigned char*)"puquis";
    }
    printf("---------------------NuevoCiclo----------------\n");
    der.run(DoVA,DoVB,DoSA,DoSB);

    cout << "-----------Datos de salida---------------- \n";
    cout << "DoVA: " << der.DoVA << '\n';
    cout << "DoVB: " << der.DoVB << '\n';
    cout << "DoSA: " << der.DoSA << '\n';
    cout << "DoSB: " << der.DoSB << '\n';
    der.changeOutPutRegisters();
  }
}

void unitTest_fetch_reg_deco()
{
  Fetch fetch;
  Decoder decoder;
  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba1 = (unsigned char*)"DrStein";
  vectorPrueba2 = (unsigned char*)"Hallowee";
  vectorPrueba3 = (unsigned char*)"IWantOut";
  vectorPrueba4 = (unsigned char*)"KeeperSe";
  decoder.setVectorRegister(0,vectorPrueba1); 
  decoder.setVectorRegister(1,vectorPrueba2); 
  decoder.setVectorRegister(2,vectorPrueba3); 
  decoder.setVectorRegister(3,vectorPrueba4); 
  

  int contador = 0;
  string* instructionMemory = new string[INST_MEM_SIZE];
  instructionMemory = fetch.getInstructionMemory();
  //SumV Rv0 Rv1 Rv2
  instructionMemory[0] = "00000000000101000000000000000000";
  //SumV Rv0 Rv1 Rv2
  instructionMemory[1] = "00010000000101000000000000000000";
  Fetch_Decoder_Register fetch_decoder_register;
  
  while(contador <= 60)
  {
    decoder.printVectorRegisters();

    printf("________________________________\n");
    printf("________________________________\n");
    printf("________________________________\n");
    printf("________________________________\n");
    fetch.run();
    fetch_decoder_register.saveRegister(fetch.Do);
    decoder.run(fetch_decoder_register.OpDo, fetch_decoder_register.FDo, fetch_decoder_register.RvgDo, fetch_decoder_register.RvsDo, fetch_decoder_register.RvpDo, fetch_decoder_register.ImmNumDo);
    usleep(1000000);
    
    contador = contador + 1;


    printf("------Datos de salida registro fetch-deco------\n");
    printf("-----------------------------------------------\n");

    cout << "OpDo: " << fetch_decoder_register.OpDo << "\n";
    cout << "FDo: " << fetch_decoder_register.FDo << "\n";
    cout << "RvgDo: " << fetch_decoder_register.RvgDo << "\n";
    cout << "RvsDo: " << fetch_decoder_register.RvsDo << "\n";
    cout << "RvpDo: " << fetch_decoder_register.RvpDo << "\n";
    cout << "ImmNumDo: " << fetch_decoder_register.ImmNumDo << "\n";

    printf("--------------Datos de salida deco------------\n");
    printf("-----------------------------------------------\n");

    cout << "DoVA: " << decoder.DoVA << "\n";
    cout << "DoVB: " << decoder.DoVB << "\n";
    cout << "DoSA: " << decoder.DoSA << "\n";
    cout << "DoSB: " << decoder.DoSB << "\n";

    fetch_decoder_register.changeOutPutRegisters();
  }
}

void unitTest_fetch_reg_deco_reg()
{

  Fetch fetch;
  Fetch_Decoder_Register fetch_decoder_register;
  Decoder decoder;
  Decoder_Execute_Register decoder_execute_register;  


  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba1 = (unsigned char*)"DrStein";
  vectorPrueba2 = (unsigned char*)"Hallowee";
  vectorPrueba3 = (unsigned char*)"IWantOut";
  vectorPrueba4 = (unsigned char*)"KeeperSe";
  decoder.setVectorRegister(0,vectorPrueba1); 
  decoder.setVectorRegister(1,vectorPrueba2); 
  decoder.setVectorRegister(2,vectorPrueba3); 
  decoder.setVectorRegister(3,vectorPrueba4);
  decoder.setScalarRegister(0,'o'); 
  decoder.setScalarRegister(1,'l');
  decoder.setScalarRegister(2,'a'); 
  

  int contador = 0;
  string* instructionMemory = new string[INST_MEM_SIZE];
  instructionMemory = fetch.getInstructionMemory();
  //SumV Rv0 Rv1 Rv2
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[0] = "00000000000101000000000000000000";
  //SumV Rv0 Rv3 Rv4
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[1] = "00000000001111000000000000000000";
  //SumV Rv0 Rv1 Rv2
  instructionMemory[2] = "00010000000101000000000000000000";
  //SumV Rv1 Rv1 Rv5
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[3] = "00010000100110100000000000000000";

  
  while(contador <= 60)
  {

    printf("\n");
    printf("+++++++++++++++++++++++++New Iteration+++++++++++++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n");
    //printf("--------------------------------------------------------------\n");
    //printf("--------------------------------------------------------------\n");

    //Part of the algorithm

    fetch.run();
    fetch_decoder_register.saveRegister(fetch.Do);
    decoder.run(fetch_decoder_register.OpDo, fetch_decoder_register.FDo, fetch_decoder_register.RvgDo, fetch_decoder_register.RvsDo, fetch_decoder_register.RvpDo, fetch_decoder_register.ImmNumDo);
    decoder_execute_register.run(decoder.DoVA,decoder.DoVB,decoder.DoSA,decoder.DoSB);
    usleep(1000000);
    

    //-----------------Prints--------------
    decoder.printVectorRegisters();
    decoder.printScalarRegisters();
    fetch_decoder_register.printDin();
    fetch_decoder_register.printDout();
    decoder.printDout();
    decoder_execute_register.printDin();
    decoder_execute_register.printDout();
    //-----------------Change Registers
    fetch_decoder_register.changeOutPutRegisters();
    decoder_execute_register.changeOutPutRegisters();
    //-----------------Others
    contador = contador + 1;
  }

}

int main(){
  //printString(returnString());
  //unitTest_FetchDecoderRegisters();
  //unitTest_VectorProcessor();
  //unitTest_ScalarRegisters();
  //unitTest_DecoderRegisters();
  //unitTest_fetch_reg_deco();
  unitTest_fetch_reg_deco_reg();
  //unitTest_DecoderExecuteRegister();
  //unitTest_image();
  //unitTest_fetch();
  //unitTest_Execute();
  
  /*
  string str[100]; 
  str[0] = "asdfasdf";
  str[1] = "asdfasdf";
  str[2] = "asdfasdf";
  cout << str[0][2] << "\n";
  cout << str[1][5] << "\n";
  cout << str[2] << "\n";
  */

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