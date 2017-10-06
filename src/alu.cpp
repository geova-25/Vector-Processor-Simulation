#include "alu.h"

Alu::Alu()
{

}

unsigned char Alu::sum(char op1,char op2)
{
	result = op1 + op2;
	return result;
}
unsigned char Alu::sub(char op1,char op2)
{
	result = op1 - op2;
	return result;	
}
unsigned char Alu::xxor(char op1, char op2)
{
	result = op1 | op2;
	return result;	
}
unsigned char Alu::mult(char op1,char op2)
{
	result = op1 * op2;
	return result;
}
unsigned char Alu::div(char op1,char  op2)
{
	result = op1 ^ op2;
	return result;
}