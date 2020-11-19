#include "matrix.h"
#include <stdio.h>

void set(Matrix *m, int i, int j, int x)
{
	if (i == j)
	{
		m->A[i - 1] = x;
	}
}
int get(Matrix m, int i, int j)
{
	if (i == j)
	{
		return m.A[i - 1];
	}
}
void display(Matrix m)
{
	int i, j;
	for (i = 0; i < m.n; ++i)
	{
		for (j = 0; j < m.n; ++j)
		{
			if (i == j)
			{
				printf("%d ", m.A[i]);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}
