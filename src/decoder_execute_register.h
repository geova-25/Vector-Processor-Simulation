#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>

#define REGISTER_SIZE_IN_BYTES_DER 64

using namespace std;

class Decoder_Execute_Register
{
	public:
		Decoder_Execute_Register();
		void changeOutPutRegisters();
		void printDin();
		void printDout();
		void run(unsigned char* DVA, unsigned char* DVB, int DSA,int DSB, short Op, int ImmIn);
		unsigned char* DoVA;
		unsigned char* DoVB;
		int  DoSA;
		int  DoSB;
		int ImmOut;
		short OpDout;
	private:
		short OpDin;
		unsigned char* DiVA;
		unsigned char* DiVB;
		int  DiSA;
		int  DiSB;
		int ImmIn;
};