#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>

class Register_Exe_Mem{
  public:
    Register_Exe_Mem();
    void run(unsigned char* Doresult, unsigned char* DoDinMD,int DoresultScalar,int DoAddrA);
    unsigned char* Doresult;
    unsigned char* DoDinMD;
		int DoresultScalar;
		int DoAddrA;
  private:
    unsigned char* Dinresult;
		unsigned int DinresultScalar;
		unsigned char* DinMD;
		int DinAddrA;
};
