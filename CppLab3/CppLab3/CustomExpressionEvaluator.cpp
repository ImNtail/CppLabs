#include "CustomExpressionEvaluator.h"
#include <iostream>
#include <fstream>

CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator() { }
CustomExpressionEvaluator::CustomExpressionEvaluator(int n) : ExpressionEvaluator(n) { }

double CustomExpressionEvaluator::calculate() const
{
	double result = 0.0;
	//result = x1 – x2 / 2 + x3 / 3 – x4 / 4 + ...
	for (size_t i = 0; i < n_; i++)
	{
		int x = i + 1;
		if (i % 2 == 0)
			result += (ops_[i] / x);
		else
			result -= (ops_[i] / x);
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen() const
{
	for (size_t i = 0; i < n_; i++)
		std::cout << "Op" << i + 1 << ", ";
	std::cout << ": " << ops_[0] << " - ";
	for (size_t i = 1; i < n_; i++)
	{
		int x = i + 1;
		if (ops_[i] >= 0)
			std::cout << ops_[i] << "/" << x << " ";
		else
			std::cout << "(" << ops_[i] << ")/" << x << " ";
		if (i == n_ - 1)
			std::cout << "\n-> ";
		else if (i % 2 != 0)
			std::cout << "+ ";
		else
			std::cout << "- ";
	}
	std::cout << CustomExpressionEvaluator::calculate() << std::endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename) const
{
	std::ofstream file;
	file.open(filename + ".log", std::ios_base::app);
	for (size_t i = 0; i < n_; i++)
		file << "Op" << i + 1 << ", ";
	file << ": ";
	for (size_t i = 0; i < n_; i++)
	{
		if (ops_[i] >= 0)
			file << ops_[i] << " ";
		else
			file << "(" << ops_[i] << ") ";
		if (i == n_ - 1)
			file << "\n-> ";
		else
			file << "x ";
	}
	file << CustomExpressionEvaluator::calculate() << std::endl;
	file.close();
}

void CustomExpressionEvaluator::shuffle()
{
	for (size_t startIndex = 0; startIndex < n_; startIndex++)
	{
		if (ops_[startIndex] < 0)
		{
			size_t biggestIndex = startIndex;
			for (size_t currentIndex = startIndex + 1; currentIndex < n_; currentIndex++)
			{
				if (ops_[currentIndex] > ops_[biggestIndex] && ops_[currentIndex] < 0)
					biggestIndex = currentIndex;
			}
			std::swap(ops_[startIndex], ops_[biggestIndex]);
		}
	}
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
	if (i != 0 && j != 0)
	{
		i--;
		j--;
	}
	if (i < n_ && j < n_ && i >= 0 && j >= 0 && i < j)
	{
		for (size_t startIndex = i + 1; startIndex < j; startIndex++)
		{
			size_t smallestIndex = startIndex;
			for (size_t currentIndex = startIndex + 1; currentIndex < j; currentIndex++)
			{
				if (ops_[currentIndex] < ops_[smallestIndex])
					smallestIndex = currentIndex;
			}
			std::swap(ops_[startIndex], ops_[smallestIndex]);
		}
	}
}