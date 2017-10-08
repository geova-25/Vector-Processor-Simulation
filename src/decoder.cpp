#include "decoder.h"

Decoder::Decoder()
{
	DoAVector = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
	DoBVector = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
	DoVA= (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
	DoVB = (unsigned char*)calloc(REGISTER_SIZE_IN_BYTES, sizeof(unsigned char));
	DoAScalar = ' ';
}

void Decoder::run(short OpDo, short FDo, short RvgDo, short RvsDo, short RvpDo, int ImmNumDo)
{
	DoVA = getVectorRegisterA(RvsDo);
	DoVB = getVectorRegisterB(RvpDo);
	DoSA = getScalarRegister(RvsDo);
	DoSB = getScalarRegister(RvpDo);
	Imm  = ImmNumDo;
	OpDout = OpDo;
}

void Decoder::printDout()
{
	printf("--------------Datos de salida deco----------------------------\n");
	printf("--------------------------------------------------------------\n");

	cout << "DoVA: " << this->DoVA << "\n";
	cout << "DoVB: " << this->DoVB << "\n";
	cout << "DoSA: " << this->DoSA << "\n";
	cout << "DoSB: " << this->DoSB << "\n";
	cout << "OpDout: " << this->OpDout << "\n";
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
  printf("--------------Registers Values--------------------------------\n");
  printf("--------------------------------------------------------------\n");
	for (int i = 0; i < REGISTER_SIZE_IN_BYTES; ++i)
	{
		for (int j = 0; j < REGISTER_SIZE_IN_BYTES; ++j)
		{
			printf("Vector %d[%d]: %c\n",i,j,vectorRegisters[i*REGISTER_SIZE_IN_BYTES + j]);
		}	
	}
}


void Decoder::printVectorRegisters()
{
	printf("--------------Registers Values--------------------------------\n");
	printf("--------------------------------------------------------------\n");
	for (int i = 0; i < REGISTER_SIZE_IN_BYTES; ++i)
	{
		printf("Vector[%d]: ",i);
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

unsigned int Decoder::getScalarRegister(short direction)
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

void Decoder::setScalarRegister(short direction, int data)
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
		printf("Register %d: %d\n",j,scalarRegisters[j]);
	}
}





