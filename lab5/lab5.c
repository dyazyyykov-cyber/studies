#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <>

char *get_clean_str(char *s, int size)
{
	while (1)
	{	
		if (!(fgets(s, size, stdin)))
		{
			printf("Ошибка чтения");
			return 0;
		}

		if (s[0] == '\n')
		{
			printf("Вы ввели пустую строку, попробуйте еще раз: ");
		}
		else
		{
			s[strcspn(s, "\n")] = '\0';
			return s;
		}	
	} 
}

void print_m(double **m, int rows, int columns)
{
	int i = 0, j = 0;

	printf("\nИтоговая матрица:\n");

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("%12.6f ",m[i][j]);
		}
		printf("\n");
	}
}

void input_m(double **m, int rows, int columns)
{
	int i = 0, j = 0;
	char s[80];

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{

			printf("Введите элемент %d,%d: ", (int) i + 1, (int) j + 1);
			if (get_clean_str(s, sizeof(s)))
			{
				m[i][j] = atof(s);
			}		
		}
	}
}

double**create_m(int *rows, int *columns, int UserInput)
{
	char s[80];
	int  i = 0, j = 0;
	double** m;

	if (UserInput)
	{
		printf("\nВведите кол-во строк: ");
		if (get_clean_str(s, sizeof(s)))
		{
			*rows = atof(s);
		}
		else
		{
			return 0;
		}

		printf("Введите кол-во столбцов: ");
		if (get_clean_str(s, sizeof(s)))
		{
			*columns = atof(s);
		}
		else
		{
			return 0;
		}
	}
																		
	m = (double**)malloc(*rows * sizeof(double*));          

	for (int i = 0; i < *rows; i++)
	{
		m[i] = (double*)malloc(*columns * sizeof(double));
	}
	printf("\n");
	return m;
	
}

double **calculate_m(double** m1, double** m2, int rows_m1, int columns_m1, int rows_m2, int columns_m2, int *rows_result, int *columns_result, char operation)
{
	int i = 0, j = 0, k = 0;
	double x = 0, **result_m = 0;

	switch (operation)
	{	
		case '*':
			if (columns_m1 == rows_m2)	
			{
				result_m = create_m(&rows_m1, &columns_m2, 0);
				for (i = 0; i < rows_m1; i++)
				{
					for (j = 0; j < columns_m2; j++)
					{
						x = 0;
						for (k = 0; k < columns_m1; k++)
						{
							x = x + (m1[i][k] * m2[k][j]);
						}
						result_m[i][j] = x;
					}
				}
				*columns_result = columns_m2;
				*rows_result = rows_m1;
			}
			else
			{
				printf("\nОшибка. Для операции \"*\" кол-во столбцов первой матрицы должно совпадать с кол-вом строк второй матрицы.\n");
			}
			break;
		
		case '+':
			if (columns_m1 == columns_m2 && rows_m1 == rows_m2)
			{
				result_m = create_m(&rows_m1, &columns_m1, 0);
				for (i = 0; i < rows_m1; i++)
				{
					for (j = 0; j < columns_m2; j++)
					{
						result_m[i][j] = m1[i][j] + m2[i][j];
					}
				}
				*columns_result = columns_m1;
				*rows_result = rows_m1;
			}
			else
			{
				printf("\nОшибка. Для операций \"+\" и \"-\" размеры матриц должны совпадать.\n");
			}
			break;
		
		case '-':
			if (columns_m1 == columns_m2 && rows_m1 == rows_m2)
			{
				result_m = create_m(&rows_m1, &columns_m1, 0);
				for (i = 0; i < rows_m1; i++)
				{
					for (j = 0; j < columns_m2; j++)
					{
						result_m[i][j] = m1[i][j] - m2[i][j];
					}
				}
				*columns_result = columns_m1;
				*rows_result = rows_m1;
			}
			else
			{
				printf("\nОшибка. Для операций \"+\" и \"-\" размеры матриц должны совпадать.\n");
			}
			break;
		
		default:
			printf("\nВведенная операция не предусмотрена\n");
			return 0;
	}

	return result_m;
}

void free_m(double **m, int rows)
{
	if (m == 0) return;

	int i;

	for (i = 0; i < rows; i++)
	{
		free(m[i]);
	}
	free(m);
}

//Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами 
//типа double(значения n и элементы массивов ввести с консоли).
//А также ввести с консоли знак операции : '+', '-' или '*'.Написать функцию, вычисляющую сумму, разность или 
//произведение данных матриц(их передать по указателю) и возвращающую указатель на массив - результат.Разместить эту 
//функцию в отдельном модуле.Выдать на консоль значения полученного вектора.