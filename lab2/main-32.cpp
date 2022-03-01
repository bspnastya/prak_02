//
//  main.cpp
//  kp2_lr2
//
//  Created by nastya on 02.11.2021.
//
//

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "matrix.h"
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
    cout << "Выберите операцию: \n 1) Сложение матриц \n 2) Умножение матриц \n 3) Умножение матрицы на число \n 4) Вычитание матриц \n 5) Произведение Адамара \n 6) Создать единичную матрицу \n 7) Диагональная матрица \n 8) Верхняя треугольная матрица \n 9) Нижняя треугольная матрица \n 10) Симметричная матрица \n 11) След матрицы \n 12) Скалярно перемножить векторы \n 13) Норма вектора(евклидова или максимальная) \n 14) Норма матрицы \n 15) Определитель матрицы" << endl;
        int n;
    cin >> n;
 
    switch (n)
    {
    case 1: // Для сложения матриц
        { try{ //Для поиска исключений
        int r1, c1, r2, c2;
        cout << "Введите количество строк матрицы 1: ";
        cin >> r1;
        cout << "Введите количество столбцов матрицы 1: ";
        cin >> c1;
        cout << "Введите элементы 1 матрицы: ";
        Matrix mat(r1, c1);
        mat.EnterMatrix();
        cout <<"Первая введенная матрица:\n"<< mat;
        cout << "Введите количество строк матрицы 2: ";
        cin >> r2;
        cout << "Введите количество столбцов матрицы 2:";
        cin >> c2;
        cout << "Введите элементы 2 матрицы: ";
        Matrix mat2(r2, c2);
        mat2.EnterMatrix();
        cout <<"Вторая введенная матрица:\n"<< mat2;
            cout << mat + mat2;}
            catch (const char* exception) // обработка исключений
            {
                std::cerr << "Error: " << exception << std::endl;
            }        break;
    }
    case 2: // Умножение матриц
        { try{
        int r1, c1, r2, c2;
        cout << "Введите количество строк для 1 матрицы: ";
        cin >> r1;
        cout << "Введите количество столбцов для 1 матрицы: ";
        cin >> c1;
        cout << "Введите элементы 1 матрицы: ";
        Matrix mat(r1, c1);
        mat.EnterMatrix();
        cout <<"Введенная первая матрица:\n"<< mat;
        cout << "Введите количество строк для 2 матрицы: \n";
        cin>>r2;
        cout << "Введите количество столбцов для 2 матрицы: ";
        cin >> c2;
        cout << "Введите элементы 2 матрицы: ";
        Matrix mat2(r2, c2);
        mat2.EnterMatrix();
        cout <<"Введенная вторая матрица:\n"<< mat2;
            cout << mat * mat2;}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
        break;
    }
    case 3: // Умножение матрицы на вектор
    {
        int r1, c1;
        cout << "Введите количество строк для 1 матрицы: ";
        cin >> r1;
        cout << "Введите количество столбцов для 1 матрицы: ";
        cin >> c1;
        cout << "Введите элементы 1 матрицы: ";
        Matrix mat(r1, c1);
        mat.EnterMatrix();
        cout <<"Введенная матрица:\n"<< mat;
        double scalar;
        cout<<"Введите число:"<<endl;
        cin>>scalar;
        cout << mat * scalar;
        break;
    }
        case 4: //Выычитание матриц
        { try{
            int r1, c1, r2, c2;
            cout << "Введите количество строк матрицы 1: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы 1: ";
            cin >> c1;
            cout << "Введите элементы 1 матрицы: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Первая введенная матрица:\n" <<mat;
            cout << "Введите количество строк матрицы 2: ";
            cin >> r2;
            cout << "Введите количество столбцов матрицы 2:";
            cin >> c2;
            cout << "Введите элементы 2 матрицы: ";
            Matrix mat2(r2, c2);
            mat2.EnterMatrix();
            cout <<"Вторая введенная матрица:\n" <<mat2;
            cout << mat - mat2;}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }            break;
        }
        case 5:
        { try{ //Операция Адамара
            int r1, c1, r2, c2;
            cout << "Введите количество строк матрицы 1: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы 2: ";
            cin >> c1;
            cout << "Введите элементы 1 матрицы: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Первая введенная матрица:\n" <<mat;
            cout << "Введите количество строк матрицы 2: ";
            cin >> r2;
            cout << "Введите количество столбцов матрицы 2:";
            cin >> c2;
            cout << "Введите элементы 2 матрицы: ";
            Matrix mat2(r2, c2);
            mat2.EnterMatrix();
            cout <<"Вторая введенная матрица:\n" <<mat2;
            cout << hadamara(mat, mat2);}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            break;
        }
            
        case 6:
        { try{ //Создание единичной матрицы
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            singleMatrix mat(r1, c1);
            mat.EnterSingleMatrix();
            cout<<mat;}
            catch (const char* exception) // обработка исключений типа const char*
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            break;
        }
        case 7:
        { try{ //Создание диагональной матрицы
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            diagonalMatrix mat(r1, c1);
            mat.EnterDiagonalMatrix();
            cout<<mat;}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            break;
            
    }
        case 8:
        { try{//Создание верхнетреугольной матрицы
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            upTriangleMatrix mat(r1, c1);
            mat.EnterUpTriangleMatrix();
            cout<<mat;}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            break;
            
            
    }
        case 9: //Создание нижнетреугольной матрицы
        { try{
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            downTriangleMatrix mat(r1, c1);
            mat.EnterDownTriangleMatrix();
            cout<<mat;}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            break;
        }

        case 10:
        {try{ //Создание симметричной матрицы
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            simMatrix mat(r1, c1);
            mat.EnterSimMatrix();
            cout<<mat;}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            break;
    }
        case 11:
        { try{ //След матрицы
            int r1, c1;
            cout << "Введите количество строк матрицы : ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы : ";
            cin >> c1;
            cout << "Введите элементы матрицы: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Первая введенная матрица:\n" <<mat;
            cout << Trace(mat);}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            cout<<endl;
            break;
        }
        case 12:
        { try{ //Скалярное умножение векторов
            int r1, c1,r2,c2;
            cout << "Введите количество строк матрицы 1: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы 1: ";
            cin >> c1;
            cout << "Введите элементы 1 вектора: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Первый введенный вектор:\n" <<mat;
            cout << "Введите количество строк матрицы 2: ";
            cin >> r2;
            cout << "Введите количество столбцов матрицы 2:";
            cin >> c2;
            cout << "Введите элементы 2 вектора: ";
            Matrix mat2(r2, c2);
            mat2.EnterMatrix();
            cout <<"Вторая введенный вектор:\n" <<mat2;
            cout << scalarVectors(mat,mat2);}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            cout<<endl;
            break;
        }
        case 13:
        { try{ //Норма вектора
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            cout << "Введите элементы вектора: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Введенный вектор :\n" <<mat;
            cout << normOfvec(mat);}
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }
            cout<<endl;
            break;
        }
        case 14://норма матрицы
        {
            int r1, c1;
            cout << "Введите количество строк матрицы: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы: ";
            cin >> c1;
            cout << "Введите элементы матрицы: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Введенная матрица:\n" <<mat;
            cout << matrixNorm(mat);
            cout<<endl;
            break;
        }
        case 15:
        { try{
            int r1, c1;
            cout << "Введите количество строк матрицы 1: ";
            cin >> r1;
            cout << "Введите количество столбцов матрицы 1: ";
            cin >> c1;
            cout << "Введите элементы 1 матрицы: ";
            Matrix mat(r1, c1);
            mat.EnterMatrix();
            cout <<"Первая введенная матрица:\n" <<mat;
            cout << determinant(mat);
        }
            catch (const char* exception)
                {
                    std::cerr << "Error: " << exception << std::endl;
                }            cout<<endl;
            break;
        }            return 0;
}
}
