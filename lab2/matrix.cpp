//
//  matrix.cpp
//  kp2_lr2
//
//  Created by nastya on 02.11.2021.
//
#include "matrix.h"
Matrix::Matrix(): row(0), column(0) {}
Matrix::Matrix(int row, int column) : row(row), column(column)
{
   matrix.resize(row, vector<double>(column));
}

void Matrix::EnterMatrix() //ввод матрицы
{
    double element;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            cin >> element;
            matrix[i][j] = element;
        }
}
double scalarVectors(const Matrix& a,const Matrix& b){
    if ((a.column!=1)&(a.row!=1)) throw "Вы ввели не вектор\n";
    if ((b.column!=1)&(b.row!=1)) throw "Вы ввели не вектор\n";
    if ((a.column!=b.column)&(b.row!=a.column)) throw "Нельзя скалярно перемножить векторы разных размерностей\n";
    cout<<"Скалярное произведение векторов:"<<endl;
    double res=0;
    if (a.column==b.column){
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < b.row; j++)
        {
                res = res+a.matrix[i][j] * b.matrix[i][j];
            
        }
    }
    }
    else {
        for (int i = 0; i < a.row; i++)
        {
            for (int j = 0; j < b.row; j++)
            {
                    res = res+a.matrix[i][j] * b.matrix[j][i];
                
            }
        }    }
    return res;
}
double Trace(const Matrix&a){
    if (a.column!=a.row) throw "Матрица должна быть квадратной\n";
    cout<<"След матрицы:"<<endl;
    double trace=0;
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.column; j++)
        {
            if(i==j) trace=trace+a.matrix[i][j];
            else trace=trace+0;
        }
    }
        return trace;
}
double matrixNorm(const Matrix& a){
    cout<<"Норма матрицы:"<<endl;
    double norm=0;
    for (int j=0; j<a.row;j++){
        for (int i=0;i<a.column;i++){
            norm =norm+ a.matrix[j][i]*a.matrix[j][i];
    }
    }
        norm=sqrt(norm);
    return norm;
}
double lcm(double x,double y)// это вспомогательная функция для подсчета коэффициента при использовании метода гаусса при приведении к диагональному виду
{
  double t;
    t=x/y;
    return x;
}
double determinant(Matrix& a){
    if (a.column!=a.row) throw "Матрица должна быть квадратной";
double d1,d2;
   for(int i=0;i<a.row-1;i++)
           {
               for(int j=i+1;j<a.row;j++)
               {
               double  l=lcm(a.matrix[i][i],a.matrix[j][i]);                if(l!=0&&(a.matrix[i][i]!=0&&a.matrix[j][i]!=0))
                 {
                   l=(a.matrix[i][i]*a.matrix[j][i])/l;
                   d1=l/a.matrix[i][i];
                   d2=l/a.matrix[j][i];
                   a.matrix[j][i]=0;
                   for(int k=i+1;k<a.row;k++)
                   {
                     a.matrix[j][k]=(d2*a.matrix[j][k])-(d1*a.matrix[i][k]);
                   }
                 }
               }
            }
   cout <<"В качестве промежуточного подсчета посмотрите на приведение к треугольному виду:\n"<<a;
    cout<<"Определитель матрицы:"<<endl;
    double det=1;
    for (int i = 0; i < a.row; i++)
    {
        for (int j = 0; j < a.column; j++)
        {
            if(i==j) det=det*a.matrix[i][j];
            else det=det+0;
        }
    }

  
    return det;
}
double normOfvec(const Matrix& a){
    if ((a.column!=1)&(a.row!=1)) throw "Введен не вектор";
    int z;
    cout<<"Вид нормы: \n 1) Евклидова \n 2) Максимальная \n";
    cin>>z;
    cout<<"Норма вектора:"<<endl;
    double norm=0;    switch(z){
        case 1:{
        for (int j=0; j<a.row;j++){
            for (int i=0;i<a.column;i++){
                norm =norm+ a.matrix[j][i]*a.matrix[j][i];
        }
        }
            norm=sqrt(norm);
            break;
        }
        case 2:{
            norm=a.matrix[0][0];
                for (int j=0; j<a.row;j++){
                    for (int i=0;i<a.column;i++){
                        if (a.matrix[j][i]>norm)
                            norm=a.matrix[j][i];
                    }
                }
                    break;
        }
    }
    return norm;
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
