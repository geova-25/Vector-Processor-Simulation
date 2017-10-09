#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>

#define REGISTER_SIZE_IN_BYTES_EMR 8

using namespace std;

class Register_Exe_Mem{
  public:
    Register_Exe_Mem();
    void run(unsigned char* DoresultNew, unsigned char* DoDinMDNew,
            int DoresultScalarNew, int DoAddrANew, short RgNew,bool selDataNew,
                                        bool selRegTypeNew, bool selWriteMemNew);
    void changeOutPutRegisters();
    void printDin();
    void printDout();
    unsigned char* Doresult;
		unsigned int DoresultScalar;
		unsigned char* DoDinMD;
		int DoAddrA;
    short RgOut;
    bool selDataOut;
    bool selRegTypeOut;
    bool selWriteMemOut;
  private:
    bool selWriteMemIn;
    bool selRegTypeIn;
    bool selDataIn;
    short RgIn;
    unsigned char* Dinresult;
		unsigned int DinresultScalar;
		unsigned char* DinMD;
		int DinAddrA;
};
