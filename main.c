#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void)
{
	Matrix m;
	m.n = 4;
	Set(&m, 1, 1, 3);
	Set(&m, 2, 2, 5);
	Set(&m, 3, 3, 7);
	Set(&m, 4, 4, 9);
	printf("%d\n", Get(m, 1, 1));
	Display(m);
	return 0;
}