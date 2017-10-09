#include "register_exe_mem.h"


Register_Exe_Mem::Register_Exe_Mem()
{
  this->Doresult = (unsigned char*)calloc(8,sizeof(unsigned char));
  this->DoDinMD = (unsigned char*)calloc(8,sizeof(unsigned char));
  this->Dinresult = (unsigned char*)calloc(8,sizeof(unsigned char));
  this->DinMD = (unsigned char*)calloc(8,sizeof(unsigned char));
}

void Register_Exe_Mem::run(unsigned char* DoresultNew, unsigned char* DoDinMDNew,
        int DoresultScalarNew, int DoAddrANew, short RgNew, bool selDataNew,
                                    bool selRegTypeNew, bool selWriteMemNew)
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_EMR; i++) {
    this->Dinresult[i] = DoresultNew[i];
    this->DinMD[i] = DoDinMDNew[i];
  }
  this->DinAddrA = DoAddrANew;
  this->DinresultScalar = DoresultScalarNew;
  this->RgIn = RgNew;
  this->selDataIn = selDataNew;
  this->selRegTypeIn = selRegTypeNew;
  this->selWriteMemIn = selWriteMemNew;
}

void Register_Exe_Mem::changeOutPutRegisters()
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_EMR; i++) {
    Doresult[i] = Dinresult[i];
    DoDinMD[i] = DinMD[i];
  }
  this->DoAddrA = this->DinAddrA;
  this->DoresultScalar = this->DinresultScalar;
  this->RgOut = this->RgIn;
  this->selDataOut = this->selDataIn;
  this->selRegTypeOut = this->selRegTypeIn;
  this->selWriteMemOut = this->selWriteMemIn;
}

void Register_Exe_Mem::printDin()
{
	cout << "-----------Input Data Execute_Mem_Register-------------------\n";
  	printf("------------------------------------------------------------\n");
	cout << "Dinresult: "        << this->Dinresult       << '\n';
	cout << "DinMD: "            << this->DinMD           << '\n';
	cout << "DinAddrA: "         << this->DinAddrA        << '\n';
	cout << "DinresultScalar: "  << this->DinresultScalar << '\n';
  cout << "RgIn: "             << this->RgIn            << '\n';
  cout << "selDataIn: "        << this->selDataIn       << '\n';
  cout << "selRegTypeIn: "     << this->selRegTypeIn    << '\n';
  cout << "selWriteMemIn: "    << this->selWriteMemIn    << '\n';
}

void Register_Exe_Mem::printDout()
{
	cout << "-----------Output data Execute_Mem_Register------------------\n";
  	printf("------------------------------------------------------------\n");
    cout << "Doresult: "        << this->Doresult           << '\n';
  	cout << "DoDinMD: "         << this->DoDinMD            << '\n';
  	cout << "DoAddrA: "         << this->DoAddrA            << '\n';
  	cout << "DoresultScalar: "  << this->DoresultScalar     << '\n';
    cout << "RgOut: "           << this->RgOut              << '\n';
    cout << "selDataOut: "      << this->selDataOut         << '\n';
    cout << "selRegTypeOut: "   << this->selRegTypeOut      << '\n';
    cout << "selWriteMemOut: "   << this->selWriteMemOut    << '\n';
}
