#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int year, month, day;
    char* week[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
    struct tm t = { 0 };

    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;



    printf("Введите дату: ")
        if (get_clean_str(str, sizeof(str)))
        {
            if (strcmp(str, "now") == 0)
            {
                currentDate(&t)
            }
            else if (sscanf(str, "%d.%d.%d%", &year, &month, &day) == 3)
            {
                printWeek();
            }
            else if (sscanf(str, "%d.%d", &year, &month) == 2)
            {
                printMonth();
            }
            else if (sscanf(str, "%d", &year) == 1)
            {
                printYear();
            }
        }



}

int currentDate(*t)
{
    t = localtime(&mytime);
}

int printWeek(int* year, int* month, int* day)
{
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
}

int printMonth(int* year, int* month)
{
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;
}

int printYear(int* year)
{
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

//Написать программу-календарь. Пользователь может указать даты в формате:
//- гггг.мм.дд – программа вычисляет день недели соответствующий данной дате;
//- гггг.мм – программа выводит календарь за данный месяц;
//- гггг – календарь за год;
//- now – текущую дату.
