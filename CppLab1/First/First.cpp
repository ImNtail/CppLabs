/*
Вариант 7.
Объявить массив из n=15 вещественных чисел, проинициализировать нулями. Функция
processArray() должна заполнить массив случайными числами от 20.0 до 100.0, а
затем вычесть из каждого элемента массива минимальное значение в массиве. Это
значение она также должна вернуть на выходе. Сформировать выходной
вещественный массив, в котором все элементы, стоящие до позиции минимального
элемента включительно, повторяют элементы входного массива, а остальные равны
минимальному элементу массива. Вывести на экран результирующие массивы.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdlib>
#include <ctime>

//array printing func
void print(float arr[], int n)
{
	printf("\n\nArray:\n");
	for (int i = 0; i < n; i++)
	{
		printf("| %f ", arr[i]);
	}
}

float processArray(float arr[], int n, float a, float b)
{
	srand((unsigned int)time(NULL));
	int pos = 0;
	//making random values of array numbers
	for (int i = 0; i < n; i++)
	{
		arr[i] = ((b - a) * ((float)rand() / RAND_MAX)) + a;
	}
	print(arr, n);
	//searching min num
	float min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			pos = i;
		}
	}
	//subtracting the minimum num from each number
	for (int i = 0; i < n; i++)
		arr[i] -= min;

	float* newArr = new float[n];
	//making new array
	for (int i = 0; i < n; i++)
	{
		if (i < pos)
			newArr[i] = arr[i];
		else
			newArr[i] = min;
	}
	print(newArr, n);
	return min;
}

void main()
{
	const int n = 15;
	float a = 20, b = 100;
	float arr[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	printf("\n\nMin num of array is %f\n", processArray(arr, n, a, b));
}