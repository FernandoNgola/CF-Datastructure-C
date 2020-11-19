#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int row;
    int col;
    int value;
} Element;

typedef struct SparceMatrix
{
    int rows, cols, numberOfNon_zeroElem;
    Element *ele;
} SparceMatrix;

void create(SparceMatrix *s)
{
    printf("Enter the dimensions: ");
    scanf("%d %d", &s->rows, &s->cols);
    printf("Enter number of non-zero elementes: ");
    scanf("%d", &s->numberOfNon_zeroElem);
    s->ele = malloc(s->numberOfNon_zeroElem * sizeof(Element));
    printf("Enter non-zero elements\n");
    for (size_t i = 0; i < s->numberOfNon_zeroElem; i++)
    {
        scanf("%d %d %d", &s->ele[i].row, &s->ele[i].col, &s->ele[i].value);
    }
}

void display(SparceMatrix s)
{
    int k = 0;
    for (size_t i = 0; i < s.numberOfNon_zeroElem; i++)
    {
        for (size_t j = 0; j < s.numberOfNon_zeroElem; j++)
        {
            if (i == s.ele[k].row && j == s.ele[k].col)
            {
                printf("%d ", s.ele[k++].value);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

SparceMatrix *add(SparceMatrix *s1, SparceMatrix *s2)
{
    SparceMatrix *sum;
    int i = 0, j = 0, k = 0;
    if (s1->cols != s2->cols || s1->rows != s2->rows)
    {
        return NULL;
    }
    sum = malloc(sizeof(SparceMatrix));
    sum->numberOfNon_zeroElem = s1->numberOfNon_zeroElem + s2->numberOfNon_zeroElem;
    sum->ele = malloc(sizeof(sum->ele) * sum->numberOfNon_zeroElem);
    while (i < s1->numberOfNon_zeroElem && j < s2->numberOfNon_zeroElem)
    {
        if (s1->ele[i].row < s2->ele[j].row)
        {
            sum->ele[k++] = s1->ele[i++];
        }
        else if (s1->ele[i].row > s2->ele[j].row)
        {
            sum->ele[k++] = s2->ele[j++];
        }
        else
        {
            if (s1->ele[i].col < s2->ele[j].col)
            {
                sum->ele[k++] = s1->ele[i++];
            }
            else if (s1->ele[i].col > s2->ele[j].col)
            {
                sum->ele[k++] = s2->ele[j++];
            }
            else
            {
                sum->ele[k] = s1->ele[i];
                sum->ele[k++].value = s1->ele[i++].value + s2->ele[j++].value;
            }
        }
    }
    for (; i < s1->numberOfNon_zeroElem; i++)
    {
        sum->ele[k++] = s1->ele[i];
    }
    for (; j < s2->numberOfNon_zeroElem; j++)
    {
        sum->ele[k++] = s2->ele[j];
    }
    sum->cols = s1->cols;
    sum->rows = s1->rows;
    return sum;
}

int main(void)
{
    SparceMatrix s;
    create(&s);
    display(s);
    return 0;
}
