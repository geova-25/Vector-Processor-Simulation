#include "vectorProcessor.h"

VectorProcessor::VectorProcessor()
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
}

void VectorProcessor::refreshRegisters()
{
  this->fetch_decoder_register.changeOutPutRegisters();
  this->decoder_execute_register.changeOutPutRegisters();
  this->register_exe_mem.changeOutPutRegisters();
  this->register_mem_wb.changeOutPutRegisters();
}

void VectorProcessor::setInstructionMemory(string* instructionMemory)
{
  fetch.setInstructionMemory(instructionMemory);
}

void VectorProcessor::setDataMemory(unsigned char* dataMemory, int imageSize)
{
  for (int i = DATA_MEM_IMAGE_INIT_POSITION; i < DATA_MEM_IMAGE_INIT_POSITION + imageSize; i++)
  {
    mem.memory[i] = dataMemory[i];
  }
}

unsigned char* VectorProcessor::getDataMemory()
{
  return mem.memory;
}

void VectorProcessor::run(int totalInstructionsNumber)
{
  unsigned char* VectorRegisters;
  unsigned int* ScalarRegisters;
  ScalarRegisters = (unsigned int*)calloc(8, sizeof(unsigned int));
  VectorRegisters = (unsigned char*)calloc(64, sizeof(unsigned char));
  decoder.setRegisters(VectorRegisters,ScalarRegisters);
  write_back.setRegisters(VectorRegisters,ScalarRegisters);
  unsigned char* vectorPrueba1 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba1[0] = 1;
  vectorPrueba1[1] = 2;
  vectorPrueba1[2] = 3;
  vectorPrueba1[3] = 4;
  vectorPrueba1[4] = 5;
  vectorPrueba1[5] = 6;
  vectorPrueba1[6] = 7;
  vectorPrueba1[7] = 8;
  unsigned char* vectorPrueba2 = (unsigned char*)calloc(8,sizeof(unsigned char));
  vectorPrueba2[0] = 10;
  vectorPrueba2[1] = 240;
  vectorPrueba2[2] = 108;
  vectorPrueba2[3] = 99;
  vectorPrueba2[4] = 32;
  vectorPrueba2[5] = 24;
  vectorPrueba2[6] = 255;
  vectorPrueba2[7] = 100;
  //decoder.setVectorRegister(0,vectorPrueba2);
  //decoder.setVectorRegister(4,vectorPrueba1);
  //decoder.setScalarRegister(4,255);
  //decoder.setScalarRegister(5,200);
  int contador = 0;

  while(contador <= totalInstructionsNumber)
  {

    //printf("\033[22;34m+++++++++++++++++++++++++New Iteration %d++++++++++++++++++++++++++++++++\033[0m \n",contador);
    //---------------------------------------------Part of the algorithm
    fetch.run();
    fetch_decoder_register.saveRegister(fetch.Do);
    decoder.run(fetch_decoder_register.OpDo, fetch_decoder_register.FDo, fetch_decoder_register.RvgDo, fetch_decoder_register.RvsDo, fetch_decoder_register.RvpDo, fetch_decoder_register.ImmNumDo);
    decoder_execute_register.run(decoder.DoVA,decoder.DoVB,decoder.DoSA,decoder.DoSB,decoder.OpDout,decoder.Imm,decoder.RgDecoOut);
    execute.run(decoder_execute_register.OpDout,decoder_execute_register.DoVA,decoder_execute_register.DoVB,decoder_execute_register.DoSA,decoder_execute_register.DoSB, decoder_execute_register.ImmOut, decoder_execute_register.RgOut);
    register_exe_mem.run(execute.result,execute.DinMD,execute.resultScalar,execute.AddrA, execute.RgOutExe, execute.selData, execute.selRegType, execute.selWriteMem);
    mem.run(register_exe_mem.DoDinMD,register_exe_mem.Doresult,register_exe_mem.DoAddrA,register_exe_mem.DoresultScalar,register_exe_mem.RgOut, register_exe_mem.selDataOut,register_exe_mem.selRegTypeOut, register_exe_mem.selWriteMemOut, contador);
    register_mem_wb.run(mem.Do,mem.Alu_result,mem.RgOutMemory,mem.AluResultScalar, mem.selData, mem.selRegType, mem.selWriteMem);
    write_back.run(register_mem_wb.DoDataMemoryOut,register_mem_wb.AluResultOut,register_mem_wb.AluResultScalarOut,register_mem_wb.RgOut,register_mem_wb.selDataOut,register_mem_wb.selRegTypeOut,register_mem_wb.selWriteMemOut ,contador);


    //-----------------Prints--------------
    /*this->printValues();
    */
    //-----------------Change Registers
    //usleep(1000000);
    this->refreshRegisters();
    //-----------------Others
    contador = contador + 1;
    //mem.printMemoryDecimalValues(1);
  }
  printf("---------------Finished! Image Ready-----------------------------\n");
}


void VectorProcessor::printValues()
{
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
}
