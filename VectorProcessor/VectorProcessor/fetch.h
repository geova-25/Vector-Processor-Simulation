#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;
#define INST_MEM_SIZE 157500
#define WORD_SIZE_IN_BITS 32

class Fetch
{

public:
	Fetch();
	string Do;
    string* getInstructionMemory();
		void setInstructionMemory(string* newMem);
		void printInstructionMemory();
    int getPC();
    int getMemorySize();
    void run();

private:
	string* instructionMemory;
	int pc;
	void adder();
};
