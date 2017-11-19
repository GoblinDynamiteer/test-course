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

    Johan Kämpe
    Mjukvaruutvecklare inbyggda system
    MÖLK Utbildning
    */


#include <stdio.h>

#include "formulas.h"
#include "io.h"

int main()
{
    int user_menu_choice, formula_index;
    double formula_return_value;

    unit_info unit_info[] =
    {
        {VOLTAGE, "spänning", "volt", "V", 'U', 230, 0},
        {RESISTANCE, "resistans", "ohm", "ohm", 'R', 20000, 0},
        {CURRENT, "ström", "ampere", "A", 'I', 440, 0},
        {COS, "effektfaktor", "cos", "cos", 'e', 1, 0},
        {POWER, "effekt", "watt", "W", 'P', 0, 0},
        {VOLT_AMPERE, "skeneffekt", "volt ampere", "VA", 'S', 0, 0}
    };

    formula_info formula_info[] =
    {
        /* Args, formula input, formula output,
            formula function (2 or 3 args) */
        {OHMS_LAW, 2, {RESISTANCE, CURRENT}, VOLTAGE,
            formula_ohms_law, NULL},
        {RTOT, 3, {RESISTANCE, RESISTANCE, RESISTANCE}, RESISTANCE,
            NULL, formula_rtot},
        {POWER_CALC, 2, {VOLTAGE, CURRENT}, POWER,
            formula_power, NULL},
        {APPARANT_POWER_ONE_PHASE, 2, {VOLTAGE, CURRENT}, VOLT_AMPERE,
            formula_apparent_power, NULL},
        {REAL_POWER_ONE_PHASE, 3, {VOLTAGE, CURRENT, COS}, POWER,
            NULL, formula_actual_power},
        {APPARANT_POWER_THREE_PHASE, 2, {VOLTAGE, CURRENT}, VOLT_AMPERE,
            formula_apparent_power_three_phase, NULL},
        {REAL_POWER_THREE_PHASE, 3, {VOLTAGE, CURRENT, COS}, POWER,
            NULL, formula_actual_power_three_phase}
    };

    output_clear_screen();

    while(1)
    {
        output_display_main_menu();
        user_menu_choice = input_main_menu_user_selection();

        /* User entered invalid menu option */
        while(user_menu_choice == INPUT_MENU_OPTION_ERROR)
        {
            printf(STRING_ERROR_INPUT_WRONG_OPTION "\n");
            user_menu_choice = input_main_menu_user_selection();
        }

        /* User entered 0, quit program */
        if(user_menu_choice == INPUT_MENU_OPTION_QUIT)
        {
            return 0;
        }

        formula_index = user_menu_choice - 1;

        output_display_formula_info(formula_index);
        formula_return_value = formula_handler(
            &formula_info[formula_index], unit_info);

        unit_type formula_return_type = formula_info[formula_index].output;

        /* Prints result of formula calculation,
            example "P = 2.32W" */
        printf("%c = %0.2f%s",
            unit_info[formula_return_type].si_char,
            formula_return_value,
            unit_info[formula_return_type].value_char);
    }
}
