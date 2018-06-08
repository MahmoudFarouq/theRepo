#include "Matrix.h"


template<class T>
Matrix<T>::Matrix()
{

}
template<class T>
Matrix<T>::Matrix(int r, int c)
{
    Rows = r;
    Columns = c;
    matrix = new T*[r];
    for(int i = 0; i < r; i++)
    {
        matrix[i] = new T[c];
    }
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Columns; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

template<class T>
Matrix<T>::~Matrix()
{
    for(int i = 0; i < Rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
template<class T>
int Matrix<T>::getColumn(){return Columns;}
template<class T>
int Matrix<T>::getRows(){return Rows;}

template<class T>
Matrix<T>& Matrix<T>::operator+(Matrix& other)
{
    if( other.getRows() != Rows || other.getColumn() != Columns )
        return *(new Matrix<T>);
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Columns; j++)
        {
            matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator-(Matrix& other)
{
    if( other.getRows() != Rows || other.getColumn() != Columns )
        return *(new Matrix<T>);
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Columns; j++)
        {
            matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator*(Matrix& other)
{
    if( Columns != other.getRows() )
        return *(new Matrix<T>);

    Matrix<T> *tempMat = new Matrix<T>(Rows, other.getColumn());

    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < other.getColumn(); j++)
        {
            for(int k = 0; k < Columns; k++)
            {
                int x =  matrix[i][k] * other.matrix[k][j];
                tempMat->matrix[i][j] += x;
            }
        }
    }
    return *(tempMat);
}
template<class T>
Matrix<T>& Matrix<T>::Transpose()
{
    Matrix<T> *tempMat = new Matrix<T>(Columns, Rows);
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Columns; j++)
        {
            tempMat->matrix[j][i] = matrix[i][j];
        }
    }
    return *(tempMat);
}

/*
http://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor
*/
template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;
