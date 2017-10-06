#include "decoder.h"

Decoder::Decoder()
{
	DoAVector = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
	DoBVector = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
	DoAScalar = ' ';
}

//-------------------------------------------------Vector

unsigned char* Decoder::getVectorRegisterA(int directionA)
{
	return this->getVector(0, directionA);
}

unsigned char* Decoder::getVectorRegisterB(int directionB)
{
	return this->getVector(1, directionB);
}


void Decoder::setVectorRegister(short din, unsigned char* vector)
{
	if(din > QUANTITY_VECTOR_REGISTERS)
	{
		printf("Solo existen %d vectores, usted intento acceder al: %d\n",QUANTITY_VECTOR_REGISTERS,din);
	}
	else
	{
		for (int i = 0; i < REGISTER_SIZE_IN_BYTES; ++i)
		{
			vectorRegisters[din*REGISTER_SIZE_IN_BYTES + i]  = vector[i];
		}
	}

}

void Decoder::printVectorRegistersByBytes()
{
	for (int i = 0; i < REGISTER_SIZE_IN_BYTES; ++i)
	{
		for (int j = 0; j < REGISTER_SIZE_IN_BYTES; ++j)
		{
			printf("Vector %d[%d]: %c\n",i,j,vectorRegisters[i*REGISTER_SIZE_IN_BYTES + j]);
		}
		printf("-------");
	}

}


void Decoder::printVectorRegisters()
{
	for (int i = 0; i < REGISTER_SIZE_IN_BYTES; ++i)
	{
		printf("-------\n Vector[%d]: ",i);
		for (int j = 0; j < REGISTER_SIZE_IN_BYTES; ++j)
		{
			printf("%c",vectorRegisters[i*REGISTER_SIZE_IN_BYTES + j]);
		}
		printf("\n");
	}

}

unsigned char* Decoder::getVector(short outPort, int direction)
{
	unsigned char* currentVector = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES,sizeof(unsigned char));
	if(direction > QUANTITY_VECTOR_REGISTERS)
	{
		printf("Intentando acceder a Registro de Vectores no alineadamente en la direccion: %d\n",direction);
	}
	else
	{
		if(outPort == 0)
		{
			currentVector = DoAVector;
		}
		else
		{
			currentVector = DoBVector;
		}

		for (int i = 0; i < 8; ++i)
		{
			currentVector[i] = 	vectorRegisters[direction*REGISTER_SIZE_IN_BYTES + i];
		}
	}
	return currentVector;
}



//-------------------------------------------------Scalar

char Decoder::getScalarRegister(short direction)
{
	if(direction > QUANTITY_SCALAR_REGISTERS)
	{
		printf("Solo existen %d vectores, usted intento acceder al: %d\n",QUANTITY_SCALAR_REGISTERS,direction);
		return '0';
	}
	else
	{
		return scalarRegisters[direction];
	}	

}

void Decoder::setScalarRegister(short direction, unsigned char data)
{
	if(direction > SCALAR_REGISTERS_MEM_SIZE)
	{
		printf("Error solo existen %d registros escalaras, usted intento acceder al: %d",QUANTITY_SCALAR_REGISTERS,direction);
	}
	else
	{	
		scalarRegisters[direction] = data;
	}
}

void Decoder::printScalarRegisters()
{
	for (int j = 0; j < QUANTITY_SCALAR_REGISTERS; ++j)
	{
		printf("Register %d: %c\n",j,scalarRegisters[j]);
	}
}





