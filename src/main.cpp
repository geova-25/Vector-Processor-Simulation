#include <stdio.h>
#include <png.h>
#include "vectorProcessor.h"
#include <stdlib.h>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;


void unitTest_fetch_reg_deco_reg_exe_reg_mem()
{
    Fetch fetch;
    Fetch_Decoder_Register fetch_decoder_register;
    Decoder decoder;
    Decoder_Execute_Register decoder_execute_register;
    Execute execute;
    Register_Exe_Mem register_exe_mem;
    Memory mem;

    mem.insertValueInMem(2000,(unsigned char*)"FearOfTh");
    mem.insertValueInMem(108, (unsigned char*)"eDaaaark");
    mem.insertValueInMem(0, (unsigned char*)"Yolooo");

    unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
    vectorPrueba1 = (unsigned char*)"DrStein";
    vectorPrueba2 = (unsigned char*)"Hallowee";
    vectorPrueba3 = (unsigned char*)"IWantOut";
    vectorPrueba4 = (unsigned char*)"KeeperSe";
    decoder.setVectorRegister(0,vectorPrueba1);
    decoder.setVectorRegister(1,vectorPrueba2);
    decoder.setVectorRegister(2,vectorPrueba3);
    decoder.setVectorRegister(3,vectorPrueba4);
    decoder.setScalarRegister(0,2000);
    decoder.setScalarRegister(1,'l');
    decoder.setScalarRegister(2,'a');


    int contador = 0;
    string* instructionMemory = new string[INST_MEM_SIZE];
    instructionMemory = fetch.getInstructionMemory();
    //SumV Rv4 Rv1 Rv2
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[0] = "00000010000101000000000000000000";
    //Sub Rv1 Rv3 Rv6
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[1] = "00010000101111000000000000000000";
    //SumVS Rv2 Rv1 Rv2
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[2] = "00100001000101000000000000000000";
    //SubVS Rv3 Rv1 Rv5
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[3] = "00110001100110100000000000000000";
    instructionMemory[4] = "00110000100110100000000000000000";
    instructionMemory[5] = "00110000100110100000000000000000";


    while(contador <= 60)
    {

      printf("\n");
      printf("+++++++++++++++++++++++++New Iteration %d++++++++++++++++++++++++++++++++\n",contador);
      printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
      printf("\n");
      //printf("--------------------------------------------------------------\n");
      //printf("--------------------------------------------------------------\n");

      //Part of the algorithm

      fetch.run();
      fetch_decoder_register.saveRegister(fetch.Do);
      decoder.run(fetch_decoder_register.OpDo, fetch_decoder_register.FDo, fetch_decoder_register.RvgDo, fetch_decoder_register.RvsDo, fetch_decoder_register.RvpDo, fetch_decoder_register.ImmNumDo);
      decoder_execute_register.run(decoder.DoVA,decoder.DoVB,decoder.DoSA,decoder.DoSB,decoder.OpDout,decoder.Imm,decoder.RgDecoOut);
      execute.run(decoder_execute_register.OpDout,decoder_execute_register.DoVA,decoder_execute_register.DoVB,decoder_execute_register.DoSA,decoder_execute_register.DoSB, decoder_execute_register.ImmOut, decoder_execute_register.RgOut);
      register_exe_mem.run(execute.result,execute.DinMD,execute.resultScalar,execute.AddrA, execute.RgOutExe, execute.selData, execute.selRegType, execute.selWriteMem);
      mem.run(register_exe_mem.DoDinMD,register_exe_mem.Doresult,register_exe_mem.DoAddrA,register_exe_mem.DoresultScalar,register_exe_mem.RgOut, register_exe_mem.selDataOut,register_exe_mem.selRegTypeOut, register_exe_mem.selWriteMemOut, contador);
      usleep(1000000);


      //-----------------Prints--------------
      decoder.printVectorRegisters();
      decoder.printScalarRegisters();
      fetch_decoder_register.printDin();
      fetch_decoder_register.printDout();
      decoder.printDout();
      decoder_execute_register.printDin();
      decoder_execute_register.printDout();
      execute.printDout();
      register_exe_mem.printDin();
      register_exe_mem.printDout();
      mem.printData();
      //-----------------Change Registers
      fetch_decoder_register.changeOutPutRegisters();
      decoder_execute_register.changeOutPutRegisters();
      register_exe_mem.changeOutPutRegisters();
      //-----------------Others
      contador = contador + 1;
    }
}

void unitTest_fetch_reg_deco_reg_exe_reg_mem_reg()
{
    Fetch fetch;
    Fetch_Decoder_Register fetch_decoder_register;
    Decoder decoder;
    Decoder_Execute_Register decoder_execute_register;
    Execute execute;
    Register_Exe_Mem register_exe_mem;
    Memory mem;
    Register_Mem_Wb register_mem_wb;

    unsigned int* ScalarRegisters;
    unsigned char* VectorRegisters;

    ScalarRegisters = (unsigned int*)calloc(8, sizeof(unsigned int));
    VectorRegisters = (unsigned char*)calloc(64, sizeof(unsigned char));

    decoder.setRegisters(VectorRegisters,ScalarRegisters);
    //write_back..setRegisters(VectorRegisters,ScalarRegisters);


    mem.insertValueInMem(2000,(unsigned char*)"FearOfTh");
    mem.insertValueInMem(108, (unsigned char*)"eDaaaark");
    mem.insertValueInMem(0, (unsigned char*)"Yolooo");

    unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
    vectorPrueba1 = (unsigned char*)"DrStein";
    vectorPrueba2 = (unsigned char*)"Hallowee";
    vectorPrueba3 = (unsigned char*)"IWantOut";
    vectorPrueba4 = (unsigned char*)"KeeperSe";
    decoder.setVectorRegister(0,vectorPrueba1);
    decoder.setVectorRegister(1,vectorPrueba2);
    decoder.setVectorRegister(2,vectorPrueba3);
    decoder.setVectorRegister(3,vectorPrueba4);
    decoder.setScalarRegister(0,2000);
    decoder.setScalarRegister(1,'l');
    decoder.setScalarRegister(2,'a');


    int contador = 0;
    string* instructionMemory = new string[INST_MEM_SIZE];
    instructionMemory = fetch.getInstructionMemory();
    //SumV Rv4 Rv1 Rv2
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[0] = "00000010000101000000000000000000";
    //Sub Rv1 Rv3 Rv6
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[1] = "00010000101111000000000000000000";
    //SumVS Rv2 Rv1 Rv2
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[2] = "00100001000101000000000000000000";
    //SubVS Rv3 Rv1 Rv5
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[3] = "00110001100110100000000000000000";
    instructionMemory[4] = "00110000100110100000000000000000";
    instructionMemory[5] = "00110000100110100000000000000000";


    while(contador <= 60)
    {

      printf("\n");
      printf("+++++++++++++++++++++++++New Iteration %d++++++++++++++++++++++++++++++++\n",contador);
      printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
      printf("\n");
      //printf("--------------------------------------------------------------\n");
      //printf("--------------------------------------------------------------\n");

      //Part of the algorithm

      fetch.run();
      fetch_decoder_register.saveRegister(fetch.Do);
      decoder.run(fetch_decoder_register.OpDo, fetch_decoder_register.FDo, fetch_decoder_register.RvgDo, fetch_decoder_register.RvsDo, fetch_decoder_register.RvpDo, fetch_decoder_register.ImmNumDo);
      decoder_execute_register.run(decoder.DoVA,decoder.DoVB,decoder.DoSA,decoder.DoSB,decoder.OpDout,decoder.Imm,decoder.RgDecoOut);
      execute.run(decoder_execute_register.OpDout,decoder_execute_register.DoVA,decoder_execute_register.DoVB,decoder_execute_register.DoSA,decoder_execute_register.DoSB, decoder_execute_register.ImmOut, decoder_execute_register.RgOut);
      register_exe_mem.run(execute.result,execute.DinMD,execute.resultScalar,execute.AddrA, execute.RgOutExe, execute.selData, execute.selRegType, execute.selWriteMem);
      mem.run(register_exe_mem.DoDinMD,register_exe_mem.Doresult,register_exe_mem.DoAddrA,register_exe_mem.DoresultScalar,register_exe_mem.RgOut, register_exe_mem.selDataOut,register_exe_mem.selRegTypeOut, register_exe_mem.selWriteMemOut, contador);
      register_mem_wb.run(mem.Do,mem.Alu_result,mem.RgOutMemory/*AQUI VA RG*/,mem.AluResultScalar, mem.selData, mem.selRegType, mem.selWriteMem);
      usleep(1000000);


      //-----------------Prints--------------
      decoder.printVectorRegisters();
      decoder.printScalarRegisters();
      fetch_decoder_register.printDin();
      fetch_decoder_register.printDout();
      decoder.printDout();
      decoder_execute_register.printDin();
      decoder_execute_register.printDout();
      execute.printDout();
      register_exe_mem.printDin();
      register_exe_mem.printDout();
      mem.printData();
      register_mem_wb.printDin();
      register_mem_wb.printDout();
      //-----------------Change Registers
      fetch_decoder_register.changeOutPutRegisters();
      decoder_execute_register.changeOutPutRegisters();
      register_exe_mem.changeOutPutRegisters();
      register_mem_wb.changeOutPutRegisters();
      //-----------------Others
      contador = contador + 1;
    }
}


void unitTest_fetch_reg_deco_reg_exe_reg_mem_reg_wb()
{
    Fetch fetch;
    Fetch_Decoder_Register fetch_decoder_register;
    Decoder decoder;
    Decoder_Execute_Register decoder_execute_register;
    Execute execute;
    Register_Exe_Mem register_exe_mem;
    Memory mem;
    Register_Mem_Wb register_mem_wb;
    Write_Back write_back;
    unsigned int* ScalarRegisters;
    unsigned char* VectorRegisters;

    ScalarRegisters = (unsigned int*)calloc(8, sizeof(unsigned int));
    VectorRegisters = (unsigned char*)calloc(64, sizeof(unsigned char));

    decoder.setRegisters(VectorRegisters,ScalarRegisters);
    write_back.setRegisters(VectorRegisters,ScalarRegisters);


    mem.insertValueInMem(2000,(unsigned char*)"FearOfTh");
    mem.insertValueInMem(108, (unsigned char*)"eDaaaark");
    mem.insertValueInMem(10, (unsigned char*)"Yolooo");

    unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
    unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
    vectorPrueba1 = (unsigned char*)"DrStein";
    vectorPrueba2 = (unsigned char*)"Hallowee";
    vectorPrueba3 = (unsigned char*)"IWantOut";
    vectorPrueba4 = (unsigned char*)"KeeperSe";
    decoder.setVectorRegister(0,vectorPrueba1);
    decoder.setVectorRegister(1,vectorPrueba2);
    decoder.setVectorRegister(2,vectorPrueba3);
    decoder.setVectorRegister(3,vectorPrueba4);
    decoder.setScalarRegister(0,2000);
    decoder.setScalarRegister(1,'l');
    decoder.setScalarRegister(2,'a');


    int contador = 0;
    string* instructionMemory = new string[INST_MEM_SIZE];
    instructionMemory = fetch.getInstructionMemory();
    //SumV Rv4 Rv1 Rv2
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[0] = "00000010000101000000000000000000";
    //Sub Rv1 Rv3 Rv6
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[1] = "01110000101111000000000000000000";
    //SumVS Rv2 Rv1 Rv2
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[2] = "00100001000101000000000000000000";
    //SubVS Rv3 Rv1 Rv5
    //                       OP|F|Rg|Rs|Rp|
    instructionMemory[3] = "00110001100110100000000000000000";
    instructionMemory[4] = "00110000100110100000000000000000";
    instructionMemory[5] = "00110000100110100000000000000000";


    while(contador <= 60)
    {

      printf("\n");
      printf("+++++++++++++++++++++++++New Iteration %d++++++++++++++++++++++++++++++++\n",contador);
      printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
      printf("\n");
      //printf("--------------------------------------------------------------\n");
      //printf("--------------------------------------------------------------\n");

      //Part of the algorithm

      fetch.run();
      fetch_decoder_register.saveRegister(fetch.Do);
      decoder.run(fetch_decoder_register.OpDo, fetch_decoder_register.FDo, fetch_decoder_register.RvgDo, fetch_decoder_register.RvsDo, fetch_decoder_register.RvpDo, fetch_decoder_register.ImmNumDo);
      decoder_execute_register.run(decoder.DoVA,decoder.DoVB,decoder.DoSA,decoder.DoSB,decoder.OpDout,decoder.Imm,decoder.RgDecoOut);
      execute.run(decoder_execute_register.OpDout,decoder_execute_register.DoVA,decoder_execute_register.DoVB,decoder_execute_register.DoSA,decoder_execute_register.DoSB, decoder_execute_register.ImmOut, decoder_execute_register.RgOut);
      register_exe_mem.run(execute.result,execute.DinMD,execute.resultScalar,execute.AddrA, execute.RgOutExe, execute.selData, execute.selRegType, execute.selWriteMem);
      mem.run(register_exe_mem.DoDinMD,register_exe_mem.Doresult,register_exe_mem.DoAddrA,register_exe_mem.DoresultScalar,register_exe_mem.RgOut, register_exe_mem.selDataOut,register_exe_mem.selRegTypeOut, register_exe_mem.selWriteMemOut, contador);
      register_mem_wb.run(mem.Do,mem.Alu_result,mem.RgOutMemory/*AQUI VA RG*/,mem.AluResultScalar, mem.selData, mem.selRegType, mem.selWriteMem);
      write_back.run(register_mem_wb.DoDataMemoryOut,register_mem_wb.AluResultOut,register_mem_wb.AluResultScalarOut,register_mem_wb.RgOut,register_mem_wb.selDataOut,register_mem_wb.selRegTypeOut,register_mem_wb.selWriteMemOut ,contador);
      usleep(1000000);


      //-----------------Prints--------------
      decoder.printVectorRegisters();
      decoder.printScalarRegisters();
      fetch_decoder_register.printDin();
      fetch_decoder_register.printDout();
      decoder.printDout();
      decoder_execute_register.printDin();
      decoder_execute_register.printDout();
      execute.printDout();
      register_exe_mem.printDin();
      register_exe_mem.printDout();
      mem.printData();
      register_mem_wb.printDin();
      register_mem_wb.printDout();
      write_back.printData();
      //-----------------Change Registers
      fetch_decoder_register.changeOutPutRegisters();
      decoder_execute_register.changeOutPutRegisters();
      register_exe_mem.changeOutPutRegisters();
      register_mem_wb.changeOutPutRegisters();
      //-----------------Others
      contador = contador + 1;
    }
}

int main(){
  //printString(returnString());
  //unitTest_FetchDecoderRegisters();
  //unitTest_VectorProcessor();
  //unitTest_ScalarRegisters();
  //unitTest_DecoderRegisters();
  //unitTest_fetch_reg_deco();
  //unitTest_DecoderExecuteRegister();
  //unitTest_image();
  //unitTest_fetch();
  //unitTest_Execute();
  //unitTest_Alu();
  //unitTest_fetch_reg_deco_reg();
  //unitTest_Register_Exe_Mem();
  //unitTest_fetch_reg_deco_reg_exe();
  //unitTest_Mem();
  //unitTest_fetch_reg_deco_reg_exe_reg();
  //unitTest_fetch_reg_deco_reg_exe_reg_mem_reg();
  unitTest_fetch_reg_deco_reg_exe_reg_mem_reg_wb();

  /*
  string str[100];
  str[0] = "asdfasdf";
  str[1] = "asdfasdf";
  str[2] = "asdfasdf";
  cout << str[0][2] << "\n";
  cout << str[1][5] << "\n";
  cout << str[2] << "\n";
  */

  /*

  int* a = (int *)malloc(sizeof(int)*4);
  int* b = (int *)malloc(sizeof(int)*4);
  a[1] = 7;
  b[1] = a[1];
  b[1] = 8;
  printf("a: %d\n",a[1]);
  printf("b: %d\n",b[1]);

  */


  return 0;
}
