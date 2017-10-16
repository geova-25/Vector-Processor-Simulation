#include <stdio.h>
#include <png.h>
#include "vectorProcessor.h"
#include "parser.h"
#include <stdlib.h>
#include <string>
#include <bitset>
#include <iostream>
using namespace std;


#define IMAGE_SIZE 4000000

void unitTest_image(){
  Fetch fetch;
  Memory mem;
  int imageSize = fetch.getMemorySize();
  unsigned char* readImageBuffer = (unsigned char*)calloc(IMAGE_SIZE,sizeof(unsigned char));
  FILE *fp;
  FILE *fp2;
  printf("----------------------Primera\n" );
  mem.printData(1);
   if ((fp = fopen("cat.data", "rb")) == NULL)
      printf("No abierta");

  fp2 = fopen("catAux2.data", "w"); //If not exist then creates it
  fread(readImageBuffer,imageSize,1,fp);
  for (int i = 0; i < IMAGE_SIZE; i++) {
    mem.memory[i] = readImageBuffer[i];
  }
  printf("----------------------Segunda\n" );
  mem.printData(1);
  fwrite(readImageBuffer,1,IMAGE_SIZE,fp2);
}


void unitTest_img_fetch_reg_deco_reg_exe_reg_mem_reg_wb()
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


  //------------------------------------------------------Get image

  int imageSize = 350 * 400;

  unsigned char* readImageBuffer = (unsigned char*)calloc(imageSize,sizeof(unsigned char));
  FILE *fp;
  printf("----------------------Primera\n" );
  mem.printData(1);
   if ((fp = fopen("cat.data", "rb")) == NULL)
      printf("No abierta");
  fread(readImageBuffer,imageSize,1,fp);
  for (int i = DATA_MEM_IMAGE_INIT_POSITION; i < DATA_MEM_IMAGE_INIT_POSITION + imageSize; i++) {
    mem.memory[i] = readImageBuffer[i];
  }

  //------------------------------------------------------

  ScalarRegisters = (unsigned int*)calloc(8, sizeof(unsigned int));
  VectorRegisters = (unsigned char*)calloc(64, sizeof(unsigned char));

  decoder.setRegisters(VectorRegisters,ScalarRegisters);
  write_back.setRegisters(VectorRegisters,ScalarRegisters);


  mem.insertValueInMem(200,(unsigned char*)"FearOfT\0");
  mem.insertValueInMem(112, (unsigned char*)"eDaaaar\0");
  mem.insertValueInMem(8, (unsigned char*)  "Yolooox\0");

  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
  /*
  vectorPrueba1 = (unsigned char*)"DrStein\0";
  vectorPrueba2 = (unsigned char*)"Keraskk\0";
  vectorPrueba3 = (unsigned char*)"MonicaG\0";
  vectorPrueba4 = (unsigned char*)"RapidGu\0";
  */
  for (int i = 0; i < 8; i++)
  {
  vectorPrueba1[i] = rand();
  vectorPrueba2[i] = rand();
  vectorPrueba3[i] = rand();
  vectorPrueba4[i] = rand();
  }


  //decoder.setVectorRegister(0,vectorPrueba1);
  //decoder.setVectorRegister(1,vectorPrueba2);
  //decoder.setVectorRegister(2,vectorPrueba3);
  //decoder.setVectorRegister(3,vectorPrueba4);
  //decoder.setScalarRegister(0,0);
  //decoder.setScalarRegister(1,8);
  //decoder.setScalarRegister(2,112);
  //decoder.setScalarRegister(3,250);
  //decoder.setScalarRegister(5,464);
  //decoder.setScalarRegister(7,40);


  int contador = 0;
  string* instructionMemory = new string[INST_MEM_SIZE];
  instructionMemory = fetch.getInstructionMemory();


  //Mov R0 35 llave
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[1] = "10110000000000000000000000100011";
  //Mov R1 0
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[2] = "10110000100000000000000000000000";
  //Mov R2 8
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[3] = "10110001000000000000000000001000";
  //Mov R3 16
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[4] = "10110001100000000000000000010000";
  //Mov R4 24
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[5] = "10110010000000000000000000011000";
  //Mov R5 32
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[6] = "10110010100000000000000000100000";
  //Mov R6 40
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[7] = "10110011000000000000000000101000";
  //Mov R7 48
  //                       OP|F|Rg|Rs|imm                |
  instructionMemory[8] = "10110011100000000000000000110000";

  //--------------------------------------LOADSS---------------------


  //LDV R1 R1
  //                      |OP|F|Rg|Rs|
  instructionMemory[9] = "10010000100100000000000000000000";

  //LDV R2 R2
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[10] = "10010001001000000000000000000000";

  //LDV R3 R3
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[11] = "10010001101100000000000000000000";

  //LDV R4 R4
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[12] = "10010110010000000000000000000000";

  //LDV R5 R5
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[13] = "10010110110100000000000000000000";

  //LDV R6 R6
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[14] = "10010111011000000000000000000000";

  //LDV R7 R7
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[15] = "10010011111100000000000000000000";


  //--------------------------------------XOR---------------------

  //Aplica un Xor de RS0 con R1
  //Xor R1 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[16] = "01000000100000100000000000000000";

  //Aplica un Xor de RS0 con R2
  //Xor R2 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[17] = "01000001000001000000000000000000";

  //Aplica un Xor de RS0 con R3
  //Xor R3 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[18] = "01000001100001100000000000000000";

  //Aplica un Xor de RS0 con R4
  //Xor R4 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[19] = "01000010000010000000000000000000";

  //Aplica un Xor de RS0 con R5
  //Xor R5 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[20] = "01000010100010100000000000000000";

  //Aplica un Xor de RS0 con R6
  //Xor R6 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[21] = "01000011000011000000000000000000";

  //Aplica un Xor de RS0 con R7
  //Xor R7 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[22] = "01000011100011100000000000000000";

  //--------------------------------------STR---------------------




  //StrV R1 Rv1
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[23] = "01110000000100100000000000000000";

  //StrV R2 Rv2
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[24] = "01110000001001000000000000000000";

  //StrV R3 Rv3
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[25] = "01110000001101100000000000000000";

  //StrV R4 Rv4
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[26] = "01110000010010000000000000000000";

  //StrV R5 Rv5
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[27] = "01110000010110100000000000000000";

  //StrV R6 Rv6
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[28] = "01110000011011000000000000000000";

  //StrV R7 Rv7
  //                       |OP|F|Rg|Rs|Rp|
  instructionMemory[29] = "01110000011111100000000000000000";


  //--------------------------------------SUMS---------------------

  //Aplica un SumS de R1 con R7
  //Sums R1 R1 R7
  //                      |OP|F|Rg|Rs|Rp|
  instructionMemory[30] = "01010000100111100000000000000000";

  //Aplica un SumS de R2 con R7
  //Sums R2 R2 R7
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[31] = "01010001001011100000000000000000";


  //Aplica un SumS de R3 con R7
  //Sums R3 R3 R7
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[32] = "01010001101111100000000000000000";


  //Aplica un SumS de R4 con R7
  //Sums R4 R4 R7
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[33] = "01010010010011100000000000000000";


  //Aplica un SumS de R5 con R7
  //Sums R5 R5 R7
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[34] = "01010010110111100000000000000000";

  //Aplica un SumS de R6 con R7
  //Sums R6 R6 R7
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[35] = "01010011011011100000000000000000";






  /*
  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[1] = "00110001100110100000000000000000";

  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[2] = "0011_0001100110100000000000000000";

  //                       OP|F|Rg|Rs|Rp|
  instructionMemory[4] = "0011_0001100110100000000000000000";
  instructionMemory[5] = "00110000100110100000000000000000";

  instructionMemory[6] = "00110000100110100000000000000000";
  */


  //mem.printData(1);
  while(contador <= 60)
  {

    printf("\n");
    printf("\033[22;34m+++++++++++++++++++++++++New Iteration %d++++++++++++++++++++++++++++++++\033[0m \n",contador);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
    mem.printData(1); // 1 para que printee decimales, 0 strings
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

    //for (int i = 0; i < 32; i=i+8) {
      //printf("%s\n",mem.getValueFromMem(i));
      //if(i%8 == 0) printf("\n");
      //else //printf("%c\n", mem.memory[i]);
    //}
  }
  unsigned char* writeImageBuffer = (unsigned char*)calloc(imageSize,sizeof(unsigned char));
  for (int i = DATA_MEM_IMAGE_INIT_POSITION; i < DATA_MEM_IMAGE_INIT_POSITION + imageSize; i++) {
    writeImageBuffer[i] = mem.memory[i];
  }
  FILE *fp2;
  fp2 = fopen("catAux3.data", "w"); //If not exist then creates it
  fwrite(writeImageBuffer,1,imageSize,fp2);
}


void unitTest_img_dup_fetch_reg_deco_reg_exe_reg_mem_reg_wb()
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


//------------------------------------------------------Get image

  int imageSize = 350 * 400;

  unsigned char* readImageBuffer = (unsigned char*)calloc(imageSize,sizeof(unsigned char));
  FILE *fp;
  printf("----------------------Primera\n" );
   if ((fp = fopen("cat.data", "rb")) == NULL)
      printf("No abierta");
  fread(readImageBuffer,imageSize,1,fp);
  for (int i = DATA_MEM_IMAGE_INIT_POSITION; i < DATA_MEM_IMAGE_INIT_POSITION + imageSize; i++) {
    mem.memory[i] = readImageBuffer[i];
  }

  //------------------------------------------------------

  ScalarRegisters = (unsigned int*)calloc(8, sizeof(unsigned int));
  VectorRegisters = (unsigned char*)calloc(64, sizeof(unsigned char));

  decoder.setRegisters(VectorRegisters,ScalarRegisters);
  write_back.setRegisters(VectorRegisters,ScalarRegisters);


  mem.insertValueInMem(200,(unsigned char*)"FearOfT\0");
  mem.insertValueInMem(112, (unsigned char*)"eDaaaar\0");
  mem.insertValueInMem(8, (unsigned char*)  "Yolooox\0");

  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba3 = (unsigned char*)calloc(8,sizeof(unsigned char));
  unsigned char* vectorPrueba4 = (unsigned char*)calloc(8,sizeof(unsigned char));
/*
  vectorPrueba1 = (unsigned char*)"DrStein\0";
  vectorPrueba2 = (unsigned char*)"Keraskk\0";
  vectorPrueba3 = (unsigned char*)"MonicaG\0";
  vectorPrueba4 = (unsigned char*)"RapidGu\0";
*/
for (int i = 0; i < 8; i++)
{
  vectorPrueba1[i] = rand();
  vectorPrueba2[i] = rand();
  vectorPrueba3[i] = rand();
  vectorPrueba4[i] = rand();
}


  //decoder.setVectorRegister(0,vectorPrueba1);
  //decoder.setVectorRegister(1,vectorPrueba2);
  //decoder.setVectorRegister(2,vectorPrueba3);
  //decoder.setVectorRegister(3,vectorPrueba4);
  //decoder.setScalarRegister(0,0);
  //decoder.setScalarRegister(1,8);
  //decoder.setScalarRegister(2,112);
  //decoder.setScalarRegister(3,250);
  //decoder.setScalarRegister(5,464);
  //decoder.setScalarRegister(7,40);


  int contador = 0;
  //string* instructionMemory = new string[INST_MEM_SIZE];
  //instructionMemory = fetch.getInstructionMemory();


  Parser parser;
  parser.parse();
  fetch.setInstructionMemory(parser.instructions);
  //fetch.printInstructionMemory();

  //mem.printData(1);
  while(contador <= parser.totalInstructionsNumber)
  {

    printf("\n");
    printf("\033[22;34m+++++++++++++++++++++++++New Iteration %d++++++++++++++++++++++++++++++++\033[0m \n",contador);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
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
    //usleep(1000000);


    //-----------------Prints--------------
    /*decoder.printVectorRegisters();
    decoder.printScalarRegisters();
    fetch_decoder_register.printDin();
    fetch_decoder_register.printDout();
    decoder.printDout();
    decoder_execute_register.printDin();
    decoder_execute_register.printDout();
    execute.printDout();
    register_exe_mem.printDin();
    register_exe_mem.printDout();
    mem.printData(1); // 1 para que printee decimales, 0 strings
    register_mem_wb.printDin();
    register_mem_wb.printDout();
    write_back.printData();
    */
    //-----------------Change Registers
    fetch_decoder_register.changeOutPutRegisters();
    decoder_execute_register.changeOutPutRegisters();
    register_exe_mem.changeOutPutRegisters();
    register_mem_wb.changeOutPutRegisters();
    //-----------------Others
    contador = contador + 1;

    //for (int i = 0; i < 32; i=i+8) {
      //printf("%s\n",mem.getValueFromMem(i));
      //if(i%8 == 0) printf("\n");
      //else //printf("%c\n", mem.memory[i]);
    //}
  }
  unsigned char* writeImageBuffer = (unsigned char*)calloc(imageSize,sizeof(unsigned char));
  for (int i = DATA_MEM_IMAGE_INIT_POSITION; i < DATA_MEM_IMAGE_INIT_POSITION + imageSize; i++) {
    writeImageBuffer[i] = mem.memory[i];
  }
  FILE *fp2;
  fp2 = fopen("catAux3.data", "w"); //If not exist then creates it
  fwrite(writeImageBuffer,1,imageSize,fp2);
}


void unitTest_parser_duplicate()
{
  Parser parser;
  parser.parse();
  //parser.duplicate(NULL);
}

int main()
{
  unitTest_img_dup_fetch_reg_deco_reg_exe_reg_mem_reg_wb();
  //unitTest_parser_duplicate();
}
