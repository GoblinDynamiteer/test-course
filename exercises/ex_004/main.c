/*  Refactoring exercise for course "Testning"
    Refactor code build by student in first programming course

    https://github.com/GoblinDynamiteer/
    test-course/tree/master/exercises/ex_004

    Original code in /original/main2.c

    Refactoring done:
        - Created functions for various ouput/input
        - Use structs for keeping unit info and limits:
            Voltage, Current etc.
            Kept in array
        - Use structs for keeping formula calculation info:
            unit input type(s), output type etc, formula calc.
            Kept in linked list
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
    int menu_select, f_index;

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

    /* Linked list containing info about formulas */
    formula_info * f_info = NULL;
    f_info = formula_init_formulas(f_info);

    output_clear_screen();

    while(1)
    {
        output_display_main_menu(f_info);
        menu_select = input_main_menu_user_selection(f_info);

        /* User entered invalid menu option */
        while(menu_select == INPUT_MENU_OPTION_ERROR)
        {
            printf(STRING_ERROR_INPUT_WRONG_OPTION "\n");
            menu_select = input_main_menu_user_selection(f_info);
        }

        /* User entered 0, quit program */
        if(menu_select == INPUT_MENU_OPTION_QUIT)
        {
            return 0;
        }

        /* Formula struct info index starts at zero, hence -1 */
        f_index = menu_select - 1;

        /* Display info about formula */
        output_display_formula_info(f_info, f_index);

        /* Get user input, and calculate value of selected formula */
        formula_handler(f_info, f_index, unit_info);
    }
}
