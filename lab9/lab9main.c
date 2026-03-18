#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_clean_str(char* str, int size);
void preprocessing_str(const char* str, char* out);

int main()
{
    char s[80];
    char out[160];
    char* tok;

    printf("Введите выражение: ");
    while (get_clean_str(s, sizeof(s)));

    preprocessing_str(s, out);

    printf("После предобработки: %s\n", out);

    tok = strtok(out, " ");
    while (tok != NULL)
    {
        printf("Токен: %s\n", tok);
        tok = strtok(NULL, " ");
    }

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