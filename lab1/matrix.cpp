//
//  matrix.cpp
//  kp2_lr1
//
//  Created by nastya on 01.11.2021.
//

#include "matrix.h"
Matrix::Matrix(): row(0), column(0) {}
Matrix::Matrix(int row, int column) : row(row), column(column)
{
   matrix.resize(row, vector<int>(column));
}

void Matrix::EnterMatrix() //ввод матрицы
{
    int element;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            cin >> element;
            matrix[i][j] = element;
        }
}
Matrix hadamara(const Matrix& a,const Matrix &b){
    if ((a.column!=b.column)|(a.row!=b.row)) throw "Матрицы должны быть одной размерности\n";
    cout<<"Произведение Адамара"<<endl;
    Matrix result(a.row,b.column);
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < b.column; j++)
        {
                result.matrix[i][j] = a.matrix[i][j] * b.matrix[i][j];
            
        }
    }
    return result;
    
}
Matrix operator*(const Matrix& a,double scalar){
    cout<<"Умножение матрицы на число:"<<endl;

    Matrix result(a.row,a.column);
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.column; j++)
        {
            result.matrix[i][j] = a.matrix[i][j] * scalar;
        }
    }
    return result;
}


Matrix operator*(const Matrix& a, const Matrix& b) // ф-ция для перемножения матриц
{
 
   cout << "Произведение матриц равно:" << endl;
    if (a.column!=b.row) throw "Количество столбцов 1 матрицы должно быть равно количеству строк 2 матрицы\n";
    Matrix result(a.row, b.column);
   for (int i = 0; i < a.row; i++)
   {
       for (int j = 0; j < b.column; j++)
       {
           result.matrix[i][j] = 0;
           for (int t = 0; t < b.row; t++)
           {
               result.matrix[i][j] += a.matrix[i][t] * b.matrix[t][j];
           }
       }
   }
   return result;
}
Matrix operator-(const Matrix& a, const Matrix& b) // ф-ция для перемножения матриц
{
    if ((a.column!=b.column)|(a.row!=b.row)) throw "Матрицы должны быть одной размерности\n";
    cout << "Разность матриц равна:" << endl;
   Matrix result(a.row, b.column);
   for (int i = 0; i < a.row; i++)
   {
       for (int j = 0; j < b.column; j++)
       {
               result.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
           
       }
   }
   return result;
}
Matrix operator+(const Matrix& a, const Matrix& b) //ф-ция для сложения матриц
{ if ((a.column!=b.column)|(a.row!=b.row)) throw "Матрицы должны быть одной размерности\n";
    cout << "Сумма матриц равна:" << endl;
   Matrix result(a.row, a.column);
   for (int i = 0; i < a.row; i++)
   {
       for (int j = 0; j < a.column; j++)
       {
           result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
       }
   }
   return result;
}

ostream& operator<<(ostream& out, const Matrix& m) //ф-ция для вывода матрицы
{
   for (int i = 0; i < m.row; i++)
   {
       for (int j = 0; j < m.column; j++)
           out << m.matrix[i][j] << " ";
       out << endl;
   }
   return out;
}
void singleMatrix::EnterSingleMatrix(){
    if (rows()!=cols()) throw "Матрица должна быть квадратной\n";
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++)
        {
            if (i==j){matrix[i][j]=1;}
            else { matrix[i][j]=0;}
        }
    }
}
void diagonalMatrix::EnterDiagonalMatrix(){
    int element;
    if (rows()!=cols()) throw "Матрица должна быть квадратной\n";
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++)
        {
            if (i==j){
                cout<<"Введите элемент на диагонали:\n";
                cin>>element;
                matrix[i][j]=element;
                
            }
            else { matrix[i][j]=0;}
        }
    }
}
void upTriangleMatrix::EnterUpTriangleMatrix(){
    int element;
    if (rows()!=cols()) throw "Матрица должна быть квадратной\n";
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++)
        {
            if (i<=j){
                cout<<"Введите элемент:\n";
                cin>>element;
                matrix[i][j]=element;
                
            }
            else { matrix[i][j]=0;}
        }
    }
}
void downTriangleMatrix::EnterDownTriangleMatrix(){
    int element;
    if (rows()!=cols()) throw "Матрица должна быть квадратной\n";
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++)
        {
            if (i>=j){
                cout<<"Введите элемент:\n";
                cin>>element;
                matrix[i][j]=element;
                
            }
            else { matrix[i][j]=0;}
        }
    }
}
void simMatrix::EnterSimMatrix(){
    int element;
    if (rows()!=cols()) throw "Матрица должна быть квадратной\n";
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++)
        {
            if (i==j){
                cout<<"Введите элемент:\n";
                cin>>element;
                matrix[i][j]=element;
                
            }
            else if (i<j){
                cout<<"Введите элемент:\n";
                cin>>element;
                matrix[i][j]=element;}
            else matrix[i][j]=0;
        }
    }
    for (int i = 0; i < rows(); i++){
        for (int j = 0; j < cols(); j++){
            if (i!=j){matrix[j][i]=matrix[i][j];}
        }
    
    }
}
