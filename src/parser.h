#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <strings.h>
#include <bitset>

using namespace std;

#define OUT_FILE_BINARY_CODE "./BinaryParsedCodes/newParse.txt"
#define OUT_FILE_DUPLICATED_BINARY_CODE "./Duplicated_Code/newDuplication.txt"

class Parser
{
  public:
    Parser(string nameOfFile);
    Parser();
    string* instructions;
    void parse();
    void duplicate(string* binaryNoDuplicatedInstructions, int times);
    int totalInstructionsNumber;
    void traslateFromAssembly(string nameOfFile);
    string getOpCodeString(string nemonic);
    string getOperand(string op);
    string getFCodeString(string nemonic);
    string getImm(string number);
    string unifyInstruction(int opCodeDecimal, string opCode, string F, string op1, string op2 , string op3, string imm, string imm2);
  private:
    int quantity_of_structions;
    int quantity_of_duplications;
    int initInstructionsReplication;
    void printDuplications();
    void printInstructions();

    //void duplicate(char* binaryNoDuplicatedInstructions);
};
