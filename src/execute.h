#include <stdlib.h>
#include <stdio.h>
#include "alu.h"

#define SIZE_OF_RESULT_BYTES 8

using namespace std;

class Execute
{
	public:
		unsigned char* result;
		unsigned int resultScalar;
		unsigned char* DinMD;
		int AddrA;
		int Imm;

		Execute();
		void run(short OpCode, unsigned char * DoVA, unsigned char * DoVB, int DoSA, int DoSB, int ImmNew, short RgNew);
		char getAluvalue(short alu);
		unsigned char* sumV(unsigned char* vector1, unsigned char* vector2);
		unsigned char* subV(unsigned char* vector1, unsigned char* vector2);
		unsigned char* sumVS(unsigned char* vector1, unsigned char data2);
		unsigned char* subVS(unsigned char* vector1, unsigned char data2);
		int sumS(int vector1, int vector2);
		int subS(int vector1, int vector2);
		unsigned char* xxor(unsigned char* vector1, unsigned char data2);
		unsigned char* shfl(unsigned char* vector1, unsigned char data2);
		unsigned char* shfr(unsigned char* vector1, unsigned char data2);
		unsigned char* shflc(unsigned char* vector1, unsigned char data2);
		unsigned char* shfrc(unsigned char* vector1, unsigned char data2);
		void printDout();
		short RgOutExe;
	private:
		Alu alu0;
		Alu alu1;
		Alu alu2;
		Alu alu3;
		Alu alu4;
		Alu alu5;
		Alu alu6;
		Alu alu7;
};
