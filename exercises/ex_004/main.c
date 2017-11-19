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

    /* Struct array containing info about formulas */
    formula_info formula_info[] =
    {
        {OHMS_LAW, "OHMS LAG", // Id and name
        "Ohms lag spänningen(volt/V) betäckning U " // Info
        "lika med Resistansen(Ohm) betäckning R \n"
        "gånger Strömmen(Ampere) med betäckningen I. "
        "Kort U=R*I. \n\n",
        2, {RESISTANCE, CURRENT}, VOLTAGE,  // Input & output type
        formula_ohms_law, NULL}, // Pointer to formula function

        {RTOT, "RTOT PARALLELL",
        "Resistans sammankopplade i parallella kretsar är "
        "lika med 1 delat Resistans R total är lika med\n"
        "Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder "
        "tre resistanser.\n\n",
        3, {RESISTANCE, RESISTANCE, RESISTANCE}, RESISTANCE,
        NULL, formula_rtot},

        {RTOT_SERIES, "RTOT SERIE",
        "Resistans sammankopplade i seriekretsar är "
        "summan av delresistanserna R1 R2 och R3.\n\n",
        3, {RESISTANCE, RESISTANCE, RESISTANCE}, RESISTANCE,
        NULL, formula_rtot_series},

        {POWER_CALC, "EFFEKTLAGEN ENKEL",
        "Effektlagen enkel för likström är effekten P i Watt (W)"
        "lika med spänningen U i volt(V)\n"
        "gånger strömmen I i Ampere(A): \n\n",
        2, {VOLTAGE, CURRENT}, POWER,
        formula_power, NULL},

        {APPARANT_POWER_ONE_PHASE, "SKENBAR EFFEKT ENFAS",
        "Skenbar effekt enfas räknas med storheten VA(VoltAmpere)"
        "som är lika med spänningen U i volt(V)\n"
        "gånger strömmen I i ampere(A)\n\n",
        2, {VOLTAGE, CURRENT}, VOLT_AMPERE,
        formula_apparent_power, NULL},

        {REAL_POWER_ONE_PHASE, "AKTIV EFFEKT/MEDELEFFEKT ENFAS",
        "Aktiv medelefdekt enfas är lika med effekt P i watt(W)"
        "lika med spänningen U i volt(V) gånger strömmen I \n"
        "i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n",
        3, {VOLTAGE, CURRENT, COS}, POWER,
        NULL, formula_actual_power},

        {APPARANT_POWER_THREE_PHASE, "SKENBAR EFFEKT 3-FAS",
        "3-fas skenbar effekt är växelspänning är skenbar effekt S "
        "i voltampere(VA) lika med spänningen U i volt(V) \n"
        "gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n",
        2, {VOLTAGE, CURRENT}, VOLT_AMPERE,
        formula_apparent_power_three_phase, NULL},

        {REAL_POWER_THREE_PHASE, "AKTIV EFFEKT 3-FAS",
        "3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen"
        "U i volt(V) gånger strömmen I i ampere(A)\n"
        "gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n",
        3, {VOLTAGE, CURRENT, COS}, POWER,
        NULL, formula_actual_power_three_phase}
    };

    output_clear_screen();
    f_size = sizeof(formula_info)/sizeof(formula_info[0]);

    while(1)
    {
        output_display_main_menu(formula_info, f_size);
        menu_select = input_main_menu_user_selection(f_size);

        /* User entered invalid menu option */
        while(menu_select == INPUT_MENU_OPTION_ERROR)
        {
            printf(STRING_ERROR_INPUT_WRONG_OPTION "\n");
            menu_select = input_main_menu_user_selection(f_size);
        }

        /* User entered 0, quit program */
        if(menu_select == INPUT_MENU_OPTION_QUIT)
        {
            return 0;
        }

        /* Formula struct info index starts at zero, hence -1 */
        f_index = menu_select - 1;

        /* Display info about formula */
        output_display_formula_info(&formula_info[f_index]);
        f_retval = formula_handler(&formula_info[f_index], unit_info);
        unit_type f_ret_type = formula_info[f_index].output;

        /* Prints result of formula calculation,
            example "P = 2.32W" */
        printf("%c = %0.2f%s",
            unit_info[f_ret_type].si_char,
            f_retval,
            unit_info[f_ret_type].value_char);
    }
}
