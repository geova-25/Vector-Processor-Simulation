#include "alu.h"

Alu::Alu()
{

}

unsigned char Alu::sum(unsigned char op1,unsigned char op2)
{
	result = op1 + op2;
	return result;
}
unsigned char Alu::sub(unsigned char op1,unsigned char op2)
{
	result = op1 - op2;
	return result;	
}
unsigned char Alu::xxor(unsigned char op1, unsigned char op2)
{
	result = op1 ^ op2;
	return result;	
}
unsigned char Alu::shfl(unsigned char op1, unsigned char op2)
{
	result = op1 << op2;
	return result;	
}
unsigned char Alu::shfr(unsigned char op1, unsigned char op2)
{
	result = op1 >> op2;
	return result;	
}
unsigned char Alu::shflc(unsigned char op1, unsigned char op2)
{
	unsigned char aux = op1;
	short op2Inverted;
	op2Inverted = 8 - op2;
	aux = aux >> op2Inverted;
	result = op1 << op2;
	result = result | aux;
	return result;	
}
unsigned char Alu::shfrc(unsigned char op1, unsigned char op2)
{
	unsigned char aux = op1;
	short op2Inverted;
	op2Inverted = 8 - op2;
	aux = aux << op2Inverted;
	result = op1 >> op2;
	result = result | aux;
	return result;	
}
unsigned char Alu::mult(unsigned char op1,unsigned char op2)
{
	result = op1 * op2;
	return result;
}
unsigned char Alu::div(unsigned char op1,unsigned char  op2)
{
	result = op1 / op2;
	return result;
}