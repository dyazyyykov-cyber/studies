#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

int get_clean_str(char* str, int size);

#define FIND_MAX(arr, n, max)         \
    do                                \
    {                                 \
        max = arr[0];                 \
        for (int i = 1; i < n; i++)   \
        {                             \
            if (arr[i] > max)         \
            {                         \
                max = arr[i];         \
            }                         \
        }                             \
    } while (0)

int main(void)
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    char s[200];
    int numbers[100];
    int count = 0;
    int max;

    printf("Введите числа через пробел: ");

    while (get_clean_str(s, sizeof(s)));

    char* token = strtok(s, " ");

    while (token != NULL)
    {
        numbers[count] = atoi(token);
        count++;
        token = strtok(NULL, " ");
    }

    if (count == 0)
    {
        printf("Числа не введены.\n");
        return 1;
    }

    FIND_MAX(numbers, count, max);

    printf("Максимальное число: %d\n", max);

    return 0;
}

int get_clean_str(char* str, int size)
{
    if (fgets(str, size, stdin))
    {
        if (str[0] == '\n')
        {
            printf("Вы ввели пустую строку\n");
            return 1;
        }

        str[strcspn(str, "\n")] = '\0';
        return 0;
    }

    return 1;
}


//Написать программу вычисления максимального числа из введенных пользователем в виде одной строки.  
// Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество.