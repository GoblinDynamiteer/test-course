#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include "formulas.h"
#include "io.h"

int main()
{
    system("chcp 1252");
    system("cls");
    int user_menu_choice;

    unit_info unit_info[] =
    {
        {"spänning", "volt", "V", 'U', 230, 0},
        {"resistans", "ohm", "ohm", 'R', 20000, 0},
        {"ström", "ampere", "A", 'I', 440, 0},
        {"effektfaktor", "cos", "cos", 'e', 1, 0},
        {"effekt", "watt", "W", 'P', 0, 0}
    };

    formula_info formula_info[] =
    {
        /* Args, formula input, formula output, formula function (2 or 3 args) */
        {OHMS_LAW, 2, {RESISTANCE, CURRENT}, VOLTAGE,
            formula_ohms_law, NULL},
        {RTOT, 3, {RESISTANCE, RESISTANCE, RESISTANCE}, RESISTANCE,
            NULL, formula_rtot},
        {EFFECT_CALC_SIMPLE, 2, {VOLTAGE, CURRENT}, POWER,
            formula_effect_simple, NULL},
        {EFFECT_CALC_ONE_PHASE, 2, {VOLTAGE, CURRENT}, POWER,
            formula_apparent_power, NULL},
        {APPARANT_POWER_ONE_PHASE, 3, {VOLTAGE, CURRENT, COS}, POWER,
            NULL, formula_actual_power},
        {REAL_POWER_THREE_PHASE, 2, {VOLTAGE, CURRENT}, POWER,
            formula_apparent_power_three_phase, NULL},
        {APPARANT_POWER_THREE_PHASE, 3, {VOLTAGE, CURRENT, COS}, POWER,
            NULL, formula_actual_power_three_phase}
    };

    while(1)
    {
        output_display_main_menu();
        user_menu_choice = input_main_menu_user_selection();

        /* User entered invalid menu option */
        while(user_menu_choice == INPUT_MENU_OPTION_ERROR)
        {
            printf("Fel alternativ försök igen!: \n");
            user_menu_choice = input_main_menu_user_selection();
        }

        /* Quit program */
        if(user_menu_choice == 0)
        {
            return 0;
        }

        user_menu_choice--;
        output_display_selection_info(user_menu_choice);
        printf("%lf V\n", formula_handler(
            &formula_info[user_menu_choice], unit_info));
    }
}
