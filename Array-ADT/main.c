#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char const *argv[])
{
    struct Array arr1 = {{-2, 9, 21, 28, 35}, 10, 5};
    struct Array arr2 = {{2, 3, 16, -18, 28}, 10, 5};
    struct Array *arr3;

    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    return 0;
}