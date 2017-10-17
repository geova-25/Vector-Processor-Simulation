#include "decoder_execute_register.h"

Decoder_Execute_Register::Decoder_Execute_Register()
{
	DoVA = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_DER, sizeof(unsigned char));
	DoVB = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_DER, sizeof(unsigned char));
}

void Decoder_Execute_Register::run(unsigned char* DVA, unsigned char* DVB, int DSA,int DSB, short Op,int Imm, short RgNew)
{
	DiVA  = DVA;
	DiVB  = DVB;
	DiSA  = DSA;
	DiSB  = DSB;
	OpDin = Op;
	ImmIn = Imm;
	RgIn  = RgNew;
}

void Decoder_Execute_Register::changeOutPutRegisters()
{
	for (int i = 0; i < REGISTER_SIZE_IN_BYTES_DER; ++i)
	{
		DoVA[i] = DiVA[i];
		DoVB[i] = DiVB[i];
	}
		DoSA = DiSA;
		DoSB = DiSB;
		OpDout = OpDin;
		ImmOut = ImmIn;
		RgOut = RgIn;
}

void Decoder_Execute_Register::printDin()
{
	cout << "-----------Input Data Decoder_Execute_Register-------------\n";
  	printf("------------------------------------------------------------\n");
	cout << "DiVA: "  << this->DiVA  << '\n';
	cout << "DiVB: "  << this->DiVB  << '\n';
	cout << "DiSA: "  << this->DiSA  << '\n';
	cout << "DiSB: "  << this->DiSB  << '\n';
	cout << "OpDin: " << this->OpDin << '\n';
	cout << "RgIn: "  << this->RgIn  << '\n';
	cout << "ImmIn: " << this->ImmIn << '\n';
}

void Decoder_Execute_Register::printDout()
{
	cout << "-----------Output data Decoder_Execute_Register------------\n";
  	printf("------------------------------------------------------------\n");
	cout << "DoVA: "   << this->DoVA   << '\n';
	cout << "DoVB: "   << this->DoVB   << '\n';
	cout << "DoSA: "   << this->DoSA   << '\n';
	cout << "DoSB: "   << this->DoSB   << '\n';
	cout << "OpDout: " << this->OpDout << '\n';
	cout << "RgOut: "  << this->RgOut  << '\n';
	cout << "ImmOut: " << this->ImmOut << '\n';
}
