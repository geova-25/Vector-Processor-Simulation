#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>

#define REGISTER_SIZE_IN_BYTES_RMWB 8

using namespace std;

class Register_Mem_Wb
{
  public:
    Register_Mem_Wb();
    void run(unsigned char* DoDataMemNew, unsigned char* AluResultNew, short RgNew,int AluResulScalarNew);
    void changeOutPutRegisters();
    void printDin();
    void printDout();
    int AluResultScalarOut;
    unsigned char* DoDataMemoryOut;
    unsigned char* AluResultOut;
    short RgOut;
  private:
    int AluResultScalarIn;
    unsigned char* DoDataMemorIn;
    unsigned char* AluResultIn;
    short RgIn;
};
