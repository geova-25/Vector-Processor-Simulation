#include "write_back.h"


Write_Back::Write_Back()
{
  this->DoDataMem = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_WB,sizeof(unsigned char));
  this->AluResult = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES_WB,sizeof(unsigned char));
  vectorRegisters = (unsigned char*)calloc(VECTOR_REGISTERS_MEM_SIZE_WB,sizeof(unsigned char));
	scalarRegisters = (unsigned int*)calloc(SCALAR_REGISTERS_MEM_SIZE_WB,sizeof(int));
}

void Write_Back::run(unsigned char* DoDataMemNew,unsigned char* AluResultNew,
                                            int AluResultScalarNew,short RgNew)
{
  for (int i = 0; i < REGISTER_SIZE_IN_BYTES_WB; i++) {
    this->DoDataMem[i] = DoDataMemNew[i];
    this->AluResult[i] =  AluResultNew[i];
  }
  this->AluResultScalar = AluResultScalarNew;
  this->Rg = RgNew;
  this->setVectorRegister(5,(unsigned char*)"VAMOOOOS");
}


void Write_Back::setRegisters(unsigned char* vectorRegistersNew,unsigned int* scalarRegistersNew)
{
	vectorRegisters = vectorRegistersNew;
	scalarRegisters = scalarRegistersNew;
}

void Write_Back::setVectorRegister(short din, unsigned char* vector)
{
	if(din > REGISTER_SIZE_IN_BYTES_WB)
	{
		printf("Solo existen %d vectores, usted intento acceder al: %d\n",REGISTER_SIZE_IN_BYTES_WB,din);
	}
	else
	{
		for (int i = 0; i < REGISTER_SIZE_IN_BYTES_WB; ++i)
		{
			vectorRegisters[din*REGISTER_SIZE_IN_BYTES_WB + i]  = vector[i];
		}
	}

}


void Write_Back::printData()
{
  printf("--------------WriteBack Data-------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
  printf("DoDataMem: %s\n",this->DoDataMem );
  printf("AluResult: %s\n",this->AluResult );
  printf("AluResultScalar: %d\n",this->AluResultScalar );
  printf("Rg: %d\n",this->Rg );
  this->printVectorRegisters();
  this->printScalarRegisters();
}

void Write_Back::printVectorRegisters()
{
	printf("--------------WriteBack Vector Registers Values-----\n");
	printf("----------------------------------------------------\n");
	for (int i = 0; i < REGISTER_SIZE_IN_BYTES_WB; ++i)
	{
		printf("Vector[%d]: ",i);
		for (int j = 0; j < REGISTER_SIZE_IN_BYTES_WB; ++j)
		{
			printf("%c",this->vectorRegisters[i*REGISTER_SIZE_IN_BYTES_WB + j]);
		}
		printf("\n");
	}
}

void Write_Back::printScalarRegisters()
{
  printf("--------------WriteBack Scalar Registers Values-----\n");
	printf("----------------------------------------------------\n");
	for (int j = 0; j < SCALAR_REGISTERS_MEM_SIZE_WB; ++j)
	{
		printf("Register %d: %d\n",j,this->scalarRegisters[j]);
	}
}
