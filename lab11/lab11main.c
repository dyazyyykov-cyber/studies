#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <windows.h>
#include "lab11.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Result r = calculate(5, 10.0, 20.0, 5.5, 7.0, 12.3);

    printf("sum = %.2lf\n", r.sum);
    printf("max = %.2lf\n", r.max);
    printf("min = %.2lf\n", r.min);
    printf("average = %.2lf\n", r.average);

    return 0;
}

//Создать в отдельном модуле функции с переменным количеством аргументов,
// которая вычисляет их сумму, максимум, минимум, среднее арифметическое.