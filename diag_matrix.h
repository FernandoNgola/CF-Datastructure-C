typedef struct Matrix
{
	int A[10];
	int n;
} Matrix;

void set(Matrix *m, int i, int j, int x);
int get(Matrix m, int i, int j);
void display(Matrix m);