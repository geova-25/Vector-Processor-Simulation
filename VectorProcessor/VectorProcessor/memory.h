#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define DATA_MEM_IMAGE_INIT_POSITION 0
#define SIZE_OF_DATA_IN_BYTES_MEM 4001000
#define SIZE_OF_DATA_IN_BYTES_M 8
#define QUANTITY_OF_PRINTS_MEMORY 1000

class Memory
{
	public:
		Memory();
		void run(unsigned char* dinMemNew,unsigned char* Alu_ResultNew, int dir,
														int AluResultScalarNew,short RgNew, int selDataNew,
																bool selRegTypeNew, bool selWriteMemNew, int contador);
		unsigned char* getValueFromMem(int dir);
		void printData(bool kind);
		unsigned char* Alu_result;
		unsigned char* Do;
		int AluResultScalar;
		unsigned char memory[SIZE_OF_DATA_IN_BYTES_MEM];
		void insertValueInMem(int dir, unsigned char* data);
		short RgOutMemory;
		int selData;
		bool selRegType;
		bool selWriteMem;
	private:
		int Addr;
		unsigned char* DinMem;
		void printMemory(int dir);
		void printMemoryDecimalValues(int t);
};
