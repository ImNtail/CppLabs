/*
Реализуйте паттерн GOF «Адаптер» в обоих видах (адаптер класса и адаптер объекта)
на следующем примере. Напишите интерфейс IFormattable с методом std::string
format() для форматирования объекта, реализующего данный интерфейс, а также
функцию void prettyPrint(const IFormattable& object), которая выводит на
экран объект-параметр в отформатированном виде. Сделайте так, чтобы в эту
функцию можно было передавать ссылку на Вашу колоду карт, разработанную в
задании 1. Алгоритм форматирования придумайте произвольный сами.
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