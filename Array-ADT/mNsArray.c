#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SingleMissingEleNoN(int arr[], int len);
void MultipleMissingEle(int arr[], int len);
void Duplicate(int arr[], int len);

void SingleMissingEleN(int arr[], int len);

void MultipleMissingEleUnsorted(int arr1[], int arr2[], int len);

int Max(int arr[], int len)
{
	int max = arr[0];
	for (int i = 1; i < len; ++i)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int Min(int arr[], int len)
{
	int min = arr[0];
	for (int i = 1; i < len; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}
int main(int argc, char const *argv[])
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
	int arr1[] = {6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17};
	int arr2[] = {
		6,
		8,
		9,
		11,
		12,
		15,
		16,
		17,
		18,
		19,
	};
	int arr3[] = {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};

	int arr5[] = {3, 6, 8, 8, 10, 12, 15, 15, 18, 18, 18, 20};

	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t len1 = sizeof(arr1) / sizeof(arr1[0]);
	size_t len2 = sizeof(arr2) / sizeof(arr2[0]);
	size_t len3 = sizeof(arr3) / sizeof(arr3[0]);

	size_t len5 = sizeof(arr5) / sizeof(int);

	const int MAX = Max(arr3, len3);
	int *arr4 = malloc(MAX * sizeof(int));
	memset(arr4, 0, MAX * sizeof(int));

	//SingleMissingEleN(arr, len);
	//SingleMissingEleNoN(arr1, len1);
	//MultipleMissingEle(arr2, len2);

	MultipleMissingEleUnsorted(arr3, arr4, len3);

	printf("==========================================\n");
	Duplicate(arr5, len5);

	return 0;
}

void SingleMissingEleN(int arr[], int len)
{
	int sum = 0;
	int high = arr[len - 1];
	for (size_t i = 0; i < len; ++i)
	{
		sum += arr[i];
	}
	int fSum = (high + 1) * (high / 2);
	if (fSum != sum)
	{
		fprintf(stdout, "Missing value %d\n", (fSum - sum));
	}
}

void SingleMissingEleNoN(int arr[], int len)
{
	int low = arr[0];
	//int high = arr[len-1];
	int diff = low;
	//printf("%d %d\n", diff, len);
	for (size_t i = 0; i < len; ++i)
	{
		if ((arr[i] - i) != diff)
		{
			//printf("%ld\n", (arr[i]-i));
			fprintf(stdout, "Missing element %ld\n", (diff + i));
			break;
		}
	}
}

void MultipleMissingEle(int arr[], int len)
{
	int low = arr[0];
	//int high = arr[len-1];
	int diff = low;
	//printf("%d %d\n", diff, len);
	for (size_t i = 0; i < len; ++i)
	{
		if ((arr[i] - i) != diff)
		{
			while (diff < arr[i] - i)
			{
				//printf("%ld\n", (arr[i]-i));
				fprintf(stdout, "Missing element %ld\n", (diff + i));
				diff++;
			}
		}
	}
}

void MultipleMissingEleUnsorted(int arr1[], int arr2[], int len)
{

	int low = Min(arr1, len);
	int high = Max(arr1, len);
	for (int i = 0; i < len; ++i)
	{
		arr2[arr1[i]]++;
	}
	for (int i = low; i < high; ++i)
	{
		if (arr2[i] == 0)
		{
			fprintf(stdout, "%d\n", i);
		}
	}
}

void Duplicate(int arr[], int len)
{
	int MAX = Max(arr, len);
	int *arr2 = malloc(MAX * sizeof(int));
	memset(arr2, 0, MAX * sizeof(int));
	for (int i = 0; i < len; ++i)
	{
		arr2[arr[i]]++;
	}
	for (int i = 0; i < MAX; ++i)
	{
		if (arr2[i] > 1)
		{
			fprintf(stdout, "%d %d\n", i, arr2[i]);
		}
	}
}