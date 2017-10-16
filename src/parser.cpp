#include "parser.h"

Parser::Parser()
{
  this->quantity_of_duplications = 2500;
  this->quantity_of_structions = 36;
  this->initInstructionsReplication = 9;
  this->totalInstructionsNumber = this->quantity_of_structions * this->quantity_of_duplications;
  this->instructions = new string[this->quantity_of_structions * this->quantity_of_duplications];
  /*this->instructions[0] = "HolaA";
  this->instructions[1] = "HolaB";
  this->instructions[2] = "HolaC";
  this->instructions[3] = "HolaD";
  this->instructions[4] = "HolaE";
  this->instructions[5] = "HolaF";
  this->instructions[6] = "HolaG";
  this->instructions[7] = "HolaH";
  this->instructions[8] = "HolaI";
  */

  //Mov R0 35 llave
  //                       OP|F|Rg|Rs|imm                |
  instructions[0] = "11111111111111111111111111111111";

  //Mov R0 35 llave
  //                       OP|F|Rg|Rs|imm                |
  instructions[1] = "10110000000000000000000000100011";
  //Mov R1 0
  //                       OP|F|Rg|Rs|imm                |
  instructions[2] = "10110000100000000000000000000000";
  //Mov R2 8
  //                       OP|F|Rg|Rs|imm                |
  instructions[3] = "10110001000000000000000000001000";
  //Mov R3 16
  //                       OP|F|Rg|Rs|imm                |
  instructions[4] = "10110001100000000000000000010000";
  //Mov R4 24
  //                       OP|F|Rg|Rs|imm                |
  instructions[5] = "10110010000000000000000000011000";
  //Mov R5 32
  //                       OP|F|Rg|Rs|imm                |
  instructions[6] = "10110010100000000000000000100000";
  //Mov R6 40
  //                       OP|F|Rg|Rs|imm                |
  instructions[7] = "10110011000000000000000000101000";
  //Mov R7 48
  //                       OP|F|Rg|Rs|imm                |
  instructions[8] = "10110011100000000000000000110000";

  //--------------------------------------LOADSS---------------------


  //LDV R1 R1
  //                      |OP|F|Rg|Rs|
  instructions[9] = "10010000100100000000000000000000";

  //LDV R2 R2
  //                       |OP|F|Rg|Rs|Rp|
  instructions[10] = "10010001001000000000000000000000";

  //LDV R3 R3
  //                       |OP|F|Rg|Rs|Rp|
  instructions[11] = "10010001101100000000000000000000";

  //LDV R4 R4
  //                       |OP|F|Rg|Rs|Rp|
  instructions[12] = "10010110010000000000000000000000";

  //LDV R5 R5
  //                       |OP|F|Rg|Rs|Rp|
  instructions[13] = "10010110110100000000000000000000";

  //LDV R6 R6
  //                       |OP|F|Rg|Rs|Rp|
  instructions[14] = "10010111011000000000000000000000";




  //--------------------------------------XOR---------------------

  //Aplica un Xor de RS0 con R1
  //Xor R1 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[15] = "01000000100000100000000000000000";

  //Aplica un Xor de RS0 con R2
  //Xor R2 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[16] = "01000001000001000000000000000000";

  //Aplica un Xor de RS0 con R3
  //Xor R3 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[17] = "01000001100001100000000000000000";

  //Aplica un Xor de RS0 con R4
  //Xor R4 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[18] = "01000010000010000000000000000000";

  //Aplica un Xor de RS0 con R5
  //Xor R5 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[19] = "01000010100010100000000000000000";

  //Aplica un Xor de RS0 con R6
  //Xor R6 R0 R1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[20] = "01000011000011000000000000000000";


  //--------------------------------------STR---------------------




  //StrV R1 Rv1
  //                       |OP|F|Rg|Rs|Rp|
  instructions[21] = "01110000000100100000000000000000";

  //StrV R2 Rv2
  //                       |OP|F|Rg|Rs|Rp|
  instructions[22] = "01110000001001000000000000000000";

  //StrV R3 Rv3
  //                       |OP|F|Rg|Rs|Rp|
  instructions[23] = "01110000001101100000000000000000";

  //StrV R4 Rv4
  //                       |OP|F|Rg|Rs|Rp|
  instructions[24] = "01110000010010000000000000000000";

  //StrV R5 Rv5
  //                       |OP|F|Rg|Rs|Rp|
  instructions[25] = "01110000010110100000000000000000";

  //StrV R6 Rv6
  //                       |OP|F|Rg|Rs|Rp|
  instructions[26] = "01110000011011000000000000000000";



  //--------------------------------------SUMS---------------------

  //Aplica un SumS de R1 con R7
  //Sums R1 R1 R7
  //                      |OP|F|Rg|Rs|Rp|
  instructions[27] = "01010000100111100000000000000000";

  //Aplica un SumS de R2 con R7
  //Sums R2 R2 R7
  //                       OP|F|Rg|Rs|Rp|
  instructions[28] = "01010001001011100000000000000000";


  //Aplica un SumS de R3 con R7
  //Sums R3 R3 R7
  //                       OP|F|Rg|Rs|Rp|
  instructions[29] = "01010001101111100000000000000000";


  //Aplica un SumS de R4 con R7
  //Sums R4 R4 R7
  //                       OP|F|Rg|Rs|Rp|
  instructions[30] = "01010010010011100000000000000000";


  //Aplica un SumS de R5 con R7
  //Sums R5 R5 R7
  //                       OP|F|Rg|Rs|Rp|
  instructions[31] = "01010010110111100000000000000000";

  //Aplica un SumS de R6 con R7
  //Sums R6 R6 R7
  //                       OP|F|Rg|Rs|Rp|
  instructions[32] = "01010011011011100000000000000000";
}

void Parser::parse()
{
  //printInstructions();
  duplicate(this->instructions,this->quantity_of_duplications);
  //printDuplications();
}

void Parser::printInstructions()
{
  for (int i = 0; i < this->quantity_of_structions; i++)
  {
    printf("%d: ",i);
    std::cout << this->instructions[i] << '\n';
  }
}

void Parser::printDuplications()
{
  std::cout << "Duplicating the instructions" << '\n';
  std::cout << "Quantity of instructions original: " << this->quantity_of_structions  << '\n';
  std::cout << "Quantity of duplications: " << this->quantity_of_duplications  << '\n';
  std::cout << "Quantity of instructions total: "    << this->quantity_of_structions*this->quantity_of_duplications << '\n';
  int dup = 1;
  for (int i = 0; i < this->quantity_of_duplications * this->quantity_of_structions; i++) {
    if(i % this->quantity_of_structions  == 0)
    {
      std::cout << "New Duplication:"<< dup << '\n';
      dup++;
    }
    printf("%d: ", i);
    std::cout << this->instructions[i] << '\n';
  }
}


void Parser::duplicate(string* binaryNoDuplicatedInstructions, int times)
{
  int i = initInstructionsReplication;
  for (int j =this->quantity_of_structions; j < this->quantity_of_structions*times; j++)
  {
    this->instructions[j] = binaryNoDuplicatedInstructions[i];
    if(i==this->quantity_of_structions - 1)
    {
      i = initInstructionsReplication;
    }
    else
    {
      i++;
    }
  }
}
