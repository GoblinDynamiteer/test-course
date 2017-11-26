/*  Functions based on code from
    http://skansholm.com/CFranBorjan/funktioner/ */


#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "io.h"

bool io_input_value_float(float * val)
{
    char buff[IO_INPUT_BUFFER];

    if(io_read_line(buff, IO_INPUT_BUFFER))
    {
        return io_string_to_float(buff, val);
    }

    return false;
}

bool io_input_value_int(int * val)
{
    char buff[IO_INPUT_BUFFER];
    float temp;

    if(io_input_value_float(&temp))
    {
        *val = (int)temp;
        return true;
    }

    return false;
}

bool io_string_to_float(char * string, float * val)
{
    bool comma_found = false;

    /* If empty string */
    if(string[0] == '\n' || string[0] == '\0')
        return false;

    if(io_replace_comma(string) > 1 || !io_check_digit(string))
    {
        return false;
    }

    printf("BEfore sscanf: ");
    puts(string);
    /* Scan string for float value and return true */
    sscanf(string, "%f", val);
    return true;
}

bool io_check_digit(char * string)
{
    /* Iterate through string, check for errors */
    for(int i = 0; string[i] != '\0'; i++)
    {
        /* Non digit found in string */
        if( !isdigit(string[i]) &&
            !(string[i] == '.' || string[i] == ','))
        {
            return false;
        }
    }

    return true;
}

/* Replace commas with dots */
int io_replace_comma(char * string)
{
    int count = 0;

    for(int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == ',' || string[i] == '.')
        {
            string[i] = '.';
            count++;
        }
    }

    return count;
}

void io_skip_line()
{
    int c;
    while((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        ;
    }
}

bool io_remove_nl(char * a)
{
    int i = strlen(a) - 1;

    if(a[i] == '\n')
    {
        a[i] = '\0';
        return true;
    }

    return false;
}

bool io_read_line(char *a, int n)
{
    if(fgets(a, n, stdin) == NULL)
    {
        return false;
    }

    if(!io_remove_nl(a))
    {
        io_skip_line();
    }

    return true;
}
