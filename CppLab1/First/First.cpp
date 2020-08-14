// First.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdlib>
#include <ctime>

void print(int arr[], int n)
{
	printf("\nArray:\n");
	for (int i = 0; i < n; i++)
	{
		printf("| %d ", arr[i]);
	}
}

void processArray(int arr[], int n, int a, int b)
{
	srand((unsigned int)time(NULL));
	int i = 0;
	size_t cnt = 0;
	while (i < n)
	{
		arr[i] = arr[i] * ((rand() % (b-a+1)) + a);
		if (arr[i] < 0)
			cnt++; //считаем кол-во отрицательных (как раз будет размером массива)
		i+=2;
	}
	print(arr, n);

	int* newArr = new int[cnt];

	for (int i = 0; i < cnt; i++)
		newArr[i] = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			for (int j = 0; j < cnt; j++)
			{
				if (newArr[j] == 0)
				{
					newArr[j] = arr[i];
					break;
				}
			}
		}
	}
	print(newArr, cnt);
}

int main()
{
	const int n = 15;
	int arr[n] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int a = 1, b;
	while (a > 0)
	{
		printf("Enter range of randomizing ( a and b, a < 0 ): ");
		scanf("%d %d", &a, &b);
	}
	processArray(arr, n, a, b);
	//system("pause");
}