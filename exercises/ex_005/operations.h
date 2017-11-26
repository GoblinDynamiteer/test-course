#ifndef OPERATIONS_H
#define OPERATIONS_H

#define INPUTS_MAX 20
#define OPERATIONS_MAX 4

typedef unsigned char uint8_t;

enum operation_id
{
    ADDITION,
    SUBTRACTION,
    DIVISION,
    MULTIPLICATION
};

typedef struct _struct_op_info
{
    int operation_id;
    char string_name[20];
    char sign;
}operation_info;

float operation_calculate(
    float * input_values, int input_count, int operation_id);
char * operation_result_to_string(
    float result, float * input_values, int input_count, int operation_id,
    char * return_string);
void operation_print_name(int operation_id);
char operation_get_sign_char(int operation_id);

#endif
