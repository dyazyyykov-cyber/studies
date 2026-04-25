#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{
    int year, month, day;
    char* str[80];
    struct tm t = { 0 };

    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;



    printf("Введите дату: ");
    if (get_clean_str(str, sizeof(str)))
    {
        if (strcmp(str, "now") == 0)
        {
            printCurrentDate(&t);
        }
        else if (sscanf(str, "%d.%d.%d%", &year, &month, &day) == 3)
        {
            printDayWeek(&t, &year, &month, &day);
        }
        else if (sscanf(str, "%d.%d", &year, &month) == 2)
        {
            printMonth(&t, &year, &month);
        }
        else if (sscanf(str, "%d", &year) == 1)
        {
            printYear();
        }
    }



}

int printCurrentDate(struct tm* t)
{
    time_t now = time(NULL);
    *t = *localtime(&now);
    printf("%02d.%02d.%d", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
}

int printDayWeek(struct tm *t ,int* year, int* month, int* day)
{
    char* week[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };

    t->tm_year = *year - 1900;
    t->tm_mon = *month - 1;
    t->tm_mday = *day;

    mktime(t);

    printf("%s", week[t->tm_wday]);
}

int printMonth(struct tm* t, int* year, int* month)
{
    int offset = 0, i = 0;

    t->tm_year = *year - 1900;
    t->tm_mon = *month - 1;
    t->tm_mday = 1;

    mktime(t);

    offset = t->tm_wday - 1;
    if (offset = 0)
    {
        offset = 6;
    }

    for (i = 0; i < offset; i++)
    {
        printf("  ");
    }

    for (i = 0; i < t->tm_mday; i++)
    {
        printf("%2d", i);

        if ((offset + i) % 7 == 0)
        {
            printf("\n");
        }

    }

}

int printYear(struct tm* t, int* year)
{
    t->tm_year = *year - 1900;
    t->tm_mon = *month - 1;
    t->tm_mday = *day;
}

int get_clean_str(char* str, int size)
{
    if (fgets(str, size, stdin))
    {
        str[strсspn(str, "\n")] = '\0';

        if (str[0] == '\0')
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
