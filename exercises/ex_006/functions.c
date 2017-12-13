/**
 * Calc operations functions source
 * functions.c
 *
 * By Johan Kampe
 */

#include "functions.h"
#include <stdio.h>

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
    char input;
    int c = scanf("%c", &input);

    operation_id id[] =
    {
        ADDITION,
        DIVISION,
        MULTIPLICATION,
        SUBTRACTION
    };

    char sign[] = { '+', '/', '*', '-' };

    if(c == 1)
    {
        for (int i = 0; i < sizeof(sign) / sizeof(char); i++)
        {
            if(input == sign[i])
            {
                return id[i];
            }
        }
    }

    return ERROR_OP_NOT_FOUND;
}

char get_operation_sign(operation_id id)
{
    char sign[] = { '+', '/', '*', '-' };

    operation_id op_id[] =
    {
        ADDITION,
        DIVISION,
        MULTIPLICATION,
        SUBTRACTION
    };

    for (int i = 0; i < sizeof(op_id) / sizeof(operation_id); i++)
    {
        if(id == op_id[i])
        {
            return sign[i];
        }
    }

    return '0';
}

bool input_value(double * val)
{
    double d;

    if(scanf("%lf", &d) != 1)
    {
        return 0.0f;
    }

    return d;
}
