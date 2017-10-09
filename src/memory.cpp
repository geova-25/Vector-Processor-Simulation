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

void Memory::run(unsigned char* dinMemNew,unsigned char* Alu_ResultNew, int dir,
	 													int AluResultScalar, short RgNew, bool selDataNew,
															bool selRegTypeNew, bool selWriteMemNew, int contador)
{
	if(this->selWriteMem && contador >= 3)
		for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; i++)
		{
			Alu_result[i] = Alu_ResultNew[i];
			Do[i] = memory[dir + i];
			DinMem[i] = dinMemNew[i];
		}
	this->RgOutMemory = RgNew;
	AluResultScalar = AluResultScalar;
	Addr = dir;
	this->selData = selDataNew;
	this->selRegType = selRegTypeNew;
	this->selWriteMem = selWriteMemNew;
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
	printf("selData: %d\n",this->selData);
	printf("selRegType: %d\n",this->selRegType);
	printf("selWriteMem: %d\n",this->selWriteMem);
	this->printMemory(this->Addr);

}

void Memory::insertValueInMem(int dir,unsigned char* data)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; ++i)
	{
		memory[dir + i] = data[i];
	}
}

void Memory::printMemory(int dir)
{
	//unsigned char* newMemVector =  (unsigned char*)malloc(sizeof(unsigned char)*8);
	printf("Valor de memoria en la posicion:%d ",dir);
	for (int i = 0; i < 8; i++) {
	 	printf("%c",memory[dir + i]);
	}
	printf("\n");
}
