#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

#define OP_SIZE 4
#define F_SIZE 2
#define RVG_SIZE 3
#define RVP_SIZE 3
#define RVS_SIZE 3

class Fetch_Decoder_Register
{
	public:
    Fetch_Decoder_Register();
		short OpDo;
  	short FDo;
 		short RvgDo;
  	short RvsDo;
  	short RvpDo;
  	short ImmNumDo;
 		void saveRegister(string DoInstrutionMemory);
 		void changeOutPutRegisters();

	private:
		//----------Fetch-Decoder Registers 
		short OpDin;
  	short FDin;
 		short RvgDin;
  	short RvsDin;
  	short RvpDin;
  	short ImmNumDin;
};