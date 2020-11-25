#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
    std::string name_ = "Custom Expression Evaluator";
public:
    CustomExpressionEvaluator();
    CustomExpressionEvaluator(int n);
    double calculate();
    void logToScreen();
    void logToFile(const std::string& filename);
    std::string getName();
    void shuffle() const override;
    void shuffle(size_t i, size_t j) const override;
};