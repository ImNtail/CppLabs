/*
��������������: 2D to 1D. ��������� ������ 5�5 ����� ����� ���������� ��������
� ���� ��� �� ��������� ����� ������� � ������ ����, �������� ��� �������� ��
�������� �������.
�������������: ��������� ������ ������������: x[i][j] = i! + j!.
����� �� �����: �� ������ ������� ������� ������� 8 �������.
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