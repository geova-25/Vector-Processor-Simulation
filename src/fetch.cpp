#include "fetch.h"
#include <stdio.h>

Fetch::Fetch(){
	this->instructionMemory = (unsigned char*)malloc(sizeof(unsigned char)*MEM_SIZE);
	this->pc = 0;
	this->Do = (unsigned char*)calloc(WORD_SIZE_IN_BITS,sizeof(unsigned char));
}

void Fetch::adder(){
	this->pc = this->pc + 1;
}

int Fetch::getPC(){
	return pc;
}

unsigned char* Fetch::getInstructionMemory(){
	return instructionMemory;
}

int Fetch::getMemorySize(){
	return MEM_SIZE;
}

void Fetch::run(){

	for (int i = 0; i < 32; ++i)
	{
		Do[i] = instructionMemory[this->pc + i];	
	}
	this->adder();
}

