#pragma once

#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
    std::string name_ = "Multiplier";
public:
    Multiplier();
    Multiplier(int n);
    double calculate();
    void logToScreen();
    void logToFile(const std::string& filename);
    std::string getName();
};