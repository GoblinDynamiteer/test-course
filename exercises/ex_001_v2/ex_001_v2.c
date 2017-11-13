/*
    Exercise 01 for course 'Test, verifiering och certifiering'

    Convert temperature fahrenheit -> celcius
    in:     User-entered string
    out:    converted temperatue

    Assert tests:
    01: 32°F = 0°C
    02: 212°F = 100°C
    03: Mata in en bokstav istället för en siffra
    04: 73.5 °F = 23.1 °C (obs rätt antal decimaler)
    05: 400 °F = 204.4 °C (obs rätt antal decimaler)
    06: Antalet =-tecken = 20
    07: å och ä saknas
    08: Blir det fortfarande rätt om ni matar in , istället för punkt?
    09: Går det köra programmet flera gånger? (fungerar både j och J? )
    10: Rensas skärmen mellan varje körning?
    11: Är koden kommenterad?
    12: Är koden uppdelad i funktioner?

    by
    Johan Kämpe
    Mjukvaruutvecklare inyggda system
    MÖLK Utbildning
    */

#include <stdio.h>
#include <stdlib.h>     // system
#include <stdbool.h>    // bool
#include <ctype.h>      // tolower, isdigit

/* Macro that converts temperatures in fahrenheit to celcius */
#define FAHRENHEIT_TO_CELCIUS(t) ((t - 32.0) * (double)(5.0/9.0))

#define INPUT_BUFFER 200

void print_program_title(void);
bool get_user_input_fahrenheit(double * temp);
bool get_user_input_yes_no(void);
bool str_to_dbl(char * string, double * value);

int main(int argc, char const *argv[])
{
    double temp_celc;

    while(1)
    {
        system("chcp 1252");    // Set code page to West European Latin
        system("cls");          // Clear screen (Windows)
        print_program_title();

        /* If user enters correct string (convertable value) */
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

/*  function    print_program_title
    desc:       Prints program title */
void print_program_title(void)
{
    printf("FAHRENHEIT - CELCIUS\n"
           "====================\n\n");
}

/*  function    get_user_input_fahrenheit
    desc:       Ask user for input; temperature in fahrenheit
    arg1:       Pointer to output temperature variable
    retval:     True if conversion successful  */
bool get_user_input_fahrenheit(double * temp)
{
    char input[INPUT_BUFFER];

    printf("Ange temperaturen i Fahrenheit :  ");
    fgets(input, INPUT_BUFFER, stdin);

    return str_to_dbl(input, temp);
}

/*  function        get_user_input_yes_no
    desc:           Ask user for input: J/N
    retval:         True if Y/y, else false */
bool get_user_input_yes_no(void)
{
    char input[INPUT_BUFFER];
    printf("\n\nEn gång till (J/N)? ");

    fgets(input, INPUT_BUFFER, stdin);

    return (tolower(input[0]) == 'j');
}

/*  function        str_to_dbl
    desc:           Convert string input to double
    arg1:           User-entered string (should be temperature)
    arg2:           Pointer to output temperature variable
    retval:         true if user input begins with char 'J' / 'j' */
bool str_to_dbl(char * string, double * value)
{
    bool comma_found = false;

    /* If empty string */
    if(string[0] == '\n' || string[0] == '\0')
        return false;

    /* Iterate through string, check for errors */
    for(int i = 0; string[i] != '\n'; i++)
    {
        if(!comma_found && (string[i] == '.' || string[i] == ','))
        {
            /* Replace comma with dots, for sscanf conversion */
            string[i++] = '.';
            /* Assert there is only 1 (one) point or comma */
            comma_found = true;
        }

        /* Non digit found in string */
        if(!isdigit(string[i]))
        {
            return false;
        }
    }

    /* Scan string for double value and return true */
    sscanf(string, "%lf", value);
    return true;
}
