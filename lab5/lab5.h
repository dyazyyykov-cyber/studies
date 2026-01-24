#ifndef HEADHERO_H
#define HEADHERO_H


char* get_clean_str(char* s, int size);
void print_m(double** m, int rows, int columns);
void input_m(double** m, int rows, int columns);
char** create_m(int* rows, int* columns, int UserInput);
double calculate_m(double** m1, double** m2, double** result_m, int rows_m1, int columns_m1, int rows_m2, int columns_m2, int operation);

#endif // !HEADHERO_H
