#include <stdlib.h>

using namespace std;
#define MEM_SIZE 32000
#define WORD_SIZE_IN_BITS 32

class Fetch
{

public:
	Fetch();
	unsigned char* Do;
    unsigned char* getInstructionMemory();
    int getPC();
    int getMemorySize();
    void run();

private: 
	unsigned char* instructionMemory;
	int pc;
	void adder();
};

