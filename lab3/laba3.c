#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

enum {rows=3, columns=3};

void ChangeReg(char s[]);
void input_M(int m[][columns]);
void print_M(int m[][columns]);
void calculate_M(int m[][columns], int *SumMainDi, int *SumSecondDi);
void check_magic_square(int m[][columns], int SumMainDi, int SumSecondDi);

void main()
{
    char s[80];
    int m[rows][columns], SumMainDi=0, SumSecondDi=0;

    setlocale(LC_ALL, "");

    //Получаем строку
    printf("Введите строку:\n");
    gets(s);

    //Изменяем регистр букв a и b
    ChangeReg(s);

    //Ввод матрицы c консоли
    input_M(m);

    //Вывод матрицы
    print_M(m);

    //Подсчет сумм диагоналей
    calculate_M(m, &SumMainDi, &SumSecondDi);

    //проверка на магический квадрат
    check_magic_square(m, SumMainDi, SumSecondDi);
}

//Функция изменяющая регистр букв a и b
void ChangeReg(char s[])
{
    int i;

    for (i=0; s[i]!=0; i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            s[i] = toupper(s[i]);
        }
    }
    printf("\nИзмененная строка: %s\n\n", s);
}

//Функция ввода матрицы
void input_M(int m[][columns])
{
    int i, j;
    char s[80];

   printf("Введите элементы матрицы\n");
   for (i=0; i<rows; i++)
   {
        for (j=0; j<columns; j++)
        {
            printf("Элемент %d,%d: ", i+1, j+1);
            gets(s);
            m[i][j] = atoi(s);
        }
   } 
}

//Функция вывода матрицы
void print_M(int m[][columns])
{
    int i, j;

   printf("\nИтоговая матрица:\n");
   for (i=0; i<rows; i++)
   {
        for (j=0; j<columns; j++)
        {
            printf("%5d ",m[i][j]);
        }
        printf("\n");
   } 
}

//Функция подсчета сумм главной и побочной диагоналей матрицы
void calculate_M(int m[][columns], int *SumMainDi, int *SumSecondDi)
{
    int i;

    for (i=0; i<rows; i++)
    {
        *SumMainDi += m[i][i];
        *SumSecondDi += m[i][columns-i-1];
    }
    printf("\nСумма элементов главной диагонали: %d", *SumMainDi);
    printf("\nСумма элементов побочной диагонали: %d\n\n", *SumSecondDi);
}

//Функция проверки матрицы на "Magic square"
void check_magic_square(int m[][columns], int SumMainDi, int SumSecondDi)
{
    int i, j, sumElements, targetNum;

    if (SumMainDi == SumSecondDi)
    {
        targetNum = SumMainDi;
        for (i=0; i<rows; i++)
        {
            sumElements = 0;
            for (j=0; j<columns; j++)
            {
                sumElements += m[i][j];
            }
            if (targetNum != sumElements) 
            {   
                printf("Квадрат не магический(\n\n");
                return;
            }
        }

        for (i=0; i<columns; i++)
        {
            sumElements = 0;
            for (j=0; j<rows; j++)
            {
                sumElements += m[j][i];
            }
            if (targetNum != sumElements) 
            {   
                printf("Квадрат не магический(\n\n");
                return;
            }
            
        }
        printf("Квадрат магический!!!\n\n");
    } 
    else
    {
        printf("Квадрат не магический(\n\n");
    }   
}







// // Ввести с консоли строку символов произвольной длины (до 80 символов). Поменять в ней все маленькие символы ‘a’ и ‘b’ 
// на заглавные и вывести на консоль полученную строку.

// // Объявить массив данных типа int размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, 
// расположенных на главной диагонали и сумму элементов, расположенных на  побочной диагонали. Проверить, является ли матрица 
// «магическим квадратом» (в «магическом квадрате» суммы элементов по вертикали, горизонтали и диагонали равны).

// // В программе должна быть предусмотрена возможность работы с матрицами любого размера.
// // P.S.: Задание присылаем в архиве одним файлом. В архиве быть только исходный код и могут быть еще файлы настроек проекта, 
// исполняемый файл (по желанию). Других файлов в архиве быть не должно!!!! 