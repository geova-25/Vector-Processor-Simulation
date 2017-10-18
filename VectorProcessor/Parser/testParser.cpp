#include <stdio.h>
#include "parser.h"
#include <stdlib.h>
#include <string>

using namespace std;

void unitTest_Traslate()
{
  Parser parser;
  parser.traslateFromAssembly("./Assembly_Codes/myCode.txt");
}

int main()
{
  unitTest_Traslate();
}
