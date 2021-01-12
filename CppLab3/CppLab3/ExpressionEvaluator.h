#pragma once

#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
protected:
    size_t n_;
    double* ops_;

public:
    ExpressionEvaluator();
    ExpressionEvaluator(int n);
    virtual ~ExpressionEvaluator();

    void setOperand(int pos, double value);
    void setOperands(double ops[], int n);
    virtual double calculate() const = 0;
};