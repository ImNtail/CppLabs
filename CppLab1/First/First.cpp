// First.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <cstdlib>

void processArray(int a[15])
{
	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
		{
			a[i] = a[i] * -1;
		}
		std::cout << a[i] << " ";
	}
}

int main()
{
	
	int a[15];
	for (int i = 0; i < 15; i++)
	{
		a[i] = rand()%11;
		std::cout << a[i]<<" ";
	}
  
	processArray(a);

	system("pause");
}
