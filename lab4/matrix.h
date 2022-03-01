//
//  matrix.h
//  kp2_lr3
//
//  Created by nastya on 04.11.2021.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <cmath>
using std::vector;
using namespace std;

class Matrix //класс матриц
{
private:
   
   int row; //строки
   int column; //столбцы
public:
    vector<vector<double> > matrix; //представление матрицы в виде вектора векторов
    Matrix(); //конструктор без параметров
    ~Matrix(){}; // деструктор
   Matrix(int row, int column);//конструктор с параметрами
 friend Matrix fromTxtFile(Matrix&a, const char*);
 friend Matrix fromBinFile(Matrix &s,const char*);
 Matrix(const Matrix &);
 void print() const;
 friend Matrix tofile(Matrix &a,int n);
    inline int rows(void) const { return row; }//геттер для приватных членов строк
    inline int cols(void) const { return column; } // геттер для приватных членов столбцов
    void EnterMatrix() ;//ввод матрицы
    friend double determinant(Matrix& a);
    friend double normOfvec(const Matrix& a);
    friend double inverse(Matrix& a);
    friend Matrix transpose(const Matrix &a);
    friend double rank1( Matrix& b);
    friend double matrixNorm(const Matrix&a);
    friend double angleBtwVecs(const Matrix& a,const Matrix& b);
    friend double scalarVectors(const Matrix& a, const Matrix& b);
    friend double Trace(const Matrix& a);
   friend Matrix operator+(const Matrix& a, const Matrix& b); //перегрузка для сложения
    friend Matrix operator-(const Matrix& a, const Matrix& b);//перегрузка для вычитания
   friend Matrix operator*(const Matrix& a,double scalar);//перегрузка для умножения на число
    friend Matrix hadamara(const Matrix& a,const Matrix &b);//функция для операции адамара
    friend ostream& operator<<(ostream& out, const Matrix& m); //перегрузка для операторы вывода
   friend Matrix operator*(const Matrix& a, const Matrix& b); // перегрузка для перемножения матриц
};
class singleMatrix: public Matrix{ //класс-наследник единичной матрицы
public:
    singleMatrix(int row,int column):Matrix(row,column){};
    void EnterSingleMatrix();
};
class diagonalMatrix: public Matrix{ //класс-наследник диагональной матрицы
public:
    diagonalMatrix(int row,int column):Matrix(row,column){};
    void EnterDiagonalMatrix();
};
class upTriangleMatrix: public Matrix{//класс-наследник верхнетреугольной матрицы
public:
   upTriangleMatrix(int row,int column):Matrix(row,column){};
    void EnterUpTriangleMatrix();
    
};
class downTriangleMatrix: public Matrix{//класс-наследник нижнетреугольной матрицы
public:
   downTriangleMatrix(int row,int column):Matrix(row,column){};
    void EnterDownTriangleMatrix();
    
    
};
class simMatrix: public Matrix{//класс-наследник для симметричной матрицы
public:
   simMatrix(int row,int column):Matrix(row,column){};
    void EnterSimMatrix();
};
