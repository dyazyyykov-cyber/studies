#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include "lab8.h"

#define N 4

int keys[MAX_KEYS];
int k = 0;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    char* nums[] = { "первого", "второго", "третьего", "четвертого" };
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

        printf("Пол (М/Ж) %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        people[i].sex = s[0];

        printf("Рост (в метрах) %s: ", nums[i]);
        while (get_clean_str(s, sizeof(s)));
        people[i].height = (float)atof(s);

        printf("\n");
    }

    save_people("people.txt", people, N);

    printf("Поля сортировки:\n");
    printf("1-год  2-имя  3-фамилия  4-пол  5-рост\n");

    printf("Сколько полей сортировки (1-%d): ", MAX_KEYS);
    while (get_clean_str(s, sizeof(s)));
    k = atoi(s);

    if (k < 1) k = 1;
    if (k > MAX_KEYS) k = MAX_KEYS;

    for (i = 0; i < k; i++) {
        printf("Поле #%d: ", i + 1);
        while (get_clean_str(s, sizeof(s)));
        keys[i] = atoi(s);

        if (keys[i] < 1 || keys[i] > 5)
            keys[i] = 1;
    }

    qsort(people, N, sizeof(people[0]), comp_multi);

    printf("\n");
    print_people(people, N);

    return 0;
}