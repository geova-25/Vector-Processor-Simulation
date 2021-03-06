#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>

#define REGISTER_SIZE_IN_BYTES_WB 8
#define VECTOR_REGISTERS_MEM_SIZE_WB 64
#define SCALAR_REGISTERS_MEM_SIZE_WB 8

using namespace std;

class Write_Back
{
  public:
      Write_Back();
      void run(unsigned char* DoDataMemNew,unsigned char* AluResultNew,
                          int AluResultScalarNew,short RgNew, int selDataNew,
                               bool selRegTypeNew,bool selWriteMemNew,int counter);
      void setRegisters(unsigned char* vectorRegistersNew,unsigned int* scalarRegistersNew);
      void setVectorRegister(short din, unsigned char* vector);

      void setScalarRegister(short direction, int data);
      void printData();
  private:
      void printVectorRegisters();
      void printScalarRegisters();
      void printVectorRegistersString();
      short Rg;
      unsigned char* DoDataMem;
      unsigned char* AluResult;
      int AluResultScalar;
      unsigned char* vectorRegisters;
      unsigned int*  scalarRegisters;
      int selData;
      bool selRegType;
      bool selWriteMem;
};
