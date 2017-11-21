/*  Refactoring exercise for course "Testning"
    Refactor code build by student in first programming course

    https://github.com/GoblinDynamiteer/
    test-course/tree/master/exercises/ex_004

    Original code in /original/main2.c

    Refactoring done:
        - Created functions for various ouput/input
        - Use structs for keeping unit info and limits:
            Voltage, Current etc.
        - Use structs for keeping formula calculation info:
            unit input type(s), output type etc, formula calc.
        - Use pointers to formula functions
        - Renaming of functions and variables
        - Added unity tests for formula handler function
        - Auto generate main menu

    Refactoring test:
        Added formula for calculating rtot for resistors in series.

    Otherwise the original program function and output is kept,
    with minor alteratioins.

    Johan Kämpe
    Mjukvaruutvecklare inbyggda system
    MÖLK Utbildning
    */

#include <stdio.h>
#include <stdlib.h>
#include "formulas.h"
#include "io.h"
#include "list.h"

int main()
{
    /* Formula index, size, retval */
    int menu_select, f_index, f_size;
    double f_retval;

    /* Scruct containing info about types used by formulas */
    unit_info unit_info[] =
    {
        {VOLTAGE, "spänning", "volt", "V", 'U', 230, 0},
        {RESISTANCE, "resistans", "ohm", "ohm", 'R', 20000, 0},
        {CURRENT, "ström", "ampere", "A", 'I', 440, 0},
        {COS, "effektfaktor", "cos", "cos", 'e', 1, 0},
        {POWER, "effekt", "watt", "W", 'P', 0, 0},
        {VOLT_AMPERE, "skeneffekt", "volt ampere", "VA", 'S', 0, 0}
    };

    formula_info * test_array = NULL;
    test_array = list_init_formulas(test_array);

    while(test_array != NULL)
    {
        puts(test_array->name);
        test_array = test_array->next;
    }
}
