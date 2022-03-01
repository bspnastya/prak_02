#include "matrix.h"
#include <math.h>
#include <fstream>
#include <sstream>
Matrix::Matrix(): row(0), column(0) {}
Matrix::Matrix(int row, int column) : row(row), column(column)
{
   matrix.resize(row, vector<double>(column));
}
Matrix::Matrix(const Matrix &B)
{
    this->column = B.cols();
    this->row = B.rows();
    this->matrix = B.matrix;
    
}
void Matrix::print() const
{
    cout << "Matrix: " << endl;
    for (unsigned i = 0; i < row; i++) {
        for (unsigned j = 0; j < column; j++) {
            cout << "[" << matrix[i][j] << "] ";
        }
        cout << endl;
    }}
Matrix fromBinFile(Matrix &a, const char *fileName){
  ifstream fin(fileName, ios::binary); 
	 if (fin.fail())  throw "Возникли проблемы с открытием файла\n";
	 double *y = new double[a.rows()*a.cols()+a.rows()*2];
	fin.read((char*)(y), sizeof(double)*(a.rows()*a.cols()+a.rows()*2-2)) ;
    fin.close();
        int inc=0;
    double *k= new double[a.rows()*a.cols()+a.rows()*2-2];
    for (int i = 0; i < a.rows()*a.cols()+a.rows()*2-2;i++) {
       if ((y[i]!=0)&(y[i]!=2.42092e-322)) {
           k[inc++]=y[i];
        }
    }
    int width = a.cols();
    int height = a.rows();
 for (int i = 0; i < height; i++) {
       for (int j = 0; j < width; j++) 
        {    
      a.matrix[i][j] = k[i * width + j];;
        }
}
  return a;
}
Matrix fromTxtFile(Matrix &a,const char *fileName){
    ifstream file_A(fileName); 
  if (file_A.fail())  throw "Возникли проблемы с открытием файла\n";
    a.column = 0;
    a.row = 0;
    string line_A;
    int idx = 0;
    double element_A;
    double *vector_A = nullptr;
    if (file_A.is_open() && file_A.good())
    {
        while (getline(file_A, line_A))
        {
            a.row += 1;
            stringstream stream_A(line_A);
            a.column = 0;
            while (1)
            {
                stream_A >> element_A;
                if (!stream_A)
                    break;
                a.column += 1;
                double *tempArr = new double[idx + 1];
                copy(vector_A, vector_A + idx, tempArr);
                tempArr[idx] = element_A;
                vector_A = tempArr;
                idx += 1;
            }
        }
    }
    else
    {
        cout << " Ошибка откытия файла! \n";
    }
    
    int j;
    idx = 0;
    a.matrix.resize(a.row);
    
    for (unsigned i = 0; i < a.matrix.size(); i++) {
        a.matrix[i].resize(a.column);
    }
    for (int i = 0; i < a.row; i++)
    {
        for (j = 0; j < a.column; j++)
        {
            a.matrix[i][j] = vector_A[idx];
           
            idx++;
        }
    }
  
    delete [] vector_A; // Tying up loose ends
    return a;

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
Matrix tofile(Matrix &a,int n){
    switch(n){
    case 1:{
    ofstream file;
        file.open("matrixNew.txt");
        if (file.fail())  throw "Возникли проблемы с открытием файла,куда была бы записана матрица\n";
        for (int i = 0; i < a.rows(); i++)
        {
            for (int j = 0; j < a.cols(); j++)
            {
                file<<a.matrix[i][j]<<" ";
                
                
            }
            file<<endl;
        }
        file.close();
        break;
    }
    case 2:{ofstream out;
    out.open("m.bin",ios::binary );
    for (int i = 0; i < a.rows(); i++)
        {
            for (int j = 0; j < a.cols()+a.rows()*2; j++)
         {  
            out.write(reinterpret_cast<char *>(&a.matrix[i][j]), sizeof(double)*(a.cols()+a.rows()*2)*a.rows() );
        }
        }
    out.close();
 
        break;
    }
        
    }
    return a;
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

Matrix transpose(const Matrix &a)
{
    Matrix neww(a.column,a.row);
    cout<<"Транспонированная матрица:"<<endl;
    for (unsigned i = 0; i < a.column; i++)
    {
        for (unsigned j = 0; j < a.row; j++) {
            neww.matrix[i][j] = a.matrix[j][i];
        }
    }
    return neww;
}
double lcm(double x,double y)//это вспомогательная функция для подсчета коэффициента при использовании метода гаусса при приведении к диагональному виду
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

double inverse(Matrix &a) {
    if (a.row!=a.column) throw "Матрица необратима\n";
    Matrix B(a.row,2*a.row);
    int n=a.row;
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<2*n;j++)
            {
                if(j>=n)
                {
                    if(i+n==j)
                        B.matrix[i][j]=1;
                    else
                        B.matrix[i][j]=0;
                }
                else
                    B.matrix[i][j]=a.matrix[i][j];
            }
        }
    cout << "Расширенная матрица,дополненная единичной:" << endl;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<2*n;j++)
         {
             cout << B.matrix[i][j] << " ";
         }
         cout << endl;
     }
    int m=0;
    int k=1;
    int i;
    int j;
    for(m=0;m!=n;m++)
       {
       cout << "Шаг-" << k <<endl;
       k++;
       for(i=m;i<n;i++)
       {
           for(j=2*n-1;j>=m;j--)
           {
               if(B.matrix[i][m]<0.000001)
               {
                   cout << "Матрица необратима" << endl;
                   exit(1);
               }
               else
                   B.matrix[i][j]=B.matrix[i][j]/B.matrix[i][m];
           }
       }
       for(i=0;i<n;i++)
       {
           for(j=0;j<2*n;j++)
           {
               cout << B.matrix[i][j] << " ";
           }
           cout << endl;
       }
       cout << "Шаг-" << k <<endl;
       k++;
       for(i=n-1;i>m;i--)
       {
           for(j=m;j<2*n;j++)
           {
               B.matrix[i][j]=B.matrix[i][j]-B.matrix[m][j];
           }
       }
       for(i=0;i<n;i++)
       {
           for(j=0;j<2*n;j++)
           {
               cout << B.matrix[i][j] << " ";
           }
           cout << endl;
       }
       }
       for(m=0;m!=n-1;m++)
       {
       cout << "Шаг-" << k <<endl;
       k++;
       for(i=m;i<n-1;i++)
       {
           for(j=2*n-1;j!=m;j--)
           {
               B.matrix[m][j]=B.matrix[m][j]-B.matrix[m][i+1]*B.matrix[i+1][j];
           }
       }
       for(i=0;i<n;i++)
       {
           for(j=0;j<2*n;j++)
           {
               cout << B.matrix[i][j] << " ";
           }
           cout << endl;
       }
       }    cout << "Обратная матрица:" << endl;
     for(i=0;i<n;i++)
     {
         for(j=n;j<2*n;j++)
         {
             cout << B.matrix[i][j] << " ";
         }
         cout << endl;
     }    return 0;
    }

double scalarVectors(const Matrix& a,const Matrix& b){
    if ((a.column!=1)&(a.row!=1)) throw "Вы ввели не вектор\n";
    if ((b.column!=1)&(b.row!=1)) throw "Вы ввели не вектор\n";
    if ((a.column!=b.column)&(b.row!=a.column)) throw "Нельзя скалярно перемножить векторы разных размерностей\n";
    cout<<"Скалярное произведение векторов:"<<endl;
    double res=0;
    if ((a.column==b.column)&(a.row==1)){
    for (int i = 0; i < a.column; i++)
    {
                res = res+a.matrix[0][i] * b.matrix[0][i];
    }
    }
    else if((a.row==b.row)&(a.column==1)){
        {
        for (int i = 0; i < a.row; i++)
        {
                    res = res+a.matrix[i][0] * b.matrix[i][0];
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
        }}
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
double angleBtwVecs(const Matrix& a, const Matrix& b){
    if ((a.column!=1)&(a.row!=1)) throw "Введен не вектор";
    if ((b.column!=1)&(b.row!=1)) throw "Введен не вектор";
    if (max(a.row,a.column)!=max(b.row,b.column)) throw "Векторы разных размерностей";
    double angle;
    double chisl=scalarVectors(a,b);
    double znam1=normOfvec(a);
    double znam2=normOfvec(b);
    angle=chisl/(znam1*znam2);
    cout<<"Угол между векторами:\n";
    return (acos(angle)*180)/(atan(1.0)*4);
}
double rank1(Matrix& b){
double d1,d2;
   for(int i=0;i<b.row-1;i++)
           {
               for(int j=i+1;j<b.row;j++)
               {
               double  l=lcm(b.matrix[i][i],b.matrix[j][i]);   
               if(l!=0&&(b.matrix[i][i]!=0&&b.matrix[j][i]!=0))
                 {
                   l=(b.matrix[i][i]*b.matrix[j][i])/l;
                   d1=l/b.matrix[i][i];
                   d2=l/b.matrix[j][i];
                b.matrix[j][i]=0;
                   for(int k=i+1;k<b.row;k++)
                   {
                     b.matrix[j][k]=(d2*b.matrix[j][k])-(d1*b.matrix[i][k]);
                   }
                 }
               }
            }
    cout<<"Матрица в треугольном виде:\n"<<b<<endl;
    cout<<"Ранг матрицы:";
    double Rank=b.row;
    int flag=0;
    for (int i=0;i<b.row;i++){
        flag = 0;
        for (int j=0;j<b.column;j++){
            if (b.matrix[i][j]==0) {
                flag++;
                }
        }
            if (flag==b.column) --Rank;
    }

    return Rank;
}
