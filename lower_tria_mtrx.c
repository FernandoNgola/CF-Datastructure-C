#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Lower triangular matrix, is matrix which a lower part as trianular 
of matrix are non-zero and others parts are zero.
In a lower triangular matrix, only n*(n+1)/2 are non-zero and n*(n-1)/2 are.
For that case for storing these elements, we don't need a n*n of space, so we can store only
on non-zero element.
We can store in two form: row form and column form.
Example
|1 0 0 0|
|1 2 0 0| n = 4
|1 2 3 0|  We need 4*(4+1)/2 or 10. so we create a array of 10
|1 2 3 4|  |  |  |  |  |  |  |  |  |  |  | we can store as row |1|1|2|1|2|3|1|2|3|4
			0   1  2  3  4  5  6  7  8  9  or as column |1|1|1|1|2|2|2|3|3|4. In both case we have a 
			a formula as we can see in code.
*/

typedef struct Matrix
{
    int *A;
    int n;
} Matrix;

void setRow(Matrix *m, int i, int j, int x);
int getRow(Matrix m, int i, int j);
void displayRow(Matrix m);

void setColumm(Matrix *m, int i, int j, int x);
int getColumm(Matrix m, int i, int j);
void displayColumm(Matrix m);

int main(void)
{
    srand(time(NULL));
    int i, j, x;
    Matrix m;
    printf("Generating Dimension\n");

    //scanf("%d", &m.n);
    m.n = rand() % 7 + 2;
    printf("n = %d\n", m.n);
    const int size = m.n * (m.n + 1) / 2;
    m.A = malloc(size * sizeof(int));
    //m.A = (int[size]){};//Error size deve ser um número
    printf("Generating arbitrary numbers of %dx%d: ", m.n, m.n);
    for (i = 1; i <= m.n; ++i)
    {
        for (j = 1; j <= m.n; ++j)
        {
            x = rand() % 9 + 1;
            setRow(&m, i, j, x);
        }
    }
    printf("\n");
    displayRow(m);
    return 0;
}

void setRow(Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}

int getRow(Matrix m, int i, int j)
{
    int index = i * (i - 1) / 2 + (j - 1);
    if (i >= j)
    {
        return m.A[index];
    }
    else
    {
        return 0;
    }
}

void displayRow(Matrix m)
{
    for (int i = 1; i <= m.n; ++i)
    {
        for (int j = 1; j <= m.n; ++j)
        {
            if (i >= j)
            {
                printf("%d ", m.A[i * (i - 1) / 2 + (j - 1)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void setColumm(Matrix *m, int i, int j, int x)
{
    int index = (m->n * (j - 1) + (j - 2) * (j - 1) / 2) + (i - j);
    if (i >= j)
    {
        m->A[index] = x;
    }
}

int getColumm(Matrix m, int i, int j)
{
    int index = (m.n * (j - 1) + (j - 2) * (j - 1) / 2) + (i - j);

    if (i >= j)
    {
        return m.A[index];
    }
    else
    {
        return 0;
    }
}

void displayColumm(Matrix m)
{

    for (int i = 1; i <= m.n; ++i)
    {
        for (int j = 1; j <= m.n; ++j)
        {
            if (i >= j)
            {
                printf("%d ", m.A[(m.n * (j - 1) + (j - 2) * (j - 1) / 2) + (i - j)]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}