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

int main(int argc, char const *argv[])
{
    char num[INPUT_BUFFER];
    bool correct_input;
    char * gender_name[2] = { "male", "female" };

    while (1)
    {
        printf("Input social security number:\n");

        do
        {
            correct_input = number_input(num);

            if (!correct_input)
            {
                printf("Incorrect format, try again:\n");
            }
        }while (!correct_input);

        printf("Number belongs to a %s\n",
            gender_name[check_gender(num)]);

        printf("Age: %d\n", get_age(num));
        printf("Enter Y to enter a new number: ");

        if (!get_user_input_yes_no())
        {
            return 0;
        }
    }

}
