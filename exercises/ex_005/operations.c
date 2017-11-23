#include "operations.h"

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
