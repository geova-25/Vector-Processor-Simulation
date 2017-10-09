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
		void setInstructionMemory(string* instructionMemory);
		void setDataMemory(unsigned char* dataMemory);
		void refreshRegisters();
		void run();

	private:
		Fetch_Decoder_Register fetch_decoder_register;
		Fetch fetch;
		Decoder deco;



};
