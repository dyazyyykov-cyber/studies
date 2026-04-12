#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

int main() {
    int year, month, day;
    char* week[] = {
        "Воскресенье", "Понедельник", "Вторник",
        "Среда", "Четверг", "Пятница", "Суббота"
    };

    printf("Введите дату в формате гггг.мм.дд: ");
    scanf("%d.%d.%d", &year, &month, &day);

    struct tm t = { 0 };
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day;

    mktime(&t);

    printf("День недели: %s\n", week[t.tm_wday]);

    return 0;
}

int get_clean_str(char* str, int size)
{
    if (fgets(str, size, stdin))
    {
        str[strcspn(str, "\n")] = '\0';

        if (str == "\0")
        {
            return 0;
        }
    }

    return 1;
}
