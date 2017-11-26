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
#include <ctype.h>
#include "operations.h"
#include "io.h"

int main()
{
    int menu_item_selection, operation_id, input_count;
    float input[OPERATION_INPUTS_MAX], result;
    char result_string[IO_INPUT_BUFFER], done;
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
            input_count = 0;

            if(!operation_is_valid_id(operation_id))
            {
                printf(ERROR_STRING_INCORRECT_MENU_OPTION "%d\n",
                    OPERATIONS_MAX);
                continue;
            }

            printf("You entered ");
            operation_print_name(operation_id);
            printf("\n\n");

            printf(INFO_STRING_NUMBER_INPUT_BEGIN);
            while(input_count < OPERATION_INPUTS_MAX)
            {
                printf("\nEnter number %d: ", input_count + 1);
                if(io_input_value_float(&input[input_count], &done))
                {
                    input_count++;
                }

                /* User entered d/D, to indicate end of number input */
                else if(tolower(done) == 'd')
                {
                    if(input_count < OPERATION_INPUTS_MIN)
                    {
                        printf(ERRROR_STRING_NOT_ENOUGH_NUMBERS);
                        continue;
                    }

                    break;
                }

                else
                {
                    printf(ERRROR_STRING_INCORRECT_INPUT);
                }
            }

            result = operation_calculate(input, input_count, operation_id);
            io_print_line();
            printf("\nResult: ");
            printf("\n");
            printf(operation_result_to_string(
                result, input, input_count, operation_id, result_string));
            io_wait_return();
        }
    }

    return 0;
}
