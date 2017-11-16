#include "io.h"

void output_display_main_menu(void)
{
    printf("%s\n", string_menu_title);

    for(int i = 0; i < MENU_OPTION_MAX; i++)
    {
        printf("Välj %d för: %s\n", (i + 1), string_menu_option[i]);
    }
}
