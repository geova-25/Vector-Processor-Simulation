#include "parser.h"

Parser::Parser()
{
  this->quantity_of_duplications = 6554;
  this->quantity_of_structions = 33;
  this->initInstructionsReplication = 9;
  this->totalInstructionsNumber = this->quantity_of_structions * this->quantity_of_duplications;
  this->instructions = new string[this->quantity_of_structions * this->quantity_of_duplications];

  //ifstream infile("SUMASIMPLE.txt");
  ifstream infile("DESENCRIPTACIONSUMASIMPLE.txt");
  //ifstream infile("SHFCLF5.txt");
  //ifstream infile("SHFCRG5.txt");
  //ifstream infile("SHFLF1.txt");
  //ifstream infile("SHFRG1.txt");
  //ifstream infile("XOR.txt");
  string a;
  int counter = 0;
  while (infile >> a)
  {
    instructions[counter] = a;
    //std::cout << counter << ": " << a << '\n';
    counter++;
  }
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

  ofstream out("DuplicatedCode.txt");
  for (int i = 0; i < totalInstructionsNumber; i++) {
    out << instructions[i];
    out << "\n";
  }
  //FILE *fp;
  //fp = fopen("DuplicatedCode.txt", "w"); //If not exist then creates it
  //fputs((char*)this->instructions[1],fp);
}
