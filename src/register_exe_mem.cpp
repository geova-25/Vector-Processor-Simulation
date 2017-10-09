#include "register_exe_mem.h"


Register_Exe_Mem::Register_Exe_Mem()
{
  this->Doresult = (unsigned char*)calloc(8,sizeof(unsigned char));
  this->DoDinMD = (unsigned char*)calloc(8,sizeof(unsigned char));
  this->Dinresult = (unsigned char*)calloc(8,sizeof(unsigned char));
  this->DinMD = (unsigned char*)calloc(8,sizeof(unsigned char));
}

void Register_Exe_Mem::run(unsigned char* DoresultNew, unsigned char* DoDinMDNew,
        int DoresultScalarNew, int DoAddrANew)
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_EMR; i++) {
    this->Dinresult[i] = DoresultNew[i];
    this->DinMD[i] = DoDinMDNew[i];
  }
  this->DinAddrA = DoAddrANew;
  this->DinresultScalar = DoresultScalarNew;
}

void Register_Exe_Mem::changeOutPutRegisters()
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_EMR; i++) {
    Doresult[i] = Dinresult[i];
    DoDinMD[i] = DinMD[i];
  }
  this->DoAddrA = this->DinAddrA;
  this->DoresultScalar = this->DinresultScalar;
}

void Register_Exe_Mem::printDin()
{
	cout << "-----------Input Data Execute_Mem_Register-------------------\n";
  	printf("------------------------------------------------------------\n");
	cout << "Dinresult: "        << this->Dinresult       << '\n';
	cout << "DinMD: "            << this->DinMD           << '\n';
	cout << "DinAddrA: "         << this->DinAddrA        << '\n';
	cout << "DinresultScalar: "  << this->DinresultScalar << '\n';
}

void Register_Exe_Mem::printDout()
{
	cout << "-----------Output data Execute_Mem_Register------------------\n";
  	printf("------------------------------------------------------------\n");
    cout << "Doresult: "        << this->Doresult           << '\n';
  	cout << "DoDinMD: "         << this->DoDinMD            << '\n';
  	cout << "DoAddrA: "         << this->DoAddrA            << '\n';
  	cout << "DoresultScalar: "  << this->DoresultScalar     << '\n';
}
