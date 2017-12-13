/**
 * Unity test template
 * main.c
 */

#include "functions.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c = 'D';
    int a = 2, b = 3;

    printf("Next letter from %c is %c\n",
        c, function_char_cycle(c, UP));
    printf("Previous letter from %c is %c\n",
        c, function_char_cycle(c, DOWN));

    printf("%d + %d = %d\n", a, b, function_add(a, b));

    return 0;
}
