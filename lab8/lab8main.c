#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

struct human {
    char fname[30];
    char lname[30];
    int year;
    char sex;      
    float height; 
};

int get_clean_str(char* str, int size)
{

    if (fgets(str, size, stdin))
    {
        if (str[0] == '\n')
        {
            printf("Вы ввели пустую строку");

            return 1;
        }

        str[strcspn(str, "\n")] = '\0';
    }
    else
    {
        printf("Ошибка чтения");

        return 1;
    }

    return 0;
}

int main() {
    char* nums[] = { "первого","второго","третьего","четвертого" };
    struct human people[N];
    char s[80];
    int i;

    for (i = 0; i < N; i++) {
        printf("Имя %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        strcpy(people[i].fname, s);

        printf("Фамилия %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        strcpy(people[i].lname, s);

        printf("Год рождения %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        people[i].year = atoi(s);

        printf("Пол (M/F) %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        people[i].sex = s[0];

        printf("Рост (м) %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        people[i].height = (float)atof(s);

        printf("\n");
    }

    return 0;
}

void sort()
{

}