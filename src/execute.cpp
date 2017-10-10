#include "execute.h"

Execute::Execute()
{
	result = (unsigned char*)calloc(SIZE_OF_RESULT_BYTES,sizeof(unsigned char));
	DinMD = (unsigned char*)calloc(SIZE_OF_RESULT_BYTES,sizeof(unsigned char));
}

void Execute::run(short OpCode, unsigned char * DoVA, unsigned char * DoVB, int DoSA, int DoSB, int ImmNew, short RgNew)
{
  printf("ScalarA:  %d\n",DoSA);
  printf("ScalarB:  %d\n",DoSB);

   printf("vectorPrueba1 VA: ");
  for (int i = 0; i < 8; ++i)
  {
   printf("%d ",DoVA[i]);
  }
  printf("\nvectorPrueba2 DoVB: ");
  for (int i = 0; i < 8; ++i)
  {
    printf("%d ",DoVB[i]);
  }
   printf("\n");
	DinMD = DoVB;
	AddrA = DoSA;
	this->RgOutExe = RgNew;
	this->Imm = ImmNew;
	this->OpDoSA = DoSA;
	this->controlLogic(OpCode);


	switch(OpCode)
	{
		case 0:
			printf("Adding vectors\n");
			this->sumV(DoVA,DoVB);
			break;
		case 1:
			printf("Substracting vectors\n");
			this->subV(DoVA,DoVB);
			break;
		case 2:
			printf("Adding vector-scalar\n");
			this->sumVS(DoVB,DoSA);
			break;
		case 3:
			printf("Substracting vector-scalar\n");
			this->subVS(DoVB,DoSA);
			break;
		case 4:
			printf("XOR vector-scalar\n");
			this->xxor(DoVB,DoSA);
			break;
		case 5:
			printf("Adding scalars\n");
			this->sumS(DoSA,DoSB);
			break;
		case 6:
			printf("Substracting scalars\n");
			this->subS(DoSA,DoSB);
			break;
		case 7:
			printf("Storing vector scalars\n");
			this->result = DoVB;
			break;
		case 9:
			printf("Loading vector \n");
			this->result = DoVB;
			break;
		case 11:
			printf("Moving scalar\n");
			this->sumS(0,ImmNew);
			break;
		case 12:
			printf("Doing shift left vector-scalar\n");
			this->shfl(DoVA,ImmNew);
			break;
		case 13:
			printf("Doing shift rigth vector-scalar\n");
			this->shfr(DoVA,ImmNew);
			break;
		case 14:
			printf("Doing shift left circular vector-scalar\n");
			this->shflc(DoVA,ImmNew);
			break;
		case 15:
			printf("Doing shift rigth circular vector-scalar\n");
			this->shfrc(DoVA,ImmNew);
			break;
		default:
			printf("Not using Alus");
	}

}

void Execute::controlLogic(int OpCode)
{
	if (OpCode == -1){
		 	this->selData = 0;
			this->selWriteMem = false;
	}//Los Store
	else if((OpCode == 7) || (OpCode == 8))
	{
		this->selData = 1;
		this->selWriteMem = true;
	}//Los Loads
	else if((OpCode == 9) | (OpCode == 10))
	{
		this->selData = 2;
		this->selWriteMem = false;
	}
	else
	{//Todos los demas
		this->selData = 1;
		this->selWriteMem = false;
	}

	if((OpCode == 5) || (OpCode == 6) || (OpCode == 10) || (OpCode == 11))
	{
		//0 is Scalar
			this->selRegType = false;
	}
	else
	{ //1 is Vecctor
		this->selRegType = true;
	}
}

unsigned char* Execute::sumVS(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.sum(vector1[0],data2);
	result[1] = alu1.sum(vector1[1],data2);
	result[2] = alu2.sum(vector1[2],data2);
	result[3] = alu3.sum(vector1[3],data2);
	result[4] = alu4.sum(vector1[4],data2);
	result[5] = alu5.sum(vector1[5],data2);
	result[6] = alu6.sum(vector1[6],data2);
	result[7] = alu7.sum(vector1[7],data2);
	return result;
}

unsigned char* Execute::subVS(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.sub(vector1[0],data2);
	result[1] = alu1.sub(vector1[1],data2);
	result[2] = alu2.sub(vector1[2],data2);
	result[3] = alu3.sub(vector1[3],data2);
	result[4] = alu4.sub(vector1[4],data2);
	result[5] = alu5.sub(vector1[5],data2);
	result[6] = alu6.sub(vector1[6],data2);
	result[7] = alu7.sub(vector1[7],data2);
	return result;
}

unsigned char* Execute::sumV(unsigned char* vector1, unsigned char* vector2){
	result[0] = alu0.sum(vector1[0],vector2[0]);
	result[1] = alu1.sum(vector1[1],vector2[1]);
	result[2] = alu2.sum(vector1[2],vector2[2]);
	result[3] = alu3.sum(vector1[3],vector2[3]);
	result[4] = alu4.sum(vector1[4],vector2[4]);
	result[5] = alu5.sum(vector1[5],vector2[5]);
	result[6] = alu6.sum(vector1[6],vector2[6]);
	result[7] = alu7.sum(vector1[7],vector2[7]);
	return result;
}

unsigned char* Execute::subV(unsigned char* vector1, unsigned char* vector2){
	result[0] = alu0.sub(vector1[0],vector2[0]);
	result[1] = alu1.sub(vector1[1],vector2[1]);
	result[2] = alu2.sub(vector1[2],vector2[2]);
	result[3] = alu3.sub(vector1[3],vector2[3]);
	result[4] = alu4.sub(vector1[4],vector2[4]);
	result[5] = alu5.sub(vector1[5],vector2[5]);
	result[6] = alu6.sub(vector1[6],vector2[6]);
	result[7] = alu7.sub(vector1[7],vector2[7]);
	return result;
}

int Execute::sumS(int dato1, int dato2){
	resultScalar =  dato1 + dato2;
	return resultScalar;
}

int Execute::subS(int dato1, int dato2){
	resultScalar =  dato1 - dato2;
	return resultScalar;
}

void Execute::printDout()
{
	printf("-----------Execute Data--------------------------------------\n");
  printf("-------------------------------------------------------------\n");
	printf("\n");
	printf("Result: %s\n",this->result);
	printf("exe.result[0]: %d\n",this->result[0]);
	printf("exe.result[1]: %d\n",this->result[1]);
	printf("exe.result[2]: %d\n",this->result[2]);
	printf("exe.result[3]: %d\n",this->result[3]);
	printf("exe.result[4]: %d\n",this->result[4]);
	printf("exe.result[5]: %d\n",this->result[5]);
	printf("exe.result[6]: %d\n",this->result[6]);
	printf("exe.result[7]: %d\n",this->result[7]);
	printf("Result Escalar: %d\n",resultScalar);
	printf("DinMD: %s\n",this->DinMD);
	printf("DinMD[0]: %d\n",this->DinMD[0]);
	printf("DinMD[1]: %d\n",this->DinMD[1]);
	printf("DinMD[2]: %d\n",this->DinMD[2]);
	printf("DinMD[3]: %d\n",this->DinMD[3]);
	printf("DinMD[4]: %d\n",this->DinMD[4]);
	printf("DinMD[5]: %d\n",this->DinMD[5]);
	printf("DinMD[6]: %d\n",this->DinMD[6]);
	printf("DinMD[7]: %d\n",this->DinMD[7]);
	printf("OpDoSA: %d\n",this->OpDoSA);
	printf("Addr: %d\n",this->AddrA);
	printf("RgOutExe: %d\n",this->RgOutExe);
	printf("selData: %d\n",this->selData);
	printf("selRegType: %d\n",this->selRegType);
	printf("selWriteMem: %d\n",this->selWriteMem);
	printf("Imm: %d\n",this->Imm);

}

unsigned char* Execute::xxor(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.xxor(vector1[0],data2);
	result[1] = alu1.xxor(vector1[1],data2);
	result[2] = alu2.xxor(vector1[2],data2);
	result[3] = alu3.xxor(vector1[3],data2);
	result[4] = alu4.xxor(vector1[4],data2);
	result[5] = alu5.xxor(vector1[5],data2);
	result[6] = alu6.xxor(vector1[6],data2);
	result[7] = alu7.xxor(vector1[7],data2);
	return result;
}

unsigned char* Execute::shfl(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.shfl(vector1[0],data2);
	result[1] = alu1.shfl(vector1[1],data2);
	result[2] = alu2.shfl(vector1[2],data2);
	result[3] = alu3.shfl(vector1[3],data2);
	result[4] = alu4.shfl(vector1[4],data2);
	result[5] = alu5.shfl(vector1[5],data2);
	result[6] = alu6.shfl(vector1[6],data2);
	result[7] = alu7.shfl(vector1[7],data2);
	return result;
}

unsigned char* Execute::shfr(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.shfr(vector1[0],data2);
	result[1] = alu1.shfr(vector1[1],data2);
	result[2] = alu2.shfr(vector1[2],data2);
	result[3] = alu3.shfr(vector1[3],data2);
	result[4] = alu4.shfr(vector1[4],data2);
	result[5] = alu5.shfr(vector1[5],data2);
	result[6] = alu6.shfr(vector1[6],data2);
	result[7] = alu7.shfr(vector1[7],data2);
	return result;
}

unsigned char* Execute::shflc(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.shflc(vector1[0],data2);
	result[1] = alu1.shflc(vector1[1],data2);
	result[2] = alu2.shflc(vector1[2],data2);
	result[3] = alu3.shflc(vector1[3],data2);
	result[4] = alu4.shflc(vector1[4],data2);
	result[5] = alu5.shflc(vector1[5],data2);
	result[6] = alu6.shflc(vector1[6],data2);
	result[7] = alu7.shflc(vector1[7],data2);
	return result;
}

unsigned char* Execute::shfrc(unsigned char* vector1, unsigned char data2){
	result[0] = alu0.shfrc(vector1[0],data2);
	result[1] = alu1.shfrc(vector1[1],data2);
	result[2] = alu2.shfrc(vector1[2],data2);
	result[3] = alu3.shfrc(vector1[3],data2);
	result[4] = alu4.shfrc(vector1[4],data2);
	result[5] = alu5.shfrc(vector1[5],data2);
	result[6] = alu6.shfrc(vector1[6],data2);
	result[7] = alu7.shfrc(vector1[7],data2);
	return result;
}
