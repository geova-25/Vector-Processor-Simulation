#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define SIZE_OF_DATA_IN_BYTES_MEM 4000000
#define SIZE_OF_DATA_IN_BYTES_M 8

class Memory
{
	public:
		Memory();
		void run(unsigned char* dinMemNew,unsigned char* Alu_ResultNew, int dir);
		unsigned char* getValueFromMem(int dir);
		void printData();
		unsigned char* Alu_result;
		unsigned char* Do;
		unsigned char memory[SIZE_OF_DATA_IN_BYTES_MEM];
		void insertValueInMem(int dir, unsigned char* data);
	private:
		int Addr;
		unsigned char* DinMem;

};
