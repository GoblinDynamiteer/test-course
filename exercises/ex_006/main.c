/**
 * Calc operations main file
 * TDD / Refactor exercise
 * based on code from
 * https://www.programiz.com/c-programming/c-switch-case-statement
 *
 * main.c
 *
 * By Johan Kampe
 */

#include <stdio.h>
#include "functions.h"

int main(int argc, char const *argv[])
{
    operation_id op_id;
    double val1, val2;

    printf("Enter an operator (+, -, *, /): ");
    op_id = input_operation();

    if(op_id == ERROR_OP_NOT_FOUND)
    {
        printf("Error! operator is not correct");
    }

    else
    {
        printf("Enter two operands: ");
        scanf("%lf %lf", &val1, &val2);

        switch(op_id)
        {
            case ADDITION:
                printf("%.1lf + %.1lf = %.1lf",
                    val1, val2, operation_add(val1, val2));
                break;

            case SUBTRACTION:
                printf("%.1lf - %.1lf = %.1lf",
                    val1, val2, operation_subtract(val1, val2));
                break;

            case MULTIPLICATION:
                printf("%.1lf * %.1lf = %.1lf",
                    val1, val2, operation_multiply(val1, val2));
                break;

            case DIVISION:
                printf("%.1lf / %.1lf = %.1lf",
                    val1, val2, operation_divide(val1, val2));
                break;

            default:
                break;
        }
    }

    return 0;
}
