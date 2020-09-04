// First.cpp : Defines the entry point for the console application.
//
/*ќбъ€вить массив из n=15 вещественных чисел, проинициализировать нул€ми. ‘ункци€
processArray() должна заполнить массив случайными числами от 20.0 до 100.0, а
затем вычесть из каждого элемента массива минимальное значение в массиве. Ёто
значение она также должна вернуть на выходе. —формировать выходной
вещественный массив, в котором все элементы, сто€щие до позиции минимального
элемента включительно, повтор€ют элементы входного массива, а остальные равны
минимальному элементу массива. ¬ывести на экран результирующие массивы.*/

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

void processArray(float arr[], int n, float a, float b)
{
	srand((unsigned int)time(NULL));
	float min = 1000;
	int pos = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] = ((b - a) * ((float)rand() / RAND_MAX)) + a;
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
	printf("Position of ");
}

int main()
{
	const int n = 15;
	float a = 20, b = 100;
	float arr[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	processArray(arr, n, a, b);
}