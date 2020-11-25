#pragma once

#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator
{
    std::string name_ = "Summator";
public:
    Summator();
    Summator(int n);
    double calculate();
    void logToScreen();
    void logToFile(const std::string& filename);
    std::string getName();
};
