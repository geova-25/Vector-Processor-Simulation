#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include "fetch.h"
#include "fetch_decoder_register.h"
#include "decoder.h"
#include "decoder_execute_register.h"
#include "execute.h"
#include "register_exe_mem.h"
#include "memory.h"
#include "register_mem_wb.h"
#include "write_back.h"

using namespace std;

class VectorProcessor
{
	public:
		VectorProcessor();
		void refreshRegisters();
		void run(int totalInstructionsNumber);
		void setInstructionMemory(string* instructionMemory);
		void setDataMemory(unsigned char* dataMemory, int imageSize);
		unsigned char* getDataMemory();

	private:
		Fetch fetch;
	  Fetch_Decoder_Register fetch_decoder_register;
	  Decoder decoder;
	  Decoder_Execute_Register decoder_execute_register;
	  Execute execute;
	  Register_Exe_Mem register_exe_mem;
	  Memory mem;
	  Register_Mem_Wb register_mem_wb;
	  Write_Back write_back;
		void printValues();
};
