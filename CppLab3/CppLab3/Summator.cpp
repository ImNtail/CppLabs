#include "Summator.h"
#include <iostream>
#include <fstream>

Summator::Summator() : ExpressionEvaluator() { }

Summator::Summator(int n) : ExpressionEvaluator(n) { }

double Summator::calculate()
{
    double output;
    for (int i = 0; i < n_; i++)
    {
        i == 0 ? (output = ops_[i]) : (output -= ops_[i]);
    }
    return output;
}

void Summator::logToScreen()
{
    for (int i = 0; i < n_; i++)
    {
        (ops_[i] >= 0 ?
            std::cout << ops_[i] :
            std::cout << '(' << ops_[i] << ')') //add parenthesis when operand is negative
            << (i != n_ - 1 ? (" minus ") : " equals ");
    }
    std::cout << calculate() << std::endl;
}

void Summator::logToFile(const std::string& filename)
{
    std::ofstream file;
    file.open(filename);
    for (int i = 0; i < n_; i++)
    {
        (ops_[i] >= 0 ?
            std::cout << ops_[i] :
            std::cout << '(' << ops_[i] << ')') //add parenthesis when operand is negative
            << (i != n_ - 1 ? (" minus ") : " equals ");
    }
    file << calculate() << std::endl;
}

std::string Summator::getName()
{
    return name_;
}