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

    double (*op_func[4])(double val1, double val2);
    op_func[ADDITION] =       operation_add;
    op_func[SUBTRACTION] =    operation_subtract;
    op_func[MULTIPLICATION] = operation_multiply;
    op_func[DIVISION] =       operation_divide;

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

        printf("%.1lf %c %.1lf = %.1lf",
            val1,
            get_operation_sign(op_id),
            val2,
            (*op_func[op_id])(val1, val2));
    }

    return 0;
}
