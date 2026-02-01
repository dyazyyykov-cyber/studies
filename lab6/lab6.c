#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6.h"


int input(FILE **people)
{
	*people = fopen("./input.txt", "r");
	if (!*people)
	{
		perror("Не удалось откртыть файл с вводными данными");
		return 1;
	}
	return 0;
}

int output(FILE **target_people)
{
	*target_people = fopen("./output.txt", "a");
	if (!*target_people)
	{
		perror("Не удалось откртыть файл для вывода данных");
		return 1;
	}
	return 0;
}

void check_year(FILE* people, FILE* target_people)
{
	int year = 0;
	char s[256];

	while (fgets(s, sizeof(s), people))
	{
		sscanf(s, "%*s %*s %*s %d", &year);

		if (year > 1980)
		{
			fprintf(target_people, s);
		}
	}
	return;
}