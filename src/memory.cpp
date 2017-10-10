#include "memory.h"

Memory::Memory()
{
	//this->memory = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_MEM,sizeof(unsigned char));
	this->Do = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_M, sizeof(unsigned char));
	this->Alu_result = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_M,sizeof(unsigned char)) ;
	this->DinMem = (unsigned char*)calloc(SIZE_OF_DATA_IN_BYTES_M,sizeof(unsigned char)) ;
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_MEM; i++)
	{
		memory[i] = 0;
	}
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
	 													int AluResultScalarNew, short RgNew, int selDataNew,
															bool selRegTypeNew, bool selWriteMemNew, int contador)
{
	this->RgOutMemory = RgNew;
	this->AluResultScalar = AluResultScalarNew;
	Addr = dir;
	this->selData = selDataNew;
	this->selRegType = selRegTypeNew;
	this->selWriteMem = selWriteMemNew;
	if(this->selWriteMem && contador >= 2)
	{
		printf("-------\n\n\nSaving new value in mem:%s \n\n\n\n",dinMemNew);
	  this->insertValueInMem(dir,dinMemNew);
	}
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; i++)
	{
		Alu_result[i] = Alu_ResultNew[i];
		Do[i] = memory[dir + i];
		DinMem[i] = dinMemNew[i];
	}
	Do = getValueFromMem(dir);
	printf("------------------------------------------------------------------------------------Do: %s\n", Do);

}

void Memory::printData(bool kind)
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
	printf("Addr %d\n",this->Addr);
	if(kind == false) 	this->printMemory(QUANTITY_OF_PRINTS_MEMORY);
	else 	this->printMemoryDecimalValues(QUANTITY_OF_PRINTS_MEMORY);

}

void Memory::insertValueInMem(int dir,unsigned char* data)
{
	for (int i = 0; i < SIZE_OF_DATA_IN_BYTES_M; ++i)
	{
		memory[dir + i] = data[i];
	}
}

void Memory::printMemory(int t)
{
	//unsigned char* newMemVector =  (unsigned char*)malloc(sizeof(unsigned char)*8);
	//printf("Valor de memoria en la posicion:%d ",dir);
	printf("-----------------------------------Data Memory------------------------------------ \n");
	int contador = 0;
	for (int i = 0; i < t; i++)
	{
		if(i == 0) printf("[000]:······· ");
		//printf("i:%d , imod8:%d \n",i,i%8);
		if(i%8 == 0 && i != 0)
		{
				contador++;
				if(memory[i] == 0)
				{
					if (contador == 7) {printf("\n"); contador = 0;}
					printf("[%03d]:·······",i);
				}
				else
				{
					if (contador == 7) {printf("\n"); contador = 0;}
					//if (strlen(memory[i]) );
					printf("[%03d]:%-7s",i,&memory[i]);
				}
				printf(" ");
		}
		else if(contador == 7)
		{
			printf("\n");
			contador = 0;
		}
		else
		{

		}
	}
	printf("\n");

}

void Memory::printMemoryDecimalValues(int t)
{
	//unsigned char* newMemVector =  (unsigned char*)malloc(sizeof(unsigned char)*8);
	//printf("Valor de memoria en la posicion:%d ",dir);
	printf("-----------------------------------Data Memory------------------------------------ \n");
	int contador = 0;
	for (int i = 0; i < t; i++)
	{
		//if(i == 0) {printf("%s %s","[000]:","······························· ");}

		//printf("i:%d , imod8:%d \n",i,i%8);
		if(i%8 == 0)
		{
				if (contador == 3)
				{
					printf("\n");
					contador = 0;
				}
				if(memory[i] == 0) printf("[%03d]: %3s",i," · ");
				else printf("[%03d]: %-3d",i,memory[i]);
				printf(" ");
				contador++;
		}
		else
		{
			if(memory[i] == 0) printf("%-3s "," · ");
			else printf("%-3d ",memory[i]);
		}

	}

}
