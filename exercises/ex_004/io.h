#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "formulas.h"

#define INPUT_CHAR_BUFFER_SIZE 200
#define INPUT_MENU_OPTION_ERROR -1
#define INPUT_MENU_OPTION_QUIT 0
#define STRING_ERROR_INPUT_LOW_VALUE "För lågt värde, försök igen:"
#define STRING_ERROR_INPUT_HIGH_VALUE "För högt värde, försök igen:"
#define STRING_ERROR_INPUT_GENERAL "Fel inmatning, försök igen:"
#define STRING_ERROR_FORMULA_STRUCT "Error: Fauly formula_info struct!"
#define STRING_ERROR_INPUT_WRONG_OPTION "Fel alternativ försök igen!"

/* Function prototypes */
void output_display_main_menu(formula_info * f, int n);
void output_display_formula_info(formula_info * f);
int input_main_menu_user_selection(int n);
double input_get_unit_value(unit_info * s, int n);
void output_clear_screen(void);
void output_ask_for_unit_value_input(unit_info * s, int n);

#endif
