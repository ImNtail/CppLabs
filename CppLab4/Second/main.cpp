/*
���������� ������� GOF �������� � ����� ����� (������� ������ � ������� �������)
�� ��������� �������. �������� ��������� IFormattable � ������� std::string
format() ��� �������������� �������, ������������ ������ ���������, � �����
������� void prettyPrint(const IFormattable& object), ������� ������� ��
����� ������-�������� � ����������������� ����. �������� ���, ����� � ���
������� ����� ���� ���������� ������ �� ���� ������ ����, ������������� �
������� 1. �������� �������������� ���������� ������������ ����.
*/

#include <iostream>
#include "IFormattable.h"
#include "Adapter.h"

int main()
{
	IFormattable* adapter = new Adapter();
	Deck deck;
	adapter->prettyPrint(deck);

	delete adapter;

	return 0;
}