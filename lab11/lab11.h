#ifndef hero
#define hero


typedef struct {
    double sum;
    double max;
    double min;
    double average;
} Result;

Result calculate(int count, ...);

#endif