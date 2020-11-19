#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct matrix
{
    int *A;
    int size;
} matrix;

void create(matrix *mtx);
void set(matrix *mtx, int i, int j, int value);
int get(matrix mtx, int i, int j);
void display(matrix mtx);

int main(int argc, char const *argv[])
{
    matrix mtx;
    create(&mtx);
    display(mtx);
    printf("Element at [1, 1] = %d\n", get(mtx, 1, 1));
    printf("Element at [2, 2] = %d\n", get(mtx, 2, 2));
    printf("Element at [3, 3] = %d\n", get(mtx, 3, 3));

    return 0;
}

void create(matrix *mtx)
{
    srand(time(NULL));
    printf("Generating size: ");
    mtx->size = rand() % 7 + 2;
    printf("Size is %d\n", mtx->size);
    mtx->A = malloc(mtx->size * sizeof(int));
    printf("Generating elements of matrix; size %dx%d\n", mtx->size, mtx->size);
    for (size_t i = 1; i <= mtx->size; i++)
    {
        for (size_t j = 1; j <= mtx->size; j++)
        {
            set(mtx, i, j, (rand() % 8 + 1));
        }
    }
}
void set(matrix *mtx, int i, int j, int value)
{
    if (i == j)
    {
        mtx->A[i - 1] = value;
    }
}
int get(matrix mtx, int i, int j)
{
    if (i == j)
    {
        return mtx.A[i - 1];
    }
    else
    {
        return 0;
    }
}
void display(matrix mtx)
{
    for (size_t i = 1; i <= mtx.size; i++)
    {
        for (size_t j = 1; j <= mtx.size; j++)
        {
            if (i == j)
            {
                printf("%d ", mtx.A[i - 1]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}