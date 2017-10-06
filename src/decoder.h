#include <stdlib.h>
#include <stdio.h>
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
		void setScalarRegister(short din, unsigned char data);
		char getScalarRegister(short direction);
		void printScalarRegisters();
	private:
		unsigned char* DoAVector;
		unsigned char* DoBVector;
		unsigned char  DoAScalar;
		char vectorRegisters[VECTOR_REGISTERS_MEM_SIZE];
		char scalarRegisters[SCALAR_REGISTERS_MEM_SIZE];
		unsigned char* getVector(short outPort, int direction);

};