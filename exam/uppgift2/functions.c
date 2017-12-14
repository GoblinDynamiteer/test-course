/**
 * For Exam
 * Test, verifiering och certifiering
 * Mjukvaruutvecklare inbyggda system
 * 2017-12-14
 *
 * By Johan Kampe
 */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Checks if a string is a valid social security number
 * @param  number Number as string
 * @return        True if valid, else false
 */
bool number_check(char * number)
{
    int len = strlen(number);
    return ((len == NUMBER_MAX_LENGTH) || (len == NUMBER_MIN_LENGTH));
}

/**
 * Checks gender of person holding social security number
 * @param  number Number as string
 * @return        Gender, either GENDER_MALE or GENDER_FEMALE
 */
int check_gender(char * number)
{
    int len = strlen(number);
    int digit = number[len-2] - '0';

    if (digit % 2)
    {
        return GENDER_MALE;
    }

    return GENDER_FEMALE;
}

/**
 * Get user input, for social security number
 * @param  number String to store number in
 * @return        True if valid number, else false
 */
bool number_input(char * number)
{
    fgets(number, INPUT_BUFFER, stdin);
    int len = strlen(number);

    if (number[len-1] == '\n')
    {
        number[len-1] = '\0';
    }

    return number_check(number);
}

/**
 * Asks user to enter string / char
 * @return  True if first char entered is y/Y, else false
 */
bool get_user_input_yes_no(void)
{
    char input[INPUT_BUFFER];
    fgets(input, INPUT_BUFFER, stdin);

    return (tolower(input[0]) == 'y');
}
