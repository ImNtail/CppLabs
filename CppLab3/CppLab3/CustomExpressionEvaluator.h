#pragma once

#include "ExpressionEvaluator.h"
#include "IShuffle.h"

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle
{
    std::string name_ = "Custom Expression Evaluator";
public:
    CustomExpressionEvaluator();
    CustomExpressionEvaluator(int n);
    double calculate() const override;
    void logToScreen() const override;
    void logToFile(const std::string& filename) const override;
    void shuffle() override;
    void shuffle(size_t i, size_t j) override;
};