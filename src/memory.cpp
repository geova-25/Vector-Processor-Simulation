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

void Memory::run(unsigned char* dinMemNew,unsigned char* Alu_ResultNew, int dir, int AluResultScalar, short RgNew)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; i++)
	{
		Alu_result[i] = Alu_ResultNew[i];
		Do[i] = memory[dir + i];
		DinMem[i] = dinMemNew[i];
	}
	this->RgOutMemory = RgNew;
	AluResultScalar = AluResultScalar;
	Addr = dir;
}

void Memory::printData()
{
	cout << "-----------Mem Stage data---------------------------------\n";
  printf("------------------------------------------------------------\n");
	printf("Do: %s\n", this->Do);
	printf("Alu_resultMem: %s\n", this->Alu_result);
	printf("AluResultScalarMem: %d\n", this->AluResultScalar);
	printf("DinMem: %s\n", this->DinMem);
	printf("Dir: %d\n",this->Addr);
	printf("RgOutMemory: %d\n",this->RgOutMemory);

}

void Memory::insertValueInMem(int dir,unsigned char* data)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; ++i)
	{
		memory[dir + i] = data[i];
	}
}
