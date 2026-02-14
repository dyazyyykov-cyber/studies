#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "lab7.h"

struct human {
    char fname[30];
    char lname[30];
    int year;
};


int main()
{
    SetConsoleCP(1251);       
    SetConsoleOutputCP(1251);

    char* numbers[] = {"первого", "второго", "третьего", "четвертого"};
    struct human people_not_sorted[4];
    struct human people_sorted[4];
    char s[80];
    int i = 0, n = 0;

    for (i = 0; i < 4; i++)
    {

        printf("Введите имя %s человека: ", numbers[i]);
        while (get_clean_str(s, sizeof(s)));
        strcpy(people_not_sorted[i].fname, s);
        
        printf("Введите фамилию %s человека: ", numbers[i]);
        while (get_clean_str(s, sizeof(s)));
        strcpy(people_not_sorted[i].lname, s);

        printf("Введите год рождения %s человека: ", numbers[i]);
        while (get_clean_str(s, sizeof(s)));
        people_not_sorted[i].year = atoi(s);
       
        printf("\n");

    }

    n = sizeof(people_not_sorted) / sizeof(people_not_sorted[0]);

    memcpy(people_sorted, people_not_sorted, sizeof(people_not_sorted));

    qsort(people_sorted, n, sizeof(people_sorted[0]), comp);

    print(people_sorted, n);


    return 0;
}

int comp(const void* a, const void* b)
{
    const struct human* personA = (const struct human*)a;
    const struct human* personB = (const struct human*)b;

    return personA -> year - personB->year;
}

int get_clean_str(char* str, int size)
{

    int* t;

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

void print(struct human *people_sorted, int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("%s %s, год рождения: %d\n", people_sorted[i].fname, people_sorted[i].lname, people_sorted[i].year);
    }

}

//  Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. 
//  Объявить два массива из четырёх элементов типа humen. 
//  Ввести с консоли или из файла элементы одного массива и построить на их основе другой, 
//  упорядочив элементы по годам рождения. Вывести результат.
