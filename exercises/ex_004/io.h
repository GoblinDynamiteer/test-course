#ifndef IO_H
#define IO_H

#include <stdio.h>

const char * string_menu_title =
    "Välj vilka storheter du vill beräkna:";

const char * string_menu_option[] =
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

static enum
{
    MENU_OPTION_OHMS_LAW,
    MENU_OPTION_RTOT,
    MENU_OPTION_EFFECT_CALC_ONE_PHASE,
    MENU_OPTION_APPARANT_POWER_ONE_PHASE,
    MENU_OPTION_REAL_POWER_THREE_PHASE,
    MENU_OPTION_APPARANT_POWER_THREE_PHASE,
    MENU_OPTION_QUIT,
    MENU_OPTION_MAX
};

/* Funktion prototypes */
void output_display_main_menu(void);

#endif
