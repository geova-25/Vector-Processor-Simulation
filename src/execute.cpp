#include "execute.h"

Execute::Execute()
{
	result = (unsigned char*)calloc(SIZE_OF_RESULT_BYTES,sizeof(unsigned char));
}

unsigned char* Execute::sum(unsigned char* vector1, unsigned char* vector2){
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

unsigned char* Execute::sub(unsigned char* vector1, unsigned char* vector2){
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