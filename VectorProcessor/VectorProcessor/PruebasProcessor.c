
/*

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
/-------------------------------1 Store Vector---------------------

//                       OP|F|Rg|Rs|Rp|
//StrV R5 Rv2
instructionMemory[0] = "01110000010101000000000000000000";


//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
/-------------------------------2 Store Vector Seguidos------------

//                       OP|F|Rg|Rs|Rp|
//StrV R5 Rv2
instructionMemory[0] = "01110000010101000000000000000000";

//                       OP|F|Rg|Rs|Rp|
//StrV R3 Rv3
instructionMemory[1] = "01110000001101100000000000000000";




//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//------------------------------1 Load-----------------------------

//LDV R6 R1
//                       OP|F|Rg|Rs|Rp|
instructionMemory[0] = "10010011000101000000000000000000";


//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//------------------------------2 Loads Seguidos-------------------

//Carga en RV6 el dato en la direccion R1 (Verificar que haya algo en esa direccion primero)

//LDV R6 R1
//                       OP|F|Rg|Rs|Rp|
instructionMemory[0] = "10010011000101000000000000000000";

//Carga en RV7 el dato en la direccion R2 (Verificar que haya algo en esa direccion primero

//LDV R7 R2
//                       OP|F|Rg|Rs|Rp|
instructionMemory[1] = "10010011101001000000000000000000";


//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//------------------------------2 Loads con 2 Store Seguidos-------

//Guarda en la memoria en la posicion de R5 lo que halla en el registro Rv2
//                       OP|F|Rg|Rs|Rp|
//StrV R5 Rv2
instructionMemory[0] = "01110000010101000000000000000000";

//Guarda en la memoria en la posicion de R3 lo que halla en el registro Rv3
//                       OP|F|Rg|Rs|Rp|
//StrV R3 Rv3
instructionMemory[1] = "01110000001101100000000000000000";

//Carga en RV6 el dato en la direccion R5 (Verificar que haya algo en esa direccion primero)

//LDV R6 R5
//                       OP|F|Rg|Rs|Rp|
instructionMemory[2] = "10010010010101000000000000000000";

//Carga en RV7 el dato en la direccion R3 (Verificar que haya algo en esa direccion primero

//LDV R7 R3
//                       OP|F|Rg|Rs|Rp|
instructionMemory[3] = "10010010101101000000000000000000";

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//------------------------------3 Movs  Seguidos-------------------

//Guarda en el Registro R3 el dato 5

//Mov R3 5
//                       OP|F|Rg|Rs|imm                |
instructionMemory[0] = "10110001100000000000000000000101";

//Guarda en el Registro R6 el dato 19

//Mov R6 19
//                       OP|F|Rg|Rs|imm                 |
instructionMemory[1] = "101100110000000000000000000100111";

//Guarda en el Registro R7 el dato 524293

//Mov R7 524293
//                       OP|F|Rg|Rs|imm                |
instructionMemory[2] = "10110011100010000000000000000101";

//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//------------------------------Xor--------------------------------


//Aplica un Xor de R3 con R2
//Xor R6 R3 R2
//                       OP|F|Rg|Rs|Rp|
instructionMemory[0] = "01000011001101000000000000000000";



//-----------------------------------------------------------------
//-----------------------------------------------------------------
//------------------------------SUMS-------------------------------


//Aplica un SumS de R3 con R2
//Sums R7 R1 R5
//                       OP|F|Rg|Rs|Rp|
instructionMemory[0] = "01010011100110100000000000000000";


Total XOR code

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
*/




*/
