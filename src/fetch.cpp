#include "fetch.h"
#include <stdio.h>

Fetch::Fetch(){
	this->instructionMemory = new string[INST_MEM_SIZE];
	this->pc = 0;
}

void Fetch::adder(){
	this->pc = this->pc + 1;
}

int Fetch::getPC(){
	return pc;
}

string* Fetch::getInstructionMemory(){
	return instructionMemory;
}

int Fetch::getMemorySize(){
	return INST_MEM_SIZE;
}

void Fetch::run(){
	this->Do = instructionMemory[this->pc];	
	this->adder();
}

