#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

class Alu
{
	public:
		Alu();
		char result;
		unsigned char sum (unsigned char op1, unsigned char op2);
		unsigned char sub (unsigned char op1, unsigned char op2);
		unsigned char xxor(unsigned char op1, unsigned char op2);
		unsigned char shfl(unsigned char op1, unsigned char op2);
		unsigned char shfr(unsigned char op1, unsigned char op2);
		unsigned char shflc(unsigned char op1, unsigned char op2);
		unsigned char shfrc(unsigned char op1, unsigned char op2);
		unsigned char mult(unsigned char op1, unsigned char op2);
		unsigned char div (unsigned char op1, unsigned char op2);
	private:
};