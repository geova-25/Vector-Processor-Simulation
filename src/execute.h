#include <stdlib.h>
#include <stdio.h>
#include "alu.h"

#define SIZE_OF_RESULT_BYTES 8

using namespace std;

class Execute
{
	public:
		Execute();
		unsigned char* result;
		char getAluvalue(short alu);
		unsigned char* sum(unsigned char* vector1, unsigned char* vector2);
		unsigned char* sub(unsigned char* vector1, unsigned char* vector2);
	private:
		Alu alu0;
		Alu alu1;
		Alu alu2;
		Alu alu3;
		Alu alu4;
		Alu alu5;
		Alu alu6;
		Alu alu7;
};

