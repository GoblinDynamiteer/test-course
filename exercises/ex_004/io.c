#include "io.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // itoa

/**
 * Print main menu.
 * @param n Size of formula info struct array
 */
void output_display_main_menu(formula_info * f, int n)
{
    printf("\nVälj vilka storheter du vill beräkna:\n");

    for(int i = 0; i < n; i++)
    {
        printf("Välj %d för: %s\n",
            (i + 1),
            f[i].name);
    }

    printf("Välj %d för: FÖR ATT AVSLUTA\n",
        INPUT_MENU_OPTION_QUIT);
}

/**
 * Print information about formula.
 */
void output_display_formula_info(formula_info * f)
{
    printf(f->info);
}

/**
 * Handles user input, for menu choice
 * @param n Size of formula info struct array
 * @return User menu item selection, as a number
 */
int input_main_menu_user_selection(int n)
{
    char input_string[INPUT_CHAR_BUFFER_SIZE];
    int menu_item_selection;

    fgets(input_string, INPUT_CHAR_BUFFER_SIZE, stdin);

    /* Scan string to integer */
    if(sscanf(input_string, "%d", &menu_item_selection) == 1)
    {
        /* Return user entered value. If not in menu range, return error */
        return (menu_item_selection <= n &&
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
