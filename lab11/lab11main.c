#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <windows.h>

typedef struct {
    double sum;
    double max;
    double min;
    double average;
} Result;

Result calculate(int count, ...)
{
    Result res = { 0, 0, 0, 0 };

    if (count <= 0)
        return res;

    va_list args;
    va_start(args, count);

    double first = va_arg(args, double);

    res.sum = first;
    res.max = first;
    res.min = first;

    for (int i = 1; i < count; i++) {
        double x = va_arg(args, double);

        res.sum += x;

        if (x > res.max)
            res.max = x;

        if (x < res.min)
            res.min = x;
    }

    va_end(args);

    res.average = res.sum / count;

    return res;
}

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