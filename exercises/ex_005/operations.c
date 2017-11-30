#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "io.h"
#include "operations.h"

operation_info op_info[] =
{
    { ADDITION,         "Addition",         '+',    OPERATION_INPUTS_MAX },
    { SUBTRACTION,      "Subtraction",      '-',    OPERATION_INPUTS_MAX },
    { MULTIPLICATION,   "Multiplication",   '*',    OPERATION_INPUTS_MAX },
    { DIVISION,         "Division",         '/',    OPERATION_INPUTS_MAX },
    { POWER_OF,         "Power of",         '^',    2 }
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

        if(operation_id == POWER_OF)
        {
            return operation_calculate_pow(
                input_values[0], (int)input_values[1]);
        }

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

/**
 * Handles pow calculations X^Y
 * @param x     X
 * @param y     Y
 * @return      Calculated value
 */
float operation_calculate_pow(float x, int y)
{
    /* If y is negative, division is used */
    bool neg = (y < 0);
    float retval = neg ? 1 : x;

    /* Inverse y, if negative */
    y = (y < 0) ? y * -1 : y;

    while(y--)
    {
        retval = neg ? retval / x : retval * x;
    }

    return retval;
}

char * operation_result_to_string(
    float result, float * input_values, int input_count, int operation_id,
    char * return_string)
{
    char string_add[IO_INPUT_BUFFER];
    char sign = operation_get_sign_char(operation_id);

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

/**
 * Prints math operation name
 * @param operation_id Math operation eg DIVISION, SUBTRACTION
 */
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

/**
 * Gets sign character for math op, eg + - / *
 * @param  operation_id Math operation eg DIVISION, SUBTRACTION
 * @return              Sign char for operation
 */
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

/**
 * Gets max user input values for math operation
 * @param  operation_id Math operation eg DIVISION, SUBTRACTION
 * @return              Max inputs for operation
 */
int operation_get_max_inputs(int operation_id)
{
    int n = sizeof(op_info) / sizeof(op_info[0]);
    for (int i = 0; i < n; i++)
    {
        if(op_info[i].operation_id == operation_id)
        {
            return op_info[i].max_inputs;
        }
    }

    printf(ERROR_STRING_OPERATION_NOT_FOUND);
    return '0';
}

/**
 * Check if pass id is a valid math operation
 * @param  operation_id Math operation eg DIVISION, SUBTRACTION
 * @return              Operation validity
 */
bool operation_is_valid_id(int operation_id)
{
    return (operation_id >= 0 && operation_id < OPERATIONS_MAX);
}
