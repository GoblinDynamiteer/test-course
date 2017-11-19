#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "formulas.h"

#define INPUT_CHAR_BUFFER_SIZE 200
#define INPUT_MENU_OPTION_ERROR -1
#define INPUT_MENU_OPTION_QUIT 0
#define MENU_ITEMS_MAX 8
#define STRING_ERROR_INPUT_LOW_VALUE "F�r l�gt v�rde, f�rs�k igen:"
#define STRING_ERROR_INPUT_HIGH_VALUE "F�r h�gt v�rde, f�rs�k igen:"
#define STRING_ERROR_INPUT_GENERAL "Fel inmatning, f�rs�k igen:"
#define STRING_ERROR_FORMULA_STRUCT "Error: Fauly formula_info struct!"
#define STRING_ERROR_INPUT_WRONG_OPTION "Fel alternativ f�rs�k igen!"

enum
{
    OHMS_LAW,
    RTOT,
    POWER_CALC,
    APPARANT_POWER_ONE_PHASE,
    REAL_POWER_ONE_PHASE,
    APPARANT_POWER_THREE_PHASE,
    REAL_POWER_THREE_PHASE,
    QUIT_PROGRAM
};

/* Function prototypes */
void output_display_main_menu(void);
void output_display_formula_info(int menu_item);
int input_main_menu_user_selection(void);
double input_get_unit_value(unit_info * s, int n);
void output_clear_screen(void);
void output_ask_for_unit_value_input(unit_info * s, int n);

#endif
