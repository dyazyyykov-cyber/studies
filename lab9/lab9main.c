#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[80], sep[] = "+-";


	printf("Введите выражение: ");
	while(get_clean_str(s, sizeof(s)));
	strtok(s, sep);
}

int get_clean_str(char *str, int size)
{
	if (fgets(str, size, stdin))
	{
		if (str[0] == '\n')
		{
			printf("Вы ввели пустую строку");
			return 1;
		}
		str[strcspn(str, '\n')] = '\0';
		return 0;
	}
}

int preprocessing_str(char *str)
{
	int i = 0, j = 0;
	char out[160];
	char prev = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}

		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			if (prev == '+' || prev == '-' || prev == '/' || prev == '*')
			{
				out[j++] = str[i];
			}
			else
			{
				out[j++] = ' ';
				out[j++] = str[i];
				out[j++] = ' ';
			}

			prev = str[i];
			i++;
			continue;
		}

		out[j++] = str[i];
		prev = str[i];
		i++;
	}
	out[j] = '\0';
}