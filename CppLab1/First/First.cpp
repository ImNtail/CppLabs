// First.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <cstdlib>
#include<ctime>

void processArray(int ar[15] , int n, int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
	
		if (i%2 ==0)
		{
			ar[i] = ar[i] * rand()/((a + b)*1000);
			printf("%d\n", ar[i]);
		}
	}
}

int main()
{
	const size_t n = 15;
	int ar[n];
	int a;
	int b;
	printf("\nEnter - a & b\n");
	std::cin >> a>>b;
	printf("\nArray start\n");
	for (int i = 0; i < n; i++)
	{
		ar[i] = 1;
		printf("%d\n", ar[i]);
	}
	printf("\nArray error \n");
	processArray(ar, n, a, b);
	system("pause");
}
