#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class Parser
{
  public:
    Parser();
    string* instructions;
    void parse();
    void duplicate(string* binaryNoDuplicatedInstructions, int times);
    int totalInstructionsNumber;
  private:
    int quantity_of_structions;
    int quantity_of_duplications;
    int initInstructionsReplication;
    void printDuplications();
    void printInstructions();
    //void duplicate(char* binaryNoDuplicatedInstructions);
};
