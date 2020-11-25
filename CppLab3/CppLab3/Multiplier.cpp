#include "Multiplier.h"
#include <iostream>
#include <fstream>

Multiplier::Multiplier() : ExpressionEvaluator() { }

Multiplier::Multiplier(int n) : ExpressionEvaluator(n) { }

double Multiplier::calculate()
{
    double output = ops_[0];
    for (int i = 1; i < n_; i++)
        output *= ops_[i];
    return output;
}

void Multiplier::logToScreen()
{
    for (int i = 0; i < n_; i++)
        std::cout << "Op" << i + 1 << ", ";
    std::cout << ": ";
    for (int i = 0; i < n_; i++)
    {
        if (ops_[i] >= 0)
            std::cout << ops_[i] << " ";
        else
            std::cout << "(" << ops_[i] << ") ";
        if (i == n_ - 1)
            std::cout << "\n-> ";
        else
            std::cout << "x ";
    }
    std::cout << calculate() << std::endl;
}

void Multiplier::logToFile(const std::string& filename)
{
    std::ofstream file;
    file.open(filename);
    for (int i = 0; i < n_; i++)
        file << "Op" << i + 1 << ", ";
    file << ": ";
    for (int i = 0; i < n_; i++)
    {
        if (ops_[i] >= 0)
            file << ops_[i] << " ";
        else
            std::cout << "(" << ops_[i] << ") ";
        if (i == n_ - 1)
            file << "\n-> ";
        else
            file << "x ";
    }
    file << calculate() << std::endl;
}

std::string Multiplier::getName()
{
    return name_;
}