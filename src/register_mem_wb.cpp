#include "register_mem_wb.h"


Register_Mem_Wb::Register_Mem_Wb()
{
  DoDataMemoryOut = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_RMWB,sizeof(unsigned char));
  AluResultOut    = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_RMWB,sizeof(unsigned char));
  DoDataMemorIn   = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_RMWB,sizeof(unsigned char));
  AluResultIn     = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_RMWB,sizeof(unsigned char));
}

void Register_Mem_Wb::run(unsigned char* DoDataMemNew, unsigned char* AluResultNew,
                        short RgNew, int AluResultScalarNew, int selDataNew
                                    ,bool selRegTypeNew, bool selWriteMemNew)
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_RMWB; i++)
  {
    this->DoDataMemorIn[i] =  DoDataMemNew[i];
    this->AluResultIn[i] = AluResultNew[i];
  }
    this->AluResultScalarIn = AluResultScalarNew;
    this->RgIn = RgNew;
    this->selDataIn = selDataNew;
    this->selRegTypeIn = selRegTypeNew;
    this->selWriteMemIn = selWriteMemNew;
}


void Register_Mem_Wb::changeOutPutRegisters()
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_RMWB; i++) {
    this->DoDataMemoryOut[i] =  this->DoDataMemorIn[i];
    this->AluResultOut[i] = this->AluResultIn[i];
  }
  this->RgOut = this->RgIn;
  this->AluResultScalarOut = this->AluResultScalarIn;
  this->selDataOut = this->selDataIn;
  this->selRegTypeOut = this->selRegTypeIn;
  this->selWriteMemOut = this->selWriteMemIn;
}

void Register_Mem_Wb::printDin()
{
	cout << "-----------Input Data Mem_WB_Register------------------------\n";
  	printf("------------------------------------------------------------\n");
	cout << "DoDataMemorIn: "     << this->DoDataMemorIn     << '\n';
	cout << "AluResultIn: "       << this->AluResultIn       << '\n';
	cout << "RgIn: "              << this->RgIn              << '\n';
  cout << "AluResultScalarIn: " << this->AluResultScalarIn << '\n';
  cout << "selDataIn: "         << this->selDataIn         << '\n';
  cout << "selRegTypeIn: "      << this->selRegTypeIn      << '\n';
  cout << "selWriteMemIn: "     << this->selWriteMemIn     << '\n';
}

void Register_Mem_Wb::printDout()
{
	cout << "-----------Output Data Mem_WB_Register-----------------------\n";
  	printf("------------------------------------------------------------\n");
	cout << "DoDataMemoryOut: "     << this->DoDataMemoryOut     << '\n';
	cout << "AluResultOut: "        << this->AluResultOut        << '\n';
	cout << "RgOut: "               << this->RgOut               << '\n';
  cout << "AluResultScalarOut: "  << this->AluResultScalarOut  << '\n';
  cout << "selDataOut: "          << this->selDataOut          << '\n';
  cout << "selRegTypeOut: "       << this->selRegTypeOut       << '\n';
  cout << "selWriteMemOut: "      << this->selWriteMemOut      << '\n';
}
