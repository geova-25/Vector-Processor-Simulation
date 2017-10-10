#include "fetch_decoder_register.h"

Fetch_Decoder_Register::Fetch_Decoder_Register()
{
	OpDo = 0;
  FDo = 0;
 	RvgDo = 0;
  RvsDo = 0;
  RvpDo = 0;
  ImmNumDo = 0;
}

void Fetch_Decoder_Register::changeOutPutRegisters(){
	OpDo = OpDin;
  FDo = FDin;
 	RvgDo = RvgDin;
  RvsDo = RvsDin;
  RvpDo = RvpDin;
  ImmNumDo = ImmNumDin;
}

void Fetch_Decoder_Register::printDout()
{
  printf("--------------Datos de salida registro fetch-deco-------------\n");
  printf("--------------------------------------------------------------\n");

  cout << "OpDo: "     << this->OpDo     << "\n";
  cout << "FDo: "      << this->FDo      << "\n";
  cout << "RvgDo: "    << this->RvgDo    << "\n";
  cout << "RvsDo: "    << this->RvsDo    << "\n";
  cout << "RvpDo: "    << this->RvpDo    << "\n";
  cout << "ImmNumDo: " << this->ImmNumDo << "\n";

}

void Fetch_Decoder_Register::printDin()
{
  printf("--------------Datos de entrada registro fetch-deco------------\n");
  printf("--------------------------------------------------------------\n");
  printf("---Numbers:---\n");
  printf("OpDin:  %d\n",OpDin);
  printf("FDin:   %d\n",FDin);
  printf("RvgDin: %d\n",RvgDin);
  printf("RvsDin: %d\n",RvsDin);
  printf("RvpDin: %d\n",RvpDin);
  printf("ImmNumDin:  %d\n",ImmNumDin);

}

void Fetch_Decoder_Register::saveRegister(string DoInstrutionMemory)
{

  unsigned char ImmC[IMM_SIZE_BITS + 1];
  unsigned char OpC[OP_SIZE + 1];
  unsigned char FC[F_SIZE + 1];
  unsigned char RvgC[RVG_SIZE + 1];
  unsigned char RvsC[RVS_SIZE + 1];
  unsigned char RvpC[RVP_SIZE + 1];
  string ImmStr;
  string OpStr;
  string FStr;
  string RvgStr;
  string RvsStr;
  string RvpStr;

  //----------------------------Data decoder

  OpC[0] = DoInstrutionMemory[0];
  OpC[1] = DoInstrutionMemory[1];
  OpC[2] = DoInstrutionMemory[2];
  OpC[3] = DoInstrutionMemory[3];
  OpC[OP_SIZE + 1] = '\0';

  //------Format
  FC[0] = DoInstrutionMemory[4];
  FC[1] = DoInstrutionMemory[5];

  //------Rvg
  RvgC[0] = DoInstrutionMemory[6];
  RvgC[1] = DoInstrutionMemory[7];
  RvgC[2] = DoInstrutionMemory[8];

  //------Rvs
  RvsC[0] = DoInstrutionMemory[9];
  RvsC[1] = DoInstrutionMemory[10];
  RvsC[2] = DoInstrutionMemory[11];

  //------Rvp
  RvpC[0] = DoInstrutionMemory[12];
  RvpC[1] = DoInstrutionMemory[13];
  RvpC[2] = DoInstrutionMemory[14];


  //------Immediate
  ImmC[0] = DoInstrutionMemory[12];
  ImmC[1] = DoInstrutionMemory[13];
  ImmC[2] = DoInstrutionMemory[14];
  ImmC[3] = DoInstrutionMemory[15];
  ImmC[4] = DoInstrutionMemory[16];
  ImmC[5] = DoInstrutionMemory[17];
  ImmC[6] = DoInstrutionMemory[18];
  ImmC[7] = DoInstrutionMemory[19];
	ImmC[8] = DoInstrutionMemory[20];
	ImmC[9] = DoInstrutionMemory[21];
	ImmC[10] = DoInstrutionMemory[22];
	ImmC[11] = DoInstrutionMemory[23];
	ImmC[12] = DoInstrutionMemory[24];
	ImmC[13] = DoInstrutionMemory[25];
	ImmC[14] = DoInstrutionMemory[26];
	ImmC[15] = DoInstrutionMemory[27];
	ImmC[16] = DoInstrutionMemory[28];
	ImmC[17] = DoInstrutionMemory[29];
	ImmC[18] = DoInstrutionMemory[30];
	ImmC[19] = DoInstrutionMemory[31];

  //----End of char[]

  FC[F_SIZE] = '\0';
  RvgC[RVG_SIZE] = '\0';
  RvpC[RVP_SIZE] = '\0';
  RvsC[RVS_SIZE] = '\0';
  ImmC[IMM_SIZE_BITS + 1 ] = '\0';

  //Char[] to string

  RvpStr  = (char*)RvpC;
  RvsStr  = (char*)RvsC;
  ImmStr = (char*)ImmC;
  OpStr = (char*)OpC;
  FStr  = (char*)FC;
  RvgStr  = (char*)RvgC;


  //String to number

	try
	{
  	ImmNumDin = stoi(ImmStr,nullptr,2);
  	OpDin = stoi(OpStr,nullptr,2);
  	FDin = stoi(FStr,nullptr,2);
  	RvgDin = stoi(RvgStr,nullptr,2);
  	RvpDin = stoi(RvpStr,nullptr,2);
  	RvsDin = stoi(RvsStr,nullptr,2);
	}
	catch(...)
	{
		ImmNumDin = 0;
  	OpDin = -1;
  	FDin = 0;
  	RvgDin = 0;
  	RvpDin = 0;
 		RvsDin = 0;
	}
}
