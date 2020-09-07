/*
������� 7.
�������� ������ �� n=15 ������������ �����, ������������������� ������. �������
processArray() ������ ��������� ������ ���������� ������� �� 20.0 �� 100.0, �
����� ������� �� ������� �������� ������� ����������� �������� � �������. ���
�������� ��� ����� ������ ������� �� ������. ������������ ��������
������������ ������, � ������� ��� ��������, ������� �� ������� ������������
�������� ������������, ��������� �������� �������� �������, � ��������� �����
������������ �������� �������. ������� �� ����� �������������� �������.
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

void processArray(float arr[], int n, float a, float b)
{
	srand((unsigned int)time(NULL));
	float min = 1000;
	int pos = 0;
	//making random values of array numbers
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
	printf("Position of ");
}

void main()
{
	const int n = 15;
	float a = 20, b = 100;
	float arr[n] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	processArray(arr, n, a, b);
}