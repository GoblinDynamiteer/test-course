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

#define MAX_INPUT 2
#define NUM_OPERATIONS 4

int main(int argc, char const *argv[])
{
    operation_id op_id;
    double val[MAX_INPUT];
    bool correct_input;

    /* Set up pointer array to operator functions */
    double (*op_func[NUM_OPERATIONS])(double val1, double val2);
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
        printf("Enter two operands\n");
        for (int i = 0; i < MAX_INPUT; i++)
        {
            printf("Value %d: ", i + 1);

            do
            {
                correct_input = input_value(&val[i]);
                if(!correct_input)
                {
                    printf("Error! wrong input, try again\n");
                }
            }
            while(!correct_input);
        }

        printf("%.1lf %c %.1lf = %.1lf",
            val[0],
            get_operation_sign(op_id),
            val[1],
            (*op_func[op_id])(val[0], val[1]));
    }

    return 0;
}
