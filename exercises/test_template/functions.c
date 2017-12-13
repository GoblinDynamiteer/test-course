/**
 * Unity test template
 * functions.c
 *
 * By Johan Kampe
 */

#include "functions.h"

int function_add(int a, int b)
{
    return a + b;
}

char function_char_cycle(char c, bool direction)
{
    return (direction ? c + 1 : c - 1);
}
