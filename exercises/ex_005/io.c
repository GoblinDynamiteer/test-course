/*  Functions based on code from
    http://skansholm.com/CFranBorjan/funktioner/ */


#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "operations.h"

/**
 * Prints main menu
 */
void io_print_menu(void)
{
    printf("\n");
    io_print_line();
    printf("\nEnter a number from the list below\n\n");

    for(int i = 0; i < OPERATIONS_MAX; i++)
    {
        printf("%i. ", i + 1);
        operation_print_name(i);
        printf("\n");
    }

    io_print_line();
    printf("\n%d. Quit program\n", IO_MENU_QUIT_PROGRAM);
    io_print_line();
    printf("\nEnter number: ");
}

/**
 * Prints a line at default lenght
 */
void io_print_line(void)
{
    io_print_char('-', IO_LINE_DEFAULT_LEN);
}

/**
 * Repeats char a number of times
 * @param c       Character to print
 * @param n       Number of times to print char
 */
void io_print_char(char c, int n)
{
    if(n < 0)
    {
        return;
    }

    n = n > IO_LINE_MAX_LEN ? IO_LINE_MAX_LEN : n;

    while(n--)
    {
        printf("%c", c);
    }
}

/**
 * Gets float input from user
 * @param val       Pointer to float variable
 *                  for storing value
 * @param d         Pointer to character variable
 *                  for storing first input char
 * @return          Input conversion success
 */
bool io_input_value_float(float * val, char * d)
{
    char buff[IO_INPUT_BUFFER];

    if(io_read_line(buff, IO_INPUT_BUFFER))
    {
        *d = buff[0];
        return io_string_to_float(buff, val);
    }

    return false;
}

/**
 * Gets integer input from user
 * @param val       Pointer to integer variable
 *                  for storing value
 * @return          Conversion success
 */
bool io_input_value_int(int * val)
{
    char buff[IO_INPUT_BUFFER], d;
    float temp;

    if(io_input_value_float(&temp, &d))
    {
        *val = (int)temp;
        return true;
    }

    return false;
}

/**
 * Converts string to float
 * @param string    String to convert
 * @param val       Pointer to float variable
 *                  for storing value
 * @return          Conversion success
 */
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

    /* Scan string for float value and return true */
    sscanf(string, "%f", val);
    return true;
}

/**
 * Checks if string is numeric
 * @param string    String to check
 * @return          Bool if numeric
 */
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

/**
 * Replaces commas with dots
 * @param string    String to replace commas in
 * @return          Number of commas replaced
 */
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

/**
 * Read user input to string
 * @param s         String buffer
 * @param n         String buffer size
 * @return          Read success
 */
bool io_read_line(char * s, int n)
{
    if(fgets(s, n, stdin) == NULL)
    {
        return false;
    }

    if(!io_remove_nl(s))
    {
        io_skip_line();
    }

    return true;
}
