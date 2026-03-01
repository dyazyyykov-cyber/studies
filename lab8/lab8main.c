#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4
#define MAX_KEYS 5

struct human {
    char fname[30];
    char lname[30];
    int year;
    char sex;
    float height;
};

int get_clean_str(char* str, int size);
void print_people(struct human* people, int n);
void save_people(const char* filename, struct human* people, int n);
int cmp_one(const struct human* A, const struct human* B, int field);
int comp_multi(const void* a, const void* b);

int keys[MAX_KEYS];
int k = 0;

int main()
{
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
        printf("Поле #%d (1-5): ", i + 1);
        while (get_clean_str(s, sizeof(s)));
        keys[i] = atoi(s);
        if (keys[i] < 1 || keys[i] > 5) keys[i] = 1;
    }

    qsort(people, N, sizeof(people[0]), comp_multi);

    printf("\n");
    print_people(people, N);

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
    printf("Ошибка чтения\n");
    return 1;
}

void print_people(struct human* people, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %s %d %c %.2f\n",
            people[i].fname, people[i].lname, people[i].year, people[i].sex, people[i].height);
}

void save_people(const char* filename, struct human* people, int n)
{
    FILE* f = fopen(filename, "w");
    if (!f) return;

    for (int i = 0; i < n; i++)
        fprintf(f, "%s;%s;%d;%c;%.2f\n",
            people[i].fname, people[i].lname, people[i].year, people[i].sex, people[i].height);

    fclose(f);
}

int cmp_one(const struct human* A, const struct human* B, int field)
{
    switch (field)
    {
    case 1: return A->year - B->year;
    case 2: return strcmp(A->fname, B->fname);
    case 3: return strcmp(A->lname, B->lname);
    case 4: return (int)A->sex - (int)B->sex;
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
        if (r != 0) return r;
    }
    return 0;
}