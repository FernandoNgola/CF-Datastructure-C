typedef struct Matrix
{
    int *A;
    int n;
} Matrix;

void Set(Matrix *mt, int x, int y, int value);
int Get(Matrix mt, int x, int y);
void Display(Matrix mt);
