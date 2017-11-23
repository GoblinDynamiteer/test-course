#include "operations.h"
#include <stdio.h>
#include <string.h>

/**
 * Handles calculations
 * @param input_values Array of values
 * @param input_count Count of values in array to use
 * @param operaton_id Math operation to use, eg DIVISION, SUBTRACTION
 * @return Calculated value
 */
double calculate(
    double * input_values, int input_count, int operaton_id)
    {
        int i = 0;
        double result = input_values[i++];

        for(; i < input_count; i++)
        {
            switch(operaton_id)
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

char * result_to_string(
    double result, double * input_values, int input_count, int operaton_id,
    char * return_string)
{
    char sign, string_add[STRING_BUFFER];

    switch(operaton_id)
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
