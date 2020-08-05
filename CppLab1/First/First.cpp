// First.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdlib>
#include <ctime>

void processArray(int arr[], int n, int a, int b)
{
	srand((unsigned int)time(NULL));
	int i = 0, cnt = 0;
	while (i < n)
	{
		arr[i] = arr[i] * ((rand() % (b-a+1)) + a);
		if (arr[i] < 0)
			cnt++; //считаем кол-во отрицательных (как раз будет размером массива)
		i+=2;
	}

	int newArr[cnt]; //чтобы создать массив, нужно указать размер в виде константы. надо придумать, как int cnt перевести в const int

	printf("\nArray:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
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