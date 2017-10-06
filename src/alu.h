#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

class Alu
{
	public:
		Alu();
		char result;
		unsigned char sum (char op1, char op2);
		unsigned char sub (char op1, char op2);
		unsigned char xxor(char op1, char op2);
		unsigned char mult(char op1, char op2);
		unsigned char div (char op1, char op2);
	private:
};