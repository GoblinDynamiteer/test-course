/*  Program asks for user input:
    temperature in fahrenheit

    prints temperature in degrees, with one decimal
    precision.

    */

#include <stdio.h>
#include <stdlib.h> // system()
#include <stdbool.h>

/* Macro that converts temperatures in fahrenheit to celcius */
#define FAHRENHEIT_TO_CELCIUS(x) ((x - 32.0) * (double)(5.0/9.0))

void print_program_title(void);
bool get_user_input_fahrenheit(double * temp);
bool get_user_input_yes_no(void);

int main(int argc, char const *argv[])
{
    double temp_celc;

    while(1)
    {
        system("cls"); // Clear screen (Windows)
        print_program_title();
        if(get_user_input_fahrenheit(&temp_celc))
        {
            printf("Temperaturen är %.1f C\n",
                FAHRENHEIT_TO_CELCIUS(temp_celc));
        }

        else
        {
            printf("Fel inmatning!\n");
        }

        /* Break loop if user choses not to continue */
        if(!get_user_input_yes_no())
        {
            break;
        }

    }

    return 0;
}

/*  function print_program_title
    desc: Print program title
    args: none
    retval: none
 */
void print_program_title(void)
{
    printf("FAHRENHEIT - CELCIUS\n"
           "====================\n\n");
}

/*  function get_user_input_fahrenheit
    desc: Ask user for input; temperature in fahrenheit
    args: pointer (double) converted value
    retval: conversion success
 */
bool get_user_input_fahrenheit(double * temp)
{
    char input[50];

    printf("Ange temperaturen i Fahrenheit :  ");
    fgets(input, 50, stdin);

    if(sscanf(input, "%lf", temp) != 1)
    {
        return false;
    }

    return true;
}

/*  function get_user_input_yes_no
    desc: Ask user for input; J/N
    args: none
    retval: true if user input begins with char 'J'
 */
bool get_user_input_yes_no(void)
{
    char input[50];
    printf("\n\nEn gång till (J/N)? ");
    fgets(input, 50, stdin);

    while (getchar() != '\n');

    return (input[0] == 'J');
}
