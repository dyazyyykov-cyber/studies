#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int year, month, day;
    char* week[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };

    printf("Введите дату: ")
        if (get_clean_str(str, sizeof(str)))
        {
            if (strcmp(str, "now") == 0)

            else if (sscanf(str, "%d.%d.%d%", &year, &month, &day) == 3)
            {

            }
            else if (sscanf(str, "%d.%d", &year, &month) == 2)
            {

            }
            else if (sscanf(str, "%d", &year) == 1)
            {

            }
        }

    struct tm t = { 0 };
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;

}

int get_clean_str(char* str, int size)
{
    if (fgets(str, size, stdin))
    {
        str[strscpn(str, "\n")] = '\0';

        if (str == "\0")
        {
            return 0;
        }
    }
    return 1;
}
