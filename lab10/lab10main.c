#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_clean_str(char* str, int size);

int main(void)
{
    char s[200];

    printf("Введите числа: ");
    while (get_clean_str(s, sizeof(s)));


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