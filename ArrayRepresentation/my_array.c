#include <stdlib.h>
#include <stdio.h>
typedef struct my_array
{
    int *A;
    int size;
    int length;

} array;

void add(array *arr, int value)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = value;
        arr->length++;
    }
    else
    {
        fprintf(stderr, "Tamanho do array alcançado\n");
    }
}
/*Outras funcções*/
int main(void)
{
    array arr = {(int[10]){}, 10, 0};
    add(&arr, 5); //1
    add(&arr, 4); //2
    add(&arr, 3); //3
    add(&arr, 2); //4
    add(&arr, 1); //5
    add(&arr, 5); //6
    add(&arr, 4); //7
    add(&arr, 3); //8
    add(&arr, 2); //9
    add(&arr, 1); //10
    add(&arr, 1); //11 Tamanho do array alcançado
    for (size_t i = 0; i < arr.length; i++)
    {
        printf("%d \n", arr.A[i]);
    }

    return 0;
}
