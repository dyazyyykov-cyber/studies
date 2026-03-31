#include <string.h>
#include <windows.h>
#include <locale.h>
#include <stdarg.h> 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double sum;
    double max;
    double min;
    double average;
} Result;

Result calculate(int count, ...)
{
    Result res = { 0.0, 0.0, 0.0, 0.0 };

    va_list args;
    va_start(args, count);

    double first_val = va_arg(args, double);

}