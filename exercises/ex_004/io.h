#ifndef IO_H
#define IO_H

#include <stdio.h>

#define INPUT_CHAR_BUFFER_SIZE 200
#define INPUT_MENU_OPTION_ERROR -1

enum
{
    MENU_OPTION_OHMS_LAW,
    MENU_OPTION_RTOT,
    MENU_OPTION_EFFECT_CALC_SIMPLE,
    MENU_OPTION_EFFECT_CALC_ONE_PHASE,
    MENU_OPTION_APPARANT_POWER_ONE_PHASE,
    MENU_OPTION_REAL_POWER_THREE_PHASE,
    MENU_OPTION_APPARANT_POWER_THREE_PHASE,
    MENU_OPTION_QUIT,
    MENU_OPTION_MAX
};

enum
{
    UNIT_VOLTAGE,
    UNIT_RESISTANCE,
    UNIT_CURRENT,
    NO_UNIT
};

typedef struct
{
    char name[20];          // eg 'Spänning'
    char value_name[20];    // eg 'Volt'
    char si_char;           // eg 'U'
    char value_char[5];        // eg 'V'
    int max_value;          // eg '230'
    int min_value;          // eg '0'
}struct_unit_info;

/* Function prototypes */
void init_io(void);
void output_display_main_menu(void);
int input_main_menu_user_selection(void);
double input_get_unit_value(int type, int n);

#endif
