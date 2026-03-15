#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
}

int get_clean_str(char *str, int size)
{
	if (fgets(str, size, stdin))
	{
		if (str[0] = '\n')
		{
			printf("Вы ввели пустую строку");
			return 1;
		}
		str[strcspn(str, '\n')] = '\0';
		return 0;
	}
}