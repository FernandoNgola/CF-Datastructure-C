
typedef struct Array
{
	int *A;
	int size;
	int length;
} Array;

//void Populate(Array *arr);

void Display(Array arr);

void Append(Array *arr, int value);

void Insert(Array *arr, int index, int newValue);

int Delete(Array *arr, int index);

void Fill(Array *arr, int value);

void Destroy(Array *arr);

int LinearSearch(Array *arr, int key);

int BinarySearch(Array arr, int key);

int BinarySearch_R(int[], int low, int high, int key);

int Get(Array arr, int index);

void Set(Array *arr, int index, int value);

int Max(Array arr);

int Min(Array arr);

int Sum(Array arr);
int rSum(int arr[], int length);

float Avg(Array arr);

void ReverseBad(Array *arr);
void Reverse(Array *arr);

void InsertSort(Array *arr, int value);

void Rearrange(Array *arr);

struct Array *Merge(struct Array *arr1, struct Array *arr2);

//Auxiliar
void Swap(int *first, int *second);
