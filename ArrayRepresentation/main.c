#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char const *argv[])
{
	/*	int A[5];
	int B[5]  = {1, 2, 3, 4, 5};
	int C[10] = {2, 4, 6};
	int D[5] = {0};
	int E[] = {1, 2, 3, 4, 5, 6};
	for (int i = 0; i < 5; ++i)
	{
		printf("%u\n", &A[i]);
	}
	*/

	/*int *p, *q;
	p = (int *)malloc(5*sizeof(int));
	p[0] = 3; p[1] = 5; p[2] = 7; 
	p[3] = 9; p[4] = 11; 

	q = (int *)malloc(10*sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		q[i] = p[i];
	}
	free(p);
	p = q;
	q = NULL;
	for (int i = 0; i < 5; ++i)
	{
		fprintf(stdout, "%d ", p[i]);
	}
	fprintf(stdout, "\n" );
*/
	//Neste momento a q não está disponível. Erro
	/*for (int i = 0; i < 5; ++i)
	{
		fprintf(stdout, "%d", q[i]);
	}*/

	array_2d_full_stack();
	array_2d_partial_stack_heap();
	array_2d_full_heap();
	return 0;
}