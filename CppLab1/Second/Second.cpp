/*
Преобразование: 2D to 1D. Двумерный массив 5х5 целых чисел необходимо выложить
в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
нечетных строках.
Инициализация: заполнить массив факториалами: x[i][j] = i! + j!.
Вывод на экран: на каждый элемент массива отвести 8 позиций.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

const size_t n = 5;

void print(int arr[n][n])
{
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << "        ";
		}
		std::cout << std::endl;
	}
}

int fact(int num)
{
	if (num == 0)
		return 1;
	else
		return num * fact(num - 1);
}

void arrInit(int arr[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = fact(i) + fact(j);
		}
	}
	print(arr);
}

void main()
{
	int arr[n][n];
	arrInit(arr);
	system("pause");
}