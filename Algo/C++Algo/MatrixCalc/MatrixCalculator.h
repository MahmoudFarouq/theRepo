#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H
#include <iostream>
#include "Matrix.h"
using namespace std;

class MatrixCalculator
{
    public:
        MatrixCalculator(string name);
        void Intro();
        void AdditionOrSubtract(int x);
        void Multiplication();
        void Transpose();
        virtual ~MatrixCalculator();

    private:
};

#endif // MATRIXCALCULATOR_H
