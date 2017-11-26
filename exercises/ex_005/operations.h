#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdbool.h>

#define OPERATION_INPUTS_MAX 20
#define OPERATION_INPUTS_MIN 2
#define OPERATIONS_MAX 5

#define OPERATION_MENU_ITEM_TO_ID(x) x-1

typedef unsigned char uint8_t;

enum operation_id
{
    ADDITION,
    SUBTRACTION,
    DIVISION,
    MULTIPLICATION,
    POWER_OF
};

typedef struct _struct_op_info
{
    uint8_t operation_id;
    char string_name[20];
    char sign;
    uint8_t max_inputs;
}operation_info;

float operation_calculate(
    float * input_values, int input_count, int operation_id);
char * operation_result_to_string(
    float result, float * input_values, int input_count, int operation_id,
    char * return_string);
void operation_print_name(int operation_id);
char operation_get_sign_char(int operation_id);
int operation_get_max_inputs(int operation_id);
bool operation_is_valid_id(int operation_id);
float operation_calculate_pow(float x, int y);

#endif
