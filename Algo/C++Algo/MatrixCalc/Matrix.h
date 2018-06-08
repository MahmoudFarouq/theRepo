#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template<class T>
class Matrix
{
    public:
        Matrix();
        Matrix(int r, int c);
        int getColumn();
        int getRows();
        virtual ~Matrix();

        Matrix<T>& operator+(Matrix& other);
        Matrix<T>& operator-(Matrix& other);
        Matrix<T>& operator*(Matrix& other);
        Matrix<T>& Transpose();

        friend istream& operator>> (istream& input, Matrix<T>& mat)
        {
            for(int i = 0; i < mat.Rows; i++)
            {
                for(int j = 0; j < mat.Columns; j++)
                {
                    input >> mat.matrix[i][j];
                }
            }
            return input;
        }
        friend ostream& operator<< (ostream& output, Matrix<T>& mat)
        {
            for(int i = 0; i < mat.Rows; i++)
            {
                for(int j = 0; j < mat.Columns; j++)
                {
                    output << mat.matrix[i][j] << " ";
                }
                output << endl;
            }
            return output;
        }

    protected:

    private:
        T **matrix;
        int Rows, Columns;
};

#endif // MATRIX_H
