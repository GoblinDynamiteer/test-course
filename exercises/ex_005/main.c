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
    int menu_item_selection, operation_id;
    float input[OPERATION_INPUTS_MAX], result;
    char result_string[IO_INPUT_BUFFER];
    bool run = true;

    while(run)
    {
        io_print_menu();
        io_input_value_int(&menu_item_selection);

        if(menu_item_selection == IO_MENU_QUIT_PROGRAM)
        {
            run = false;
        }

        else
        {
            operation_id = OPERATION_MENU_ITEM_TO_ID(menu_item_selection);

            if(!operation_is_valid_id(operation_id))
            {
                printf("Enter correct number e.g 1 - %d\n", OPERATIONS_MAX);
                continue;
            }

            printf("You entered ");
            operation_print_name(operation_id);
            printf("\n\n");

            printf("Enter first number: ");
            io_input_value_float(&input[0]);

            printf("Enter second number: ");
            io_input_value_float(&input[1]);

            result = operation_calculate(input, 2, operation_id);
            printf(operation_result_to_string(
                result, input, 2, operation_id, result_string));
        }
    }

    return 0;
}
