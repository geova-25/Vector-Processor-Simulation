#include "parser.h"

Parser::Parser(string nameOfFile)
{
  this->quantity_of_duplications = 6554;
  this->quantity_of_structions = 33;
  this->initInstructionsReplication = 9;
  this->totalInstructionsNumber = this->quantity_of_structions * this->quantity_of_duplications;
  this->instructions = new string[this->quantity_of_structions * this->quantity_of_duplications];

  //ifstream infile("SUMASIMPLE.txt");
  ifstream infile(nameOfFile);
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
    std::cout << counter << ": " << a << '\n';
    counter++;
  }
}

Parser::Parser()
{
  this->quantity_of_duplications = 6554;
  this->quantity_of_structions = 33;
  this->initInstructionsReplication = 9;
  this->totalInstructionsNumber = this->quantity_of_structions * this->quantity_of_duplications;
  this->instructions = new string[this->quantity_of_structions * this->quantity_of_duplications];

  ifstream infile("SUMASIMPLE.txt");
  //ifstream infile(nameOfFile);
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


void Parser::traslateFromAssembly(string nameOfFile)
{
  ifstream infile(nameOfFile);
  string stringActual0;
  string stringActual1;
  string stringActual2;
  string stringActual3;
  string test, test1;
  getline(infile,test);
  std::cout << "Line: " << test  << '\n';

  istringstream iss(test);
  //iss >> test1;
  //std::cout << test1 << '\n';
  //iss >> test1;
  //std::cout << test1 << '\n';

  string nemonic;
  string opCode;
  string F;
  string op1;
  string op2;
  string op3;
  string imm;
  string imm2;
  string newInstruction;
  string finalInstruction = "";
  int opCodeDecimal = 0;
  bool first = true;
  while(getline(infile,test))
  {
    //std::cout << "---------------------------Line: " << test  << '\n';
    istringstream line(test);
    line >> nemonic;
    opCode = getOpCodeString(nemonic);
    F = getFCodeString(nemonic);
    line >> nemonic;
    op1 = getOperand(nemonic);
    line >> nemonic;
    imm = getImm(nemonic);
    op2 = getOperand(nemonic);
    line >> nemonic;
    imm2 = getImm(nemonic);
    op3 = getOperand(nemonic);

    /*std::cout << "opCode: " << opCode << '\n';
    std::cout << "F: "    << F << '\n';
    std::cout << "op1: "  << op1 << '\n';
    std::cout << "op2: "  << op2 << '\n';
    std::cout << "op3: "  << op3 << '\n';
    std::cout << "imm: "  << imm << '\n';
    std::cout << "imm2: " << imm2 << '\n';
    */
    opCodeDecimal = stoi(opCode,nullptr,2);
    newInstruction = unifyInstruction(opCodeDecimal, opCode, F, op1, op2, op3, imm, imm2 );
    std::cout << "newInstruction: " << newInstruction <<'\n';
    std::cout << "newInstruction length: " << newInstruction.length() <<'\n';
    if(!first)
    {
      finalInstruction.append("\n");
      finalInstruction.append(newInstruction);
    }
    else finalInstruction.append(newInstruction);
    first = false;
  }
    ofstream out(OUT_FILE_BINARY_CODE);
    out << finalInstruction;
}

string Parser::unifyInstruction(int opCodeDecimal, string opCode, string F, string op1, string op2 , string op3, string imm, string imm2)
{
  string completeInstruction = opCode;
  completeInstruction.append(F);
  if(opCodeDecimal == 7 || opCodeDecimal == 8 || opCodeDecimal == 9 || opCodeDecimal == 10)
  {
    completeInstruction.append(op1);
    completeInstruction.append(op2);
    completeInstruction.append(20,'0');
  }
  else if(opCodeDecimal == 11)
  {
    completeInstruction.append(op1);
    completeInstruction.append(3,'0');
    completeInstruction.append(imm);
  }
  else if(opCodeDecimal == 12 || opCodeDecimal == 13 || opCodeDecimal == 14 || opCodeDecimal == 15)
  {
    completeInstruction.append(op1);
    completeInstruction.append(op2);
    completeInstruction.append(imm2);
  }
  else
  {
    completeInstruction.append(op1);
    completeInstruction.append(op2);
    completeInstruction.append(op3);
    completeInstruction.append(17,'0');
  }
  return completeInstruction;
}

string Parser::getOperand(string op)
{
  string operand;
  if(strcasecmp((char*)op.c_str(),"R0") == 0) operand = "000";
  else if(strcasecmp((char*)op.c_str(),"R1")   == 0) operand = "001"; //1
  else if(strcasecmp((char*)op.c_str(),"R2")  == 0)  operand = "010"; //2
  else if(strcasecmp((char*)op.c_str(),"R3")  == 0)  operand = "011"; //3
  else if(strcasecmp((char*)op.c_str(),"R4")  == 0)  operand = "100"; //4
  else if(strcasecmp((char*)op.c_str(),"R5")   == 0) operand = "101"; //5
  else if(strcasecmp((char*)op.c_str(),"R6")   == 0) operand = "110"; //6
  else if(strcasecmp((char*)op.c_str(),"R7")   == 0) operand = "111"; //7
  else
  {
    operand = "000";
    //  printf("Error wrong operand\n");
  }
  return operand;
}

string Parser::getOpCodeString(string nemonic)
{
  string opCode;
  if(strcasecmp((char*)nemonic.c_str(),"SUMV") == 0) opCode = "0000";
  else if(strcasecmp((char*)nemonic.c_str(),"SUBV")   == 0) opCode = "0001"; //1
  else if(strcasecmp((char*)nemonic.c_str(),"SUMVS")  == 0) opCode = "0010"; //2
  else if(strcasecmp((char*)nemonic.c_str(),"SUBVS")  == 0) opCode = "0011"; //3
  else if(strcasecmp((char*)nemonic.c_str(),"XORVS")  == 0) opCode = "0100"; //4
  else if(strcasecmp((char*)nemonic.c_str(),"SUMS")   == 0) opCode = "0101"; //5
  else if(strcasecmp((char*)nemonic.c_str(),"SUBS")   == 0) opCode = "0110"; //6
  else if(strcasecmp((char*)nemonic.c_str(),"STRV")   == 0) opCode = "0111"; //7
  else if(strcasecmp((char*)nemonic.c_str(),"STRS")   == 0) opCode = "1000"; //8
  else if(strcasecmp((char*)nemonic.c_str(),"LDV")    == 0) opCode = "1001"; //9
  else if(strcasecmp((char*)nemonic.c_str(),"LDS")    == 0) opCode = "1010"; //10
  else if(strcasecmp((char*)nemonic.c_str(),"MOVS")   == 0) opCode = "1011"; //11
  else if(strcasecmp((char*)nemonic.c_str(),"SHFLF")  == 0) opCode = "1100"; //12
  else if(strcasecmp((char*)nemonic.c_str(),"SHFRG")  == 0) opCode = "1101"; //13
  else if(strcasecmp((char*)nemonic.c_str(),"SHFCLF") == 0) opCode = "1110"; //14
  else if(strcasecmp((char*)nemonic.c_str(),"SHFCRG") == 0) opCode = "1111"; //15
  else
  {
    opCode = "0000";
    //printf("Error wrong nemonic\n");
  }
  return opCode;
}

string Parser::getImm(string number)
{
  string binaryNumber;
  try
  {
    int decimalNumber = stoi(number,nullptr,10);
    binaryNumber = bitset<20>(decimalNumber).to_string();
  }
  catch(...)
  {
    binaryNumber = "00000000000000000000";
  }
  return binaryNumber;
}

string Parser::getFCodeString(string nemonic)
{
  string F;
  if(strcasecmp((char*)nemonic.c_str(),"SUMV") == 0) F = "00";
  else if(strcasecmp((char*)nemonic.c_str(),"SUBV")   == 0) F = "00"; //1
  else if(strcasecmp((char*)nemonic.c_str(),"SUMVS")  == 0) F = "00"; //2
  else if(strcasecmp((char*)nemonic.c_str(),"SUBVS")  == 0) F = "00"; //3
  else if(strcasecmp((char*)nemonic.c_str(),"XORVS")  == 0) F = "00"; //4
  else if(strcasecmp((char*)nemonic.c_str(),"SUMS")   == 0) F = "00"; //5
  else if(strcasecmp((char*)nemonic.c_str(),"SUBS")   == 0) F = "00"; //6
  else if(strcasecmp((char*)nemonic.c_str(),"STRV")   == 0) F = "01"; //7
  else if(strcasecmp((char*)nemonic.c_str(),"STRS")   == 0) F = "01"; //8
  else if(strcasecmp((char*)nemonic.c_str(),"LDV")    == 0) F = "01"; //9
  else if(strcasecmp((char*)nemonic.c_str(),"LDS")    == 0) F = "01"; //10
  else if(strcasecmp((char*)nemonic.c_str(),"MOVS")   == 0) F = "10"; //11
  else if(strcasecmp((char*)nemonic.c_str(),"SHFLF")  == 0) F = "10"; //12
  else if(strcasecmp((char*)nemonic.c_str(),"SHFRG")  == 0) F = "10"; //13
  else if(strcasecmp((char*)nemonic.c_str(),"SHFCLF") == 0) F = "10"; //14
  else if(strcasecmp((char*)nemonic.c_str(),"SHFCRG") == 0) F = "10"; //15
  else
  {
    F = "0000";
    printf("Error wrong nemonic\n");
  }
  return F;
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

  ofstream out(OUT_FILE_DUPLICATED_BINARY_CODE);
  for (int i = 0; i < totalInstructionsNumber; i++) {
    out << instructions[i];
    out << "\n";
  }
}
