/*  Refactoring exercise for course "Testning"
    Refactor code build by student in first programming course

    GitHub:
    https://github.com/GoblinDynamiteer/
        test-course/tree/master/exercises/ex_005

    Original code in '/original/main.c' and on web
    https://codereview.stackexchange.com/
        questions/91740/simple-calculator-in-c

*/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "io.h"

int main()
{
    int menu;
    float input[INPUTS_MAX], result;
    char result_string[IO_INPUT_BUFFER];

    io_print_menu();
    io_input_value_int(&menu);

    switch(menu)
    {
    case 1:
        printf("You entered Addition\n\n");

        printf("Enter first number: ");
        io_input_value_float(&input[0]);

        printf("Enter second number: ");
        io_input_value_float(&input[1]);

        printf("\n");

        result = operation_calculate(input, 2, ADDITION);
        printf(operation_result_to_string(
            result, input, 2, ADDITION, result_string));

        break;
    case 2:
        printf("You entered Subtraction\n\n");

        printf("Enter first number: ");
        io_input_value_float(&input[0]);

        printf("Enter second number: ");
        io_input_value_float(&input[1]);

        printf("\n");

        result = operation_calculate(input, 2, SUBTRACTION);

        printf(operation_result_to_string(
            result, input, 2, SUBTRACTION, result_string));
        break;
    case 3:
        printf("You entered Multiplication\n\n");

        printf("Enter first number: ");
        io_input_value_float(&input[0]);

        printf("Enter second number: ");
        io_input_value_float(&input[1]);

        printf("\n");

        result = operation_calculate(input, 2, MULTIPLICATION);

        printf(operation_result_to_string(
            result, input, 2, MULTIPLICATION, result_string));
        break;
    case 4:
        printf("You entered Division\n\n");

        printf("Enter first number: ");
        io_input_value_float(&input[0]);

        printf("Enter second number: ");
        io_input_value_float(&input[1]);

        printf("\n");

        result = operation_calculate(input, 2, DIVISION);

        printf(operation_result_to_string(
            result, input, 2, DIVISION, result_string));
        break;
    default:
        printf("Enter correct number e.g 1 - 4\n");
        break;
    }
    return 0;
}
