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

void Fetch_Decoder_Register::saveRegister(string DoInstrutionMemory)
{

  unsigned char ImmC[9];
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
  

  //----End of char[]

  FC[F_SIZE] = '\0';
  RvgC[RVG_SIZE] = '\0';
  RvpC[RVP_SIZE] = '\0';
  RvsC[RVS_SIZE] = '\0';
  ImmC[8] = '\0';

  //Char[] to string

  RvpStr  = (char*)RvpC;
  RvsStr  = (char*)RvsC;
  ImmStr = (char*)ImmC;
  OpStr = (char*)OpC;
  FStr  = (char*)FC;
  RvgStr  = (char*)RvgC;


  //String to number
  
  ImmNumDin = stoi(ImmStr,nullptr,2);
  OpDin = stoi(OpStr,nullptr,2);
  FDin = stoi(FStr,nullptr,2);
  RvgDin = stoi(RvgStr,nullptr,2);
  RvpDin = stoi(RvpStr,nullptr,2);
  RvsDin = stoi(RvsStr,nullptr,2);


  printf("---Numbers:---\n");
  printf("Op:  %d\n",OpDin);
  printf("F:   %d\n",FDin);
  printf("Rvg: %d\n",RvgDin);
  printf("Rvs: %d\n",RvsDin);
  printf("Rvp: %d\n",RvpDin);
  printf("ImmNum:  %d\n",ImmNumDin);

  printf("---Chars:---\n");

  printf("Op:  %s\n",OpC);
  printf("F:   %s\n",FC);
  printf("Rvg: %s\n",RvgC);
  printf("Rvs: %s\n",RvsC);
  printf("Rvp: %s\n",RvpC);
  printf("Imm_bin: %s\n",ImmC);

  printf("---Strings:---\n");

  printf("OpStr: %s\n" ,OpStr.c_str());
  printf("FStr: %s\n"  ,FStr.c_str());
  printf("RvgStr: %s\n",RvgStr.c_str());
  printf("RvsStr: %s\n",RvsStr.c_str());
  printf("RvpStr: %s\n",RvpStr.c_str());
  printf("ImmStr: %s\n",ImmStr.c_str());

}