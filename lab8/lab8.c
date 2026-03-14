#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab8.h"

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

    printf("Ошибка чтения\n");
    return 1;
}

void print_people(struct human* people, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %s %d %c %.2f\n",
            people[i].fname,
            people[i].lname,
            people[i].year,
            people[i].sex,
            people[i].height);
}

void save_people(const char* filename, struct human* people, int n)
{
    FILE* f = fopen(filename, "w");
    if (!f) return;

    for (int i = 0; i < n; i++)
        fprintf(f, "%s;%s;%d;%c;%.2f\n",
            people[i].fname,
            people[i].lname,
            people[i].year,
            people[i].sex,
            people[i].height);

    fclose(f);
}

int cmp_one(const struct human* A, const struct human* B, int field)
{
    switch (field)
    {
    case 1:
        return A->year - B->year;
    case 2:
        return strcmp(A->fname, B->fname);
    case 3:
        return strcmp(A->lname, B->lname);
    case 4:
        return (int)A->sex - (int)B->sex;
    case 5:
        if (A->height < B->height) return -1;
        if (A->height > B->height) return 1;
        return 0;
    default:
        return 0;
    }
}

int comp_multi(const void* a, const void* b)
{
    const struct human* A = (const struct human*)a;
    const struct human* B = (const struct human*)b;

    for (int i = 0; i < k; i++) {
        int r = cmp_one(A, B, keys[i]);
        if (r != 0)
            return r;
    }

    return 0;
}