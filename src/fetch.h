#include <stdlib.h>
#include <string>

using namespace std;
#define INST_MEM_SIZE 1024
#define WORD_SIZE_IN_BITS 32

class Fetch
{

public:
	Fetch();
	string Do;
    string* getInstructionMemory();
    int getPC();
    int getMemorySize();
    void run();

private: 
	string* instructionMemory;
	int pc;
	void adder();
};

