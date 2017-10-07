#include "vectorProcessor.h"

VectorProcessor::VectorProcessor()
{

}


void VectorProcessor::refreshRegisters()
{
  this->fetch_decoder_register.changeOutPutRegisters();
}

void VectorProcessor::setInstructionMemory(string* instructionMemory)
{
  instructionMemory = fetch.getInstructionMemory();
}

void VectorProcessor::setDataMemory(unsigned char* dataMemory)
{
  //dataMemory = fetch.getInstructionMemory();
}



void VectorProcessor::run()
{
  
  string* instructionMemory;
  instructionMemory = fetch.getInstructionMemory();

  for (int i = 0; i < 4; ++i)
  {
    instructionMemory[i] = '0';
  }
  for (int i = 4; i < 6; ++i)
  {
    instructionMemory[i] = '1';
  }
  for (int i = 6; i < 8; ++i)
  {
    instructionMemory[i] = '0';
  }
  for (int i = 8; i < 12; ++i)
  {
    instructionMemory[i] = '1';
  }
  for (int i = 12; i < 32; ++i)
  {
    instructionMemory[i] = '1';
  }
  //printf("Do Instruction Memory: ");
  fetch.run();
  /*int contador = 0;
  while(contador <= 60){
    fetch.run();
    for (int i = 0; i < 32; ++i)
    {
        printf("%c",fetch.Do[i]);
    }
    printf("\n");
    //usleep(1000000);
    contador = contador + 1;
  }*/
  //this->fetchDecoderRegister(fetch.Do);
}