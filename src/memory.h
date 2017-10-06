#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define SIZE_OF_DATA_IN_BYTES

class Memory
{
	public:
		Memory();
		unsigned char* getValueFromMem(int dir);
		void insertValueInMem(int dir, char data);
	private:
		unsigned char* Do;
		char memory[4000000];
};