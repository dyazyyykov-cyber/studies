#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

enum {rows_M1 = 3, columns_M1 = 3, rows_M2 = 2, columns_M2 = 2};
double m1[rows_M1][columns_M1], SumMainDi_M1, SumSecondDi_M1;
int m2[rows_M2][columns_M2],mRes[rows_M2][columns_M2], i,j,k;
char s[80];

void input_M1();
void input_M2();
void print_M1();
void print_M2();
void calculate_Sum_Diagonals();
void calculate_square();

void main()
{
    SetConsoleCP(1251);       // Чтобы правильно работал ввод (scanf)
    SetConsoleOutputCP(1251); // Чтобы правильно работал вывод (printf)

    //Ввод первой матрицы с консоли
    input_M1();

    //вывод матрицы
    print_M1();

    //подсчет сумм диагоналей
    calculate_Sum_Diagonals();

    //Ввод второй матрицы
    input_M2();

    //Вывод матрицы
    print_M2();

    //Вывод квадрата матрицы
    calculate_square();

    printf("\n");

}

//функция ввода первой матрицы double
void input_M1()
{    
    printf("Введите значения элементов матрицы\n");
    for (i=0; i<rows_M1; i++)
    {
        for (j=0; j<columns_M1; j++)
        {
            printf("Элемент %d,%d: ", (int)i + 1, (int)j + 1);
            gets(s);
            m1[i][j] = atof(s);
        }
    }
}

//функция ввода второй матрицы int
void input_M2()
{
    printf("\nВведите значения элементов второй матрицы\n");
    for (i=0; i<rows_M2; i++)
    {
        for (j=0; j<columns_M2; j++)
        {
            printf("Элемент %d,%d: ", (int)i + 1, (int)j + 1);
            gets(s);
            m2[i][j] = atoi(s);
        }
    }    
}

//функция вывода первой матрицы double
void print_M1()
{
     //Вывод первой матрицы
    printf("\nМатрица заполнена\n\nИтоговая матрица:\n");
    for (i=0; i<rows_M1; i++)
        {
            for (j=0; j<columns_M1; j++)
            {
                printf("%5.2f ",m1[i][j]);
            }
            printf("\n");
        }
}

//функция вывода второй матрицы int
void print_M2()
{
    printf("\nМатрица заполнена\n\nИтоговая матрица:\n");
    for (i=0; i<rows_M2; i++)
        {
            for (j=0; j<columns_M2; j++)
            {
                printf("%5d ",m2[i][j]);
            }
            printf("\n");
        }
}

//функция подсчет сумм главной и побочной диагоналей первой матрицы double
void calculate_Sum_Diagonals()
{
    for (i=0; i<rows_M1; i++)
    {
        SumMainDi_M1 = SumMainDi_M1 + m1[i][i];
        SumSecondDi_M1 = SumSecondDi_M1 + m1[i][(rows_M1-1)-i];
    }
    printf("\nСумма главной диагонали: %f\nСумма побочной диагонали: %f\n", SumMainDi_M1, SumSecondDi_M1);
}

//функция подсчета и вывода квадрата второй матрицы int
void calculate_square()
{
    printf("\nКвадрат матрицы:\n");
    for (i=0; i<rows_M2; i++)
    {
        for (j=0; j<columns_M2; j++)
        {
            for (k=0; k<columns_M2; k++)
            {
                mRes[i][j] = mRes[i][j] + (m2[i][k] * m2[k][j]);     
            }
            printf("%5d ", mRes[i][j]);  
        }
        printf("\n");
    }
}