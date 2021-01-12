#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator()
{
    n_ = 20;
    ops_ = new double[n_];
    for (size_t i = 0; i < n_; i++)
        ops_[i] = 0;
}

ExpressionEvaluator::ExpressionEvaluator(int n)
{
    n_ = n;
    ops_ = new double[n_];
    for (size_t i = 0; i < n_; ++i)
        ops_[i] = 0;
}
ExpressionEvaluator::~ExpressionEvaluator()
{
    delete[] ops_;
}

void ExpressionEvaluator::setOperand(int pos, double value)
{
    ops_[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], int n)
{
    for (int i = 0; i < n; ++i)
        ops_[i] = ops[i];
}