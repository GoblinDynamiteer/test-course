#ifndef IO_H
#define IO_H

#include <stdbool.h>

#define IO_INPUT_BUFFER 128

void io_skip_line();
bool io_remove_nl(char *a);
bool io_read_line(char *a, int n);
bool io_input_value_float(float * val);
int io_replace_comma(char * string);
bool io_check_digit(char * string);
bool io_string_to_float(char * string, float * val);
bool io_input_value_int(int * val);

#endif
