#include "io.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // itoa

struct_unit_info unit_type_info[3];

void init_io(void)
{
    strcpy(unit_type_info[UNIT_VOLTAGE].name, "spänning");
    strcpy(unit_type_info[UNIT_VOLTAGE].value_name, "volt");
    strcpy(unit_type_info[UNIT_VOLTAGE].value_char, "V");
    unit_type_info[UNIT_VOLTAGE].si_char = 'U';
    unit_type_info[UNIT_VOLTAGE].max_value = 230;
    unit_type_info[UNIT_VOLTAGE].min_value = 0;

    strcpy(unit_type_info[UNIT_CURRENT].name, "ström");
    strcpy(unit_type_info[UNIT_CURRENT].value_name, "ampere");
    strcpy(unit_type_info[UNIT_CURRENT].value_char, "A");
    unit_type_info[UNIT_CURRENT].si_char = 'I';
    unit_type_info[UNIT_CURRENT].max_value = 440;
    unit_type_info[UNIT_CURRENT].min_value = 0;

    strcpy(unit_type_info[UNIT_RESISTANCE].name, "resistans");
    strcpy(unit_type_info[UNIT_RESISTANCE].value_name, "ohm");
    strcpy(unit_type_info[UNIT_RESISTANCE].value_char, "ohm");
    unit_type_info[UNIT_RESISTANCE].si_char = 'R';
    unit_type_info[UNIT_RESISTANCE].max_value = 20000;
    unit_type_info[UNIT_RESISTANCE].min_value = 0;
}

/* Generate and display main menu */
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

    for(int i = 0; i < MENU_OPTION_MAX; i++)
    {
        printf("Välj %d för: %s\n", (i + 1), string_menu_option[i]);
    }
}

/* Get user input for menu selection, should be numeric */
int input_main_menu_user_selection(void)
{
    char input_string[INPUT_CHAR_BUFFER_SIZE];
    int menu_item_selection;

    fgets(input_string, INPUT_CHAR_BUFFER_SIZE, stdin);

    /* Scan string to integer */
    if(sscanf(input_string, "%d", &menu_item_selection) == 1)
    {
        return (menu_item_selection <= MENU_OPTION_MAX &&
                menu_item_selection > 0 ?
                menu_item_selection : INPUT_MENU_OPTION_ERROR);
    }

    return INPUT_MENU_OPTION_ERROR;
}

/*  User input for unit value, eg current,
    resistance or voltage */
double input_get_unit_value(int type, int n)
{
    char input_string[INPUT_CHAR_BUFFER_SIZE];
    char number[3];
    double input_value;
    bool correct_input = true;

    printf("Skriv %s %c%s i %s(%s) < %d%s: \n",
        unit_type_info[type].name,
        unit_type_info[type].si_char,
        n ? itoa(n, number, 10) : "",
        unit_type_info[type].value_name,
        unit_type_info[type].value_char,
        unit_type_info[type].max_value,
        unit_type_info[type].value_char
    );

    do
    {
        fgets(input_string, INPUT_CHAR_BUFFER_SIZE, stdin);
        sscanf(input_string, "%lf", &input_value);

        correct_input = (input_value <= unit_type_info[type].max_value);

        if(!correct_input)
        {
            printf("För högt värde, försök igen: \n");
        }

    } while(!correct_input);

    return input_value;
}
