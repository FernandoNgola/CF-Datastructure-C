#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Matrix
{
    int *A;
    int n;
} Matrix;

void Create(Matrix *mtx);
void SetRow(Matrix *m, int i, int j, int x);
int GetRow(Matrix m, int i, int j);
void DisplayRow(Matrix m);

void SetColumn(Matrix *m, int i, int j, int x);
int GetColumn(Matrix m, int i, int j);
void DisplayColumn(Matrix m);
void Delete(Matrix *mtx);

int main(void)
{
    srand(time(NULL));
    Matrix m;
    Create(&m);
    printf("\n");
    DisplayRow(m);
    //Delete(&m);
    return 0;
}

void SetRow(Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        m->A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}

int GetRow(Matrix m, int i, int j)
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

void DisplayRow(Matrix m)
{
    for (int i = 1; i < m.n; ++i)
    {
        for (int j = 1; j < m.n; ++j)
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

void SetColumn(Matrix *m, int i, int j, int x)
{
    int index = (m->n * (j - 1) + (j - 2) * (j - 1) / 2) + (i - j);
    if (i >= j)
    {
        m->A[index] = x;
    }
}

int GetColumn(Matrix m, int i, int j)
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

void DisplayColumn(Matrix m)
{

    for (int i = 1; i < m.n; ++i)
    {
        for (int j = 1; j < m.n; ++j)
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

void Create(Matrix *mtx)
{
    printf("Enter Dimension\n");

    //scanf("%d", &m.n);
    mtx->n = (rand() % 7) + 2;
    printf("n = %d\n", mtx->n);
    const int size = mtx->n * (mtx->n + 1) / 2;
    // mtx->A = malloc(size * sizeof(int));
    mtx->A = calloc(size, sizeof(int));
    //m.A = (int[size]){};//Error size deve ser um número
    printf("Generating arbitrary numbers: ");
    for (int i = 1; i < mtx->n; ++i)
    {
        for (int j = 0; j < mtx->n; ++j)
        {
            SetRow(mtx, i, j, ((rand() % 9) + 1));
        }
    }
}

void Delete(Matrix *mtx)
{
    free(mtx->A);
}