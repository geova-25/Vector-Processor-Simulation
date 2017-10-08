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
		void run(unsigned char* DVA, unsigned char* DVB, unsigned char DSA,unsigned char DSB);
		unsigned char* DoVA;
		unsigned char* DoVB;
		unsigned char  DoSA;
		unsigned char  DoSB;
	private:
		unsigned char* DiVA;
		unsigned char* DiVB;
		unsigned char  DiSA;
		unsigned char  DiSB;
};