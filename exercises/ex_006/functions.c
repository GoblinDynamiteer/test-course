/**
 * Calc operations functions source
 * functions.c
 *
 * By Johan Kampe
 */

#include "functions.h"

/**
 * Add two numbers and return result
 * @param  a Number 1
 * @param  b Number 2
 * @return   Result
 */
double operation_add(double a, double b)
{
    return a + b;
}

/**
 * Subtract two numbers and return result
 * @param  a Number 1
 * @param  b Number 2
 * @return   Result
 */
double operation_subtract(double a, double b)
{
    return a - b;
}

/**
 * Multiply two numbers and return result
 * @param  a Number 1
 * @param  b Number 2
 * @return   Result
 */
double operation_multiply(double a, double b)
{
    return a * b;
}

/**
 * Divide two numbers and return result
 * @param  a Number 1
 * @param  b Number 2
 * @return   Result
 */
double operation_divide(double a, double b)
{
    if(b == 0.0)
    {
        return 0.0;
    }

    return a / b;
}

operation_id input_operation(void)
{
    return -1;
}
