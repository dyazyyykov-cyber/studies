
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6.h"


void main()
{
	FILE *people, *target_people; 

	if (input(&people) || output(&target_people))
	{
		return;
	}
		
	check_year(&people, &target_people);
	
	fclose(people);
	fclose(target_people);

	return;
}




//Создать текстовый файл с записями следующего вида :
//Иванов Петр Сергеевич 1975
//Сидоров Николай Андреевич 1981
//….
//Воробьянинов Ипполит Матвеевич 1978
//
//Прочитать данные из этого файла и записать в другой только те строки, 
//которые относятся к родившимся позднее 1980 года.
