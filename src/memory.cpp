#include "memory.h"

Memory::Memory()
{
	unsigned char* Do = calloc(SIZE_OF_DATA_IN_BYTES, sizeof(unsigned char));
}
unsigned char* getValueFromMem(int dir)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES; ++i)
	{
		Do[i] = memory[dir + i]; 
	}
}

void insertValueInMem(int dir,unsigned char* data)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES; ++i)
	{
		memory[dir + i] = data[i]; 
	}
}