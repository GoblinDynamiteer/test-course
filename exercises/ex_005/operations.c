#include <stdio.h>
#include <string.h>
#include "io.h"
#include "operations.h"

operation_info op_info[] =
{
    { ADDITION,         "Addition",         '+' },
    { SUBTRACTION,      "Subtraction",      '-' },
    { MULTIPLICATION,   "Multiplication",   '*' },
    { DIVISION,         "Division",         '/' }
};

/**
 * Handles calculations
 * @param input_values Array of values
 * @param input_count Count of values in array to use
 * @param operation_id Math operation to use, eg DIVISION, SUBTRACTION
 * @return Calculated value
 */
float operation_calculate(
    float * input_values, int input_count, int operation_id)
    {
        int i = 0;
        float result = input_values[i++];

        for(; i < input_count; i++)
        {
            switch(operation_id)
            {
                case DIVISION:
                    result /= input_values[i];
                    break;

                case ADDITION:
                    result += input_values[i];
                    break;

                case SUBTRACTION:
                    result -= input_values[i];
                    break;

                case MULTIPLICATION:
                    result *= input_values[i];
                    break;

                default:
                    break;
            }
        }

        return result;
}

char * operation_result_to_string(
    float result, float * input_values, int input_count, int operation_id,
    char * return_string)
{
    char sign, string_add[IO_INPUT_BUFFER];

    switch(operation_id)
    {
        case DIVISION:
            sign = '/';
            break;

        case ADDITION:
            sign = '+';
            break;

        case SUBTRACTION:
            sign = '-';
            break;

        case MULTIPLICATION:
            sign = '*';
            break;

        default:
            break;
    }

    int i = 0;
    string_add[0] = '\0';
    return_string[0] = '\0';

    sprintf(string_add, "%0.2f %c ", input_values[i++], sign);
    strcat(return_string, string_add);

    for(; i < input_count; i++)
    {
        sprintf(string_add, "%0.2f %c ",
            input_values[i],
            i < input_count - 1 ? sign : '=');
        strcat(return_string, string_add);
    }

    sprintf(string_add, "%0.2f", result);
    strcat(return_string, string_add);

    return return_string;
}

void operation_print_name(int operation_id)
{
    int n = sizeof(op_info) / sizeof(op_info[0]);
    for (int i = 0; i < n; i++)
    {
        if(op_info[i].operation_id == operation_id)
        {
            printf(op_info[i].string_name);
            return;
        }
    }

    printf(ERROR_STRING_OPERATION_NOT_FOUND);
}

char operation_get_sign_char(int operation_id)
{
    int n = sizeof(op_info) / sizeof(op_info[0]);
    for (int i = 0; i < n; i++)
    {
        if(op_info[i].operation_id == operation_id)
        {
            return op_info[i].sign;
        }
    }

    printf(ERROR_STRING_OPERATION_NOT_FOUND);
    return '0';
}
