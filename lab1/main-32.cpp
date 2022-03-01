//
//  main.cpp
//  kp2_lr1
//
//  Created by nastya on 30.10.2021.
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
    cout << "Выберите операцию: \n 1) Сложение матриц \n 2) Умножение матриц \n 3) Умножение матрицы на число \n 4) Вычитание матриц \n 5) Произведение Адамара \n 6) Создать единичную матрицу \n 7) Диагональная матрица \n 8) Верхняя треугольная матрица \n 9) Нижняя треугольная матрица \n 10) Симметричная матрица" << endl;
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
        
    return 0;
}
}
