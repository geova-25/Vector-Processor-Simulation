#include "memory.h"

Memory::Memory()
{
	//this->memory = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_MEM,sizeof(unsigned char));
	this->Do = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_M, sizeof(unsigned char));
	this->Alu_result = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_M,sizeof(unsigned char)) ;
	this->DinMem = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_M,sizeof(unsigned char)) ;
}

unsigned char* Memory::getValueFromMem(int dir)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; ++i)
	{
		Do[i] = memory[dir + i];
	}
	return Do;
}

void Memory::run(unsigned char* dinMemNew,unsigned char* Alu_ResultNew, int dir)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; i++)
	{
		Alu_result[i] = Alu_ResultNew[i];
		Do[i] = memory[dir + i];
		DinMem[i] = dinMemNew[i];
	}
	Addr = dir;
}

void Memory::printData()
{
	printf("Do: %s\n", this->Do);
	printf("Alu_resultMem: %s\n", this->Alu_result);
	printf("DinMem: %s\n", this->DinMem);
	printf("Dir: %d\n",this->Addr);
}

void Memory::insertValueInMem(int dir,unsigned char* data)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; ++i)
	{
		memory[dir + i] = data[i];
	}
}
