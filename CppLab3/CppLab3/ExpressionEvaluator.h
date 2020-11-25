#pragma once

#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
public:
    ExpressionEvaluator();
    ExpressionEvaluator(int n);
    void setOperand(size_t pos, double value);
    void setOperands(double ops[], size_t n);
    virtual std::string getName() = 0;
    virtual double calculate() = 0;
    virtual ~ExpressionEvaluator();
    int getSize();
protected:
    size_t n_;
    double* ops_;
};