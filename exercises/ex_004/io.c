#include "io.h"

unit units[3];

void init_io(void)
{
    units[UNIT_VOLTAGE].max_value = 230;
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
