#include "io.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // itoa

struct_unit_info unit_type_info[4] =
{
    {"sp�nning", "volt", "V", 'U', 230, 0},
    {"resistans", "ohm", "ohm", 'R', 20000, 0},
    {"str�m", "ampere", "A", 'I', 440, 0},
    {"effektfaktor", "cos", "cos", 'e', 1, 0},
};

/* Generate and display main menu */
void output_display_main_menu(void)
{
    static const char * string_menu_title =
        "V�lj vilka storheter du vill ber�kna:";

    static const char * string_menu_option[] =
    {
        "OHMS LAG",
        "Rtot",
        "EFFEKTLAGEN ENKEL",
        "SKENBAR EFFEKT ENFAS",
        "AKTIV EFFEKT/MEDELEFFEKT ENFAS",
        "SKENBAR EFFEKT 3-FAS",
        "AKTIV EFFEKT 3-FAS",
        "F�R ATT AVSLUTA"
    };

    printf("\n%s\n", string_menu_title);

    for(int i = 0; i < MENU_ITEMS_MAX; i++)
    {
        printf("V�lj %d f�r: %s\n", (i + 1),
            string_menu_option[i]);
    }
}

/* Print info about chosen formula */
void output_display_selection_info(int menu_item)
{
    static const char * string_menu_help[] =
    {
        "Ohms lag sp�nningen(volt/V) bet�ckning U "
        "lika med Resistansen(Ohm) bet�ckning R \n"
        "g�nger Str�mmen(Ampere) med bet�ckningen I. "
        "Kort U=R*I. \n\n",

        "Resistans sammankopplade i parallella kretsar �r "
        "lika med 1 delat Resistans R total �r lika med\n"
        "Resistans 1/R1 + 1/R2 + 1/R3 d� vi h�gst anv�nder "
        "tre resistanser.\n\n",

        "Effektlagen enkel f�r likstr�m �r effekten P i Watt (W)"
        "lika med sp�nningen U i volt(V)\n"
        "g�nger str�mmen I i Ampere(A): \n\n",

        "Skenbar effekt enfas r�knas med storheten VA(VoltAmpere)"
        "som �r lika med sp�nningen U i volt(V)\n"
        "g�nger str�mmen I i ampere(A)\n\n",

        "Aktiv medelefdekt enfas �r lika med effekt P i watt(W)"
        "lika med sp�nningen U i volt(V) g�nger str�mmen I \n"
        "i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n",

        "3-fas skenbar effekt �r v�xelsp�nning �r skenbar effekt S "
        "i voltampere(VA) lika med sp�nningen U i volt(V) \n"
        "g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n",

        "3-fas aktiv effekt �r effekten P i Watt(W) lika med sp�nningen"
        "U i volt(V) g�nger str�mmen I i ampere(A)\n"
        "g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n"
    };

    printf(string_menu_help[menu_item]);
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
        menu_item_selection--;
        return (menu_item_selection < MENU_ITEMS_MAX &&
                menu_item_selection >= 0 ?
                menu_item_selection: INPUT_MENU_OPTION_ERROR);
    }

    return INPUT_MENU_OPTION_ERROR;
}

/*  User input for unit value, eg current,
    resistance or voltage */
double input_get_unit_value(int type, int n)
{
    printf("Got type: %d\n", type);
    char input_string[INPUT_CHAR_BUFFER_SIZE];
    char number[3];
    double input_value;
    bool correct_input;

    /* FIX CORRECT OUTPUT
        Skriv in effektfaktorn cos > 0 && cos < 1
        Skriv resistans R2 < 20 000ohm:
        */

    printf("Skriv %s %c%s i %s(%s) < %d%s: \n",
        unit_type_info[type].name,             // 'sp�nning', 'str�m'
        unit_type_info[type].si_char,          // U, I
        n ? itoa(n, number, 10) : "",          // R1, R2 ...
        unit_type_info[type].value_name,       // 'Volt', 'Ampere'
        unit_type_info[type].value_char,       // 'V', 'A'
        unit_type_info[type].max_value,        // Max value
        unit_type_info[type].value_char        // 'V', 'A'
    );

    do
    {
        correct_input = true;
        fgets(input_string, INPUT_CHAR_BUFFER_SIZE, stdin);
        sscanf(input_string, "%lf", &input_value);

        if(input_value > unit_type_info[type].max_value)
        {
            correct_input = false;
            printf("F�r h�gt v�rde, f�rs�k igen: \n");
        }

        if(input_value < unit_type_info[type].min_value)
        {
            correct_input = false;
            printf("F�r l�gt v�rde, f�rs�k igen: \n");
        }

    } while(!correct_input);

    return input_value;
}
