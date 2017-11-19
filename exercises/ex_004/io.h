#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "formulas.h"

#define INPUT_CHAR_BUFFER_SIZE 200
#define INPUT_MENU_OPTION_ERROR -1
#define MENU_ITEMS_MAX 8

enum
{
    OHMS_LAW,
    RTOT,
    EFFECT_CALC_SIMPLE,
    EFFECT_CALC_ONE_PHASE,
    APPARANT_POWER_ONE_PHASE,
    REAL_POWER_THREE_PHASE,
    APPARANT_POWER_THREE_PHASE,
    QUIT_PROGRAM
};

enum
{
    VOLTAGE,
    RESISTANCE,
    CURRENT,
    COS,
    POWER
};

/* Function prototypes */
void output_display_main_menu(void);
void output_display_selection_info(int menu_item);
int input_main_menu_user_selection(void);
double input_get_unit_value(unit_info * s, int n);

#endif
