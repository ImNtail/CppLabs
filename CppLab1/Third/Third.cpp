/*
�������� ���� ������ ����������� ������� ��������� ����� �� ����� cstring, �
������������ � ���������.� ������� main �� �������� ������ ������������������
��������� ������ ��� ����������� �������, ��� � ����������� ������.���� - �����
������ ������������ ���������� cstdio.
������� strchr.
������ char* strchr(char* s, int c).
������� ������� � ������ s ������ ��������� ������� � � ���������� ���������,
������������ � ����� �������.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <string>

char* search(char s[], char ch)
{
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ch)
		{
			char* newS = &s[i];
			return newS;
		}
	}
}

void main()
{
	char s[] = "Hello, that's the third task of the first lab.\n";
	char ch;
	printf("%s\n", s);
	printf("Write the symbol you want: ");
	scanf("%c", &ch);
	char* symbol = strchr(s, ch);
	printf("\nStrchr function strchr found the first entrance of \"%c\" and returned the rest of string.\n\nRest of string: %s\n", ch, symbol);
	printf("\nMy function found the first entrance of \"%c\" and returned the rest of string.\n\nRest of string: %s\n", ch, search(s, ch));
}