#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <windows.h>
#include "lab11.h"

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