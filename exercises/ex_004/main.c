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

        printf("User--: %d\n", user_menu_choice);
        if(user_menu_choice == QUIT_PROGRAM)
        {
            return 0;
        }

        output_display_selection_info(user_menu_choice);
        printf("%lf V\n", formula_handler(user_menu_choice));
    }
}
