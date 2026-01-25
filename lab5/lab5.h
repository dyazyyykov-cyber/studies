#ifndef HEADHERO_H
#define HEADHERO_H


char* get_clean_str(char* s, int size);
void print_m(double** m, int rows, int columns);
void input_m(double** m, int rows, int columns);
double** create_m(int* rows, int* columns, int UserInput);
double** calculate_m(double** m1, double** m2, int rows_m1, int columns_m1, int rows_m2, int columns_m2, int* rows_result, int* columns_result, char operation);
void free_m(double** m, int rows);

#endif // !HEADHERO_H
