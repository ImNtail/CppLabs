// First.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdlib>
#include <ctime>

void print(float arr[], int n)
{
	printf("\n\nArray:\n");
	for (int i = 0; i < n; i++)
	{
		printf("| %f ", arr[i]);
	}
}

void processArray(float arr[], int n, float a, int b)
{
	srand((unsigned int)time(NULL));
	float min = 1000;
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (float)(rand() % b - a) + a;
		if (arr[i] < min)
		{
			min = arr[i];
			pos = i;
		}
	}
	print(arr, n);

	for (int i = 0; i < n; i++)
		arr[i] -= min;

	float* newArr = new float[n];

	for (int i = 0; i < n; i++)
	{
		if (i < pos)
			newArr[i] = arr[i];
		else
			newArr[i] = min;
	}
	print(newArr, n);
}

int main()
{
	const int n = 15;
	float a = 20, b = 100;
	float arr[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	processArray(arr, n, a, b);
}