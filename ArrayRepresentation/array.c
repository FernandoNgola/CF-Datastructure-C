#include <stdlib.h>
#include <stdio.h>

void array_2d_full_stack()
{
	int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {3, 5, 7, 9}};
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			fprintf(stdout, "%d ", A[i][j]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "\n");
}

void array_2d_partial_stack_heap()
{
	int *B[3];
	B[0] = (int *)malloc(4 * sizeof(int));
	B[1] = (int *)malloc(4 * sizeof(int));
	B[2] = (int *)malloc(4 * sizeof(int));
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			fprintf(stdout, "%d ", B[i][j]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "\n");
}

void array_2d_full_heap()
{

	int **C;
	C = (int **)malloc(3 * sizeof(int *));
	C[0] = (int *)malloc(4 * sizeof(int));
	C[1] = (int *)malloc(4 * sizeof(int));
	C[2] = (int *)malloc(4 * sizeof(int));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			fprintf(stdout, "%d ", C[i][j]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "\n");
}