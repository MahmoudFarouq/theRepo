#include "MatrixCalculator.h"

MatrixCalculator::MatrixCalculator(string name)
{
    cout << "Welcome to " << name << " Matrix Calculator" << endl;
    cout << "----------------------------------------" << endl;
    Intro();
}
void MatrixCalculator::Intro()
{
    cout << "1- Perform Matrix Addition" << endl;
    cout << "2- Perform Matrix Subtraction" << endl;
    cout << "3- Perform Matrix Multiplication" << endl;
    cout << "4- Matrix Transpose" << endl;
    int choose;
    START:
    cin >> choose;
    switch(choose)
    {
        case 1: AdditionOrSubtract(1); break;
        case 2: AdditionOrSubtract(2); break;
        case 3: Multiplication(); break;
        case 4: Transpose(); break;
        default:
            cout << "Wrong Input, Try Again" << endl;
            goto START;
    }
}
void MatrixCalculator::AdditionOrSubtract(int x)
{
    int r1, c1, r2, c2;
    cout << "Enter Num Of Rows And Columns For First Matrix: ";
    cin >> r1 >> c1;
    cout << "Enter Num Of Rows And Columns For Second Matrix: ";
    cin >> r2 >> c2;
    Matrix<int> *mat1 = new Matrix<int>(r1, c1);
    Matrix<int> *mat2 = new Matrix<int>(r2, c2);
    cout << "Enter The Elements of the First Matrix: " << endl;
    cin >> *mat1;
    cout << "Enter The Elements of the Second Matrix: " << endl;
    cin >> *mat2;
    cout << "the Result of" << (x == 1 ? "Adding":"Subtracting") << " ->" << endl;
    cout << *mat1 << endl;
    cout << "to -> " << endl;
    cout << *mat2 << endl;
    cout << "is -> " << endl;
    (x == 1 ? *mat1 + *mat2:*mat1 - *mat2);
    cout << *mat1 << endl;
    Intro();
}

void MatrixCalculator::Multiplication()
{
    int r1, c1, r2, c2;
    cout << "Enter Num Of Rows And Columns For First Matrix: ";
    cin >> r1 >> c1;
    cout << "Enter Num Of Rows And Columns For Second Matrix: ";
    cin >> r2 >> c2;
    if( c1 != r2 )
    {
        cout << "You Entered An Invalid Operation, The Columns of FirstMatrix Must EQUAL The Rows Of SecondMatrix, Retry" << endl;
        Intro();
        return;
    }
    Matrix<int> *mat1 = new Matrix<int>(r1, c1);
    Matrix<int> *mat2 = new Matrix<int>(r2, c2);
    cout << "Enter The Elements of the First Matrix: " << endl;
    cin >> *mat1;
    cout << "Enter The Elements of the Second Matrix: " << endl;
    cin >> *mat2;
    cout << "the Result of Multiplying ->" << endl;
    cout << *mat1 << endl;
    cout << "to -> " << endl;
    cout << *mat2 << endl;
    cout << "is -> " << endl;
    cout << (*mat1 * *mat2) << endl;
    Intro();
}
void MatrixCalculator::Transpose()
{
    int r1, c1;
    cout << "Enter Num Of Rows And Columns For The Matrix: ";
    cin >> r1 >> c1;
    Matrix<int> *mat1 = new Matrix<int>(r1, c1);
    cout << "Enter The Elements of the First Matrix: " << endl;
    cin >> *mat1;
    cout << "the Result of Transposing ->" << endl;
    cout << *mat1 << endl;
    cout << "is -> " << endl;
    cout << (mat1->Transpose()) << endl;
    Intro();
}
MatrixCalculator::~MatrixCalculator()
{
    //dtor
}
