#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*void Populate(Array *arr){
	int n = 0;
	fprintf(stdout, "Enter the size of an array: ");
	fscanf(stdin, "%d", &arr->size);
	arr->A = (int *)malloc(arr->size*sizeof(int));
	arr->length = 0;

	fprintf(stdout, "Enter the length of array: ");
	fscanf(stdin, "%d", &n);
	while (true)
	{
		if (n > arr->size)
		{
			fprintf(stderr, "Enter a lesser number please: ");
			fscanf(stdin, "%d", &n);
		}else
			break;
	}
	fprintf(stdout, "Enter the elements of array: ");
	fprintf(stdout, "\n");

	fprintf(stdout, "length of array %d\n", n);
	for (int i = 0; i < n; ++i)
	{
		fprintf(stdout, "Enter the element %d: ", i);
		fscanf(stdin, "%d", &arr->A[i]);
	}
	arr->length = n;
}
*/
void Display(Array arr)
{
	int n = arr.length;
	for (int i = 0; i < n; ++i)
	{
		fprintf(stdout, "%d ", arr.A[i]);
	}
	fprintf(stdout, "\n");
}

void Append(Array *arr, int value)
{
	if (arr->length < arr->size)
	{
		arr->A[arr->length] = value;
		arr->length++;
	}
	else
	{
		fprintf(stderr, "Array is full\n");
	}
}

void Insert(Array *arr, int index, int newValue)
{
	if (index >= 0 && index <= arr->length)
	{
		for (int i = arr->length; i > index; --i)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = newValue;
		arr->length++;
	}
}

int Delete(Array *arr, int index)
{
	int deletedValue = 0;
	if (index >= 0 && index < arr->length)
	{
		deletedValue = arr->A[index];
		for (int i = index; i < arr->length - 1; ++i)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		return deletedValue;
	}
	else
	{
		fprintf(stderr, "Position %d does'nt exist\n", index);
		return -1;
	}
}

void Fill(Array *arr, int value)
{
	for (int i = 0; i < arr->size; ++i)
	{
		arr->A[i] = value;
	}
}

void Destroy(Array *arr)
{
	free(arr->A);
	arr->A = NULL;
}

int LinearSearch(Array *arr, int key)
{
	for (int i = 0; i < arr->length; ++i)
	{
		if (key == arr->A[i])
		{
			Swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;
}

void Swap(int *first, int *second)
{
	int tmp;
	tmp = *first;
	*first = *second;
	*second = tmp;
}
int BinarySearch(Array arr, int key)
{
	int middle;
	int low = 0;
	int high = arr.length - 1;
	while (low <= high)
	{

		middle = (low + high) / 2;

		if (key == arr.A[middle])

			return middle;
		else if (key < arr.A[middle])

			high = middle - 1;
		else
			low = middle + 1;
	}
	return -1;
}

int BinarySearch_R(int array[], int low, int high, int key)
{
	int middle;

	if (low <= high)
	{
		middle = (low + high) / 2;
		if (key == array[middle])
		{
			return middle;
		}
		else if (key < array[middle])
		{
			return BinarySearch_R(array, low, (middle - 1), key);
		}
		else
		{
			return BinarySearch_R(array, (middle + 1), high, key);
		}
	}
	return -1;
}

int Get(Array arr, int index)
{
	if (index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}
	return -1;
}

void Set(Array *arr, int index, int value)
{
	if (index >= 0 && index < arr->length)
	{
		arr->A[index] = value;
	}
	return;
}

int Max(Array arr)
{
	int max = arr.A[0];
	for (int i = 0; i < arr.length; ++i)
	{
		if (arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}
	return max;
}

int Min(Array arr)
{
	int min = arr.A[0];
	for (int i = 0; i < arr.length; ++i)
	{
		if (arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}
	return min;
}

int Sum(Array arr)
{
	int sum = 0;
	for (int i = 0; i < arr.length; ++i)
	{
		sum += arr.A[i];
	}
	return sum;
}

int rSum(int arr[], int length)
{
	if (length < 0)
	{
		return 0;
	}
	return rSum(arr, length - 1) + arr[length];
}

float Avg(Array arr)
{
	return Sum(arr) / arr.length;
}

void ReverseBad(Array *arr)
{
	int *B;
	int i, j;

	B = (int *)malloc(arr->length * sizeof(int));
	for (i = (arr->length - 1), j = 0; i >= 0; --i, j++)
	{
		B[j] = arr->A[i];
	}
	for (int i = 0; i < arr->length; ++i)
	{
		arr->A[i] = B[i];
	}

	free(B);
	B = NULL;
}

void Reverse(Array *arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; ++i, j--)
	{
		Swap(&arr->A[i], &arr->A[j]);
	}
}

void InsertSort(Array *arr, int value)
{

	int i = arr->length - 1;

	if (arr->length == arr->size)
	{
		return;
	}
	while (i >= 0 && (arr->A[i] > value))
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = value;
	arr->length++;
}

void Rearrange(Array *arr)
{
	int i = 0, j = arr->length - 1;
	while (i < j)
	{
		while (arr->A[i] < 0)
			i++;
		while (arr->A[j] >= 0)
			j--;
		if (i < j)
		{
			Swap(&arr->A[i], &arr->A[j]);
		}
	}
}

struct Array *Merge(struct Array *arr1, struct Array *arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	return arr3;
}
