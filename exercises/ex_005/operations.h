#ifndef OPERATIONS_H
#define OPERATIONS_H

#define INPUTS_MAX 20

typedef unsigned char uint8_t;

enum operation_id
{
    ADDITION,
    SUBTRACTION,
    DIVISION,
    MULTIPLICATION
};

double calculate(
    double * input_values, int input_count, int operaton_id);

char * result_to_string(
    double result, double * input_values, int input_count, int operaton_id);

#endif
