#include "fetch.h"


Fetch::Fetch(){
	this->instructionMemory = new string[INST_MEM_SIZE];
	this->pc = 0;
}

void Fetch::adder(){
	this->pc = this->pc + 1;
}

void Fetch::printInstructionMemory()
{
	for (int i = 0; i < INST_MEM_SIZE; i++) {
		std::cout  << i << ": " << instructionMemory[i] << '\n';
	}
}

int Fetch::getPC(){
	return pc;
}

string* Fetch::getInstructionMemory(){
	return instructionMemory;
}

void Fetch::setInstructionMemory(string* newMem)
{
	instructionMemory = newMem;
}

int Fetch::getMemorySize(){
	return INST_MEM_SIZE;
}

void Fetch::run(){
	this->Do = instructionMemory[this->pc];
	this->adder();
}
