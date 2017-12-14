/**
 * For Exam,
 * By Johan Kampe
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool number_check(char * number)
{
    int len = strlen(number);
    return ((len == NUMBER_MAX_LENGTH) || (len == NUMBER_MIN_LENGTH));
}

int check_gender(char * number)
{
    int len = strlen(number);
    int digit = number[len-2] - '0';

    if(digit % 2)
    {
        return GENDER_MALE;
    }

    return GENDER_FEMALE;
}

bool number_input(char * number)
{
    fgets(number, INPUT_BUFFER, stdin);
    int len = strlen(number);

    if(number[len-1] == '\n')
    {
        number[len-1] = '\0';
    }

    return number_check(number);
}

bool get_user_input_yes_no(void)
{
    char input[INPUT_BUFFER];
    fgets(input, INPUT_BUFFER, stdin);

    return (tolower(input[0]) == 'y');
}
