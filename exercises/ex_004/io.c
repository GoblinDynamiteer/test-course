#include "io.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // itoa

/**
 * Print main menu.
 */
void output_display_main_menu(void)
{
    static const char * string_menu_title =
        "Välj vilka storheter du vill beräkna:";

    static const char * string_menu_option[] =
    {
        "OHMS LAG",
        "Rtot",
        "EFFEKTLAGEN ENKEL",
        "SKENBAR EFFEKT ENFAS",
        "AKTIV EFFEKT/MEDELEFFEKT ENFAS",
        "SKENBAR EFFEKT 3-FAS",
        "AKTIV EFFEKT 3-FAS",
        "FÖR ATT AVSLUTA"
    };

    printf("\n%s\n", string_menu_title);

    for(int i = 0; i < MENU_ITEMS_MAX; i++)
    {
        printf("Välj %d för: %s\n",
            i == QUIT_PROGRAM ? 0 : (i + 1), // Exit is menu option 0
            string_menu_option[i]);
    }
}

/**
 * Print information about formula.
 */
void output_display_formula_info(int menu_item)
{
    static const char * string_menu_help[] =
    {
        "Ohms lag spänningen(volt/V) betäckning U "
        "lika med Resistansen(Ohm) betäckning R \n"
        "gånger Strömmen(Ampere) med betäckningen I. "
        "Kort U=R*I. \n\n",

        "Resistans sammankopplade i parallella kretsar är "
        "lika med 1 delat Resistans R total är lika med\n"
        "Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder "
        "tre resistanser.\n\n",

        "Effektlagen enkel för likström är effekten P i Watt (W)"
        "lika med spänningen U i volt(V)\n"
        "gånger strömmen I i Ampere(A): \n\n",

        "Skenbar effekt enfas räknas med storheten VA(VoltAmpere)"
        "som är lika med spänningen U i volt(V)\n"
        "gånger strömmen I i ampere(A)\n\n",

        "Aktiv medelefdekt enfas är lika med effekt P i watt(W)"
        "lika med spänningen U i volt(V) gånger strömmen I \n"
        "i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n",

        "3-fas skenbar effekt är växelspänning är skenbar effekt S "
        "i voltampere(VA) lika med spänningen U i volt(V) \n"
        "gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n",

        "3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen"
        "U i volt(V) gånger strömmen I i ampere(A)\n"
        "gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n"
    };

    printf(string_menu_help[menu_item]);
}

/**
 * Handles user input, for menu choice
 * @return User menu item selection, as a number
 */
int input_main_menu_user_selection(void)
{
    char input_string[INPUT_CHAR_BUFFER_SIZE];
    int menu_item_selection;

    fgets(input_string, INPUT_CHAR_BUFFER_SIZE, stdin);

    /* Scan string to integer */
    if(sscanf(input_string, "%d", &menu_item_selection) == 1)
    {
        /* Return user entered value. If not in menu range, return error */
        return (menu_item_selection < MENU_ITEMS_MAX &&
                menu_item_selection >= 0 ?
                menu_item_selection: INPUT_MENU_OPTION_ERROR);
    }

    return INPUT_MENU_OPTION_ERROR;
}

/**
 * Handles user input, for setting unit value
 * @param s pointer to unit information struct
 * @param n Number after SI-value, pass 0 for none.
 *          example: R1 R2 R3 or U
 */
double input_get_unit_value(unit_info * s, int n)
{
    char input_string[INPUT_CHAR_BUFFER_SIZE];
    double input_value;
    bool correct_input;

    /* Display text: Ask user for input */
    output_ask_for_unit_value_input(s, n);

    do
    {
        correct_input = true;
        fgets(input_string, INPUT_CHAR_BUFFER_SIZE, stdin);

        /* Scan input to input_value */
        if(sscanf(input_string, "%lf", &input_value) != 1)
        {
            correct_input = false;
            printf(STRING_ERROR_INPUT_GENERAL "\n");
            continue;
        }

        if(input_value > s->max_value)
        {
            correct_input = false;
            printf(STRING_ERROR_INPUT_HIGH_VALUE "\n");
        }

        if(input_value < s->min_value)
        {
            correct_input = false;
            printf(STRING_ERROR_INPUT_LOW_VALUE "\n");
        }

    } while(!correct_input); // Repeat while incorrect user input

    return input_value;
}

/**
 * Asks user to enter unit value
 * @param s pointer to unit information struct
 * @param n Number after SI-value, pass 0 for none.
            example: R1 R2 R3 or U
 */
void output_ask_for_unit_value_input(unit_info * s, int n)
{
    char number[3];
    char char_parantheses[5];

    if(s->id == COS)
    {
        printf("Skriv %s %s > %d && < %d: \n ",
            s->name,
            s->value_name,
            s->max_value,
            s->min_value);

        /* Exit function */
        return;
    }

    sprintf(char_parantheses, " (%s)", s->value_char);

    printf("Skriv %s %c%s i %s%s < %d%s: \n ",
        s->name,                                     // 'spänning', 'ström'
        s->si_char,                                  // U, I
        n ? itoa(n, number, 10) : "",                // R1, R2 ...
        s->value_name,                               // 'Volt', 'Ampere'
        s->id != RESISTANCE ? char_parantheses : "", // 'V', 'A'
        s->max_value,                                // Max value
        s->value_char                                // 'V', 'A'
    );
}

/**
 * Clears terminal screen and sets code page to 1252
 */
void output_clear_screen(void)
{
    system("chcp 1252");
    system("cls");
}
