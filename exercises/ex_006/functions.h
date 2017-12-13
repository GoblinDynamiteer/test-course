/**
 * Calc operations functions header
 * functions.h
 *
 * By Johan Kampe
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

typedef enum
{
    ADDITION,
    DIVISION,
    MULTIPLICATION,
    SUBTRACTION,
    ERROR_OP_NOT_FOUND
} operation_id;

double operation_add(double a, double b);
double operation_subtract(double a, double b);
double operation_multiply(double a, double b);
double operation_divide(double a, double b);
operation_id input_operation(void);
char get_operation_sign(operation_id id);
bool input_value(double * val);

#endif
