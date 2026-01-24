#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "lab5.h"

void main()
{
	int rows_m1 = 0, columns_m1 = 0, rows_m2 = 0, columns_m2 = 0, rows_result = 0, columns_result = 0, operation = 0;
	double **m1, **m2, **result_m;
	char s[80];

	setlocale(LC_ALL, "");
	
	printf("Введите первую матрицу: \n");
	m1 = create_m(&rows_m1, &columns_m1, 1);
	input_m(m1, rows_m1, columns_m1);
	print_m(m1, rows_m1, columns_m1);
	
	printf("\nВведите вторую матрицу: \n");
	m2 = create_m(&rows_m2, &columns_m2, 1);
	input_m(m2, rows_m2, columns_m2);
	printf(m2, rows_m2, columns_m2);

	rows_result = rows_m1;
	columns_result = columns_m2;
	result_m = create_m(&rows_result, &columns_result, 0);

	while (1)
	{
		printf("\nВведите операцию \"*\", \"+\" или \"-\": ");
		if (get_clean_str(s, sizeof(s)))
		{
			int operation = 0;

			if (s[0] == '*')
			{

			}
			calculate_m(m1, m2, result_m, rows_m1, columns_m1, rows_m2, columns_m2, );
		}
	}
		
}





//Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами 
//типа double(значения n и элементы массивов ввести с консоли).
//А также ввести с консоли знак операции : '+', '-' или '*'.Написать функцию, вычисляющую сумму, разность или 
//произведение данных матриц(их передать по указателю) и возвращающую указатель на массив - результат.Разместить эту 
//функцию в отдельном модуле.Выдать на консоль значения полученного вектора.