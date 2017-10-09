#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define SIZE_OF_DATA_IN_BYTES_MEM 4000000
#define SIZE_OF_DATA_IN_BYTES_M 8

class Memory
{
	public:
		Memory();
		void run(unsigned char* dinMemNew,unsigned char* Alu_ResultNew, int dir,
														int AluResultScalar,short RgNew, bool selDataNew,
																bool selRegTypeNew, bool selWriteMemNew, int contador);
		unsigned char* getValueFromMem(int dir);
		void printData();
		unsigned char* Alu_result;
		unsigned char* Do;
		int AluResultScalar;
		unsigned char memory[SIZE_OF_DATA_IN_BYTES_MEM];
		void insertValueInMem(int dir, unsigned char* data);
		short RgOutMemory;
		bool selData;
		bool selRegType;
		bool selWriteMem;
	private:
		int Addr;
		unsigned char* DinMem;
		void printMemory(int dir);
};
