#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

double a=3, b=12, c=9, d, x1, x2;
void main()
{

    SetConsoleCP(1251);       // Чтобы правильно работал ввод (scanf)
    SetConsoleOutputCP(1251); // Чтобы правильно работал вывод (printf)

    d = pow(b,2) - 4 * a * c;
    
    if (d > 0) 
    {
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
    }
    else if (d == 0)
    {
        x1 = -b/(2*a);
        x2 = x1;
    }
    else if (d < 0)
    {
        x1 = 0;
        x2 = 0;
    }
 
    printf("x1 = %f\nx2 = %f", x1,x2); 

}