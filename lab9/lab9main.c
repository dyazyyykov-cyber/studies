#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

int get_clean_str(char* str, int size);
void preprocessing_str(const char* str, char* out);

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    char s[80];
    char out[160];
    char* tok, op;
    double result, num;

    printf("Введите выражение: ");
    while (get_clean_str(s, sizeof(s)));

    preprocessing_str(s, out);

    tok = strtok(out, " ");      // первый токен
    result = strtod(tok, NULL);  // начальное число

    while (1)
    {
        tok = strtok(NULL, " "); // оператор
        if (tok == NULL)
            break;

        op = tok[0];

        tok = strtok(NULL, " "); // число после оператора
        if (tok == NULL)
            break;

        num = strtod(tok, NULL);

        if (op == '+')
            result = result + num;
        else if (op == '-')
            result = result - num;
    }

    printf("%.2f\n", result);
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

void preprocessing_str(const char* str, char* out)
{
    int i = 0, j = 0;
    char prev = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }

        if (str[i] == '+' || str[i] == '-')
        {
            if (prev == 0 || prev == '+' || prev == '-')
            {
                out[j] = str[i];
                j++;
            }
            else
            {
                out[j] = ' ';
                j++;
                out[j] = str[i];
                j++;
                out[j] = ' ';
                j++;
            }

            prev = str[i];
            i++;
            continue;
        }

        out[j] = str[i];
        j++;
        prev = str[i];
        i++;
    }

    out[j] = '\0';
}