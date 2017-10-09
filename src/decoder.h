#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define VECTOR_REGISTERS_MEM_SIZE 64
#define SCALAR_REGISTERS_MEM_SIZE 8
#define REGISTER_SIZE_IN_BYTES 8
#define QUANTITY_VECTOR_REGISTERS 8
#define QUANTITY_SCALAR_REGISTERS 8

class Decoder
{
	public:
		Decoder();
		//--------Vector
		unsigned char* getVectorRegisterA(int directionA);
		unsigned char* getVectorRegisterB(int directionB);
		void setVectorRegister(short din, unsigned char* vector);
		void printVectorRegistersByBytes();
		void printVectorRegisters();
		//-------Scalar
		void setScalarRegister(short din, int data);
		unsigned int getScalarRegister(short direction);
		void printScalarRegisters();
		void printDout();
		void run(short OpDo, short FDo, short RvgDo, short RvsDo, short RvpDo, int ImmNumDo);
		void setRegisters(unsigned char* vectorRegistersNew, unsigned int* scalarRegistersNew);
		unsigned char* DoVA;
		unsigned char* DoVB;
		int DoSA;
		int DoSB;
		int Imm;
		short OpDout;
		short RgDecoOut;
	private:
		//short OpDin;
		unsigned char* DoAVector;
		unsigned char* DoBVector;
		unsigned char  DoAScalar;
		unsigned char* vectorRegisters;
		unsigned int*  scalarRegisters;
		/*
		unsigned char vectorRegisters[VECTOR_REGISTERS_MEM_SIZE];
		unsigned int scalarRegisters[SCALAR_REGISTERS_MEM_SIZE];
		*/
		unsigned char* getVector(short outPort, int direction);

};
