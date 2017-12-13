/**
 * Calc operations functions source
 * functions.c
 *
 * By Johan Kampe
 */

#include "functions.h"

double operation_add(double a, double b)
{
    return a + b;
}

double operation_subtract(double a, double b)
{
    return a - b;
}

double operation_multiply(double a, double b)
{
    return a * b;
}

double operation_divide(double a, double b)
{
    if(b == 0.0)
    {
        return 0.0;
    }
    
    return a / b;
}
