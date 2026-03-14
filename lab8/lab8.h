#ifndef LAB8_H
#define LAB8_H

#define MAX_KEYS 5

struct human {
    char fname[30];
    char lname[30];
    int year;
    char sex;
    float height;
};

extern int keys[MAX_KEYS];
extern int k;

int get_clean_str(char* str, int size);
void print_people(struct human* people, int n);
void save_people(const char* filename, struct human* people, int n);
int cmp_one(const struct human* A, const struct human* B, int field);
int comp_multi(const void* a, const void* b);

#endif