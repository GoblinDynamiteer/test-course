#ifndef IO_H
#define IO_H

#include <stdbool.h>

#define IO_INPUT_BUFFER 128
#define IO_LINE_MAX_LEN 100
#define IO_LINE_DEFAULT_LEN 40
#define IO_MENU_QUIT_PROGRAM 0

#define ERROR_STRING_PREFIX "ERROR: "
#define ERROR_STRING_OPERATION_NOT_FOUND ERROR_STRING_PREFIX \
    "Operation not found"
#define ERRROR_STRING_NOT_ENOUGH_NUMBERS ERROR_STRING_PREFIX \
    "Enter at least two numbers!\n"
#define ERRROR_STRING_INCORRECT_INPUT ERROR_STRING_PREFIX \
    "Incorrect input! Try again.\n"
#define ERROR_STRING_INCORRECT_MENU_OPTION ERROR_STRING_PREFIX \
    "Enter correct number e.g 1 - "
#define INFO_STRING_NUMBER_INPUT_BEGIN \
    "Enter numbers for calculation (Max 20).\n" \
    "Input character 'd' when done\n\n"

void io_skip_line();
bool io_remove_nl(char *a);
bool io_read_line(char *a, int n);
bool io_input_value_float(float * val, char * d);
int io_replace_comma(char * string);
bool io_check_digit(char * string);
bool io_string_to_float(char * string, float * val);
bool io_input_value_int(int * val);
void io_print_menu(void);
void io_print_char(char c, int n);
void io_print_line(void);

#endif
