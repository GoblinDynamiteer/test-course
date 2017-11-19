#ifndef FORMULAS_H
#define FORMULAS_H

#include <math.h>

/* Function pointers to formula calculations */
typedef double (*formula_func2)(double, double);
typedef double (*formula_func3)(double, double, double);

typedef unsigned short unit_type;

enum
{
    VOLTAGE,
    RESISTANCE,
    CURRENT,
    COS,
    POWER,
    VOLT_AMPERE
};

enum
{
    OHMS_LAW,
    RTOT,
    RTOT_SERIES,
    POWER_CALC,
    APPARANT_POWER_ONE_PHASE,
    REAL_POWER_ONE_PHASE,
    APPARANT_POWER_THREE_PHASE,
    REAL_POWER_THREE_PHASE,
};

typedef struct _struct_formula_info
{
    int id;
    char name[50];
    char info[1000];
    int input_count;
    unit_type input[3];
    unit_type output;
    formula_func2 formula2;
    formula_func3 formula3;
}formula_info;

typedef struct _struct_unit_info
{
    unit_type id;           // enum eg VOLTAGE, CURRENT
    char name[20];          // eg 'Spänning'
    char value_name[20];    // eg 'Volt'
    char value_char[5];     // eg 'V'
    char si_char;           // eg 'U'
    int max_value;          // eg '230'
    int min_value;          // eg '0'
}unit_info;

/* Function prototypes */
double formula_handler(formula_info * f, unit_info * u);
double formula_ohms_law(double r, double i);
double formula_rtot(double r1, double r2, double r3);
double formula_power(double u, double i);
double formula_apparent_power(double u, double i);
double formula_actual_power(double u, double i, double cos);
double formula_apparent_power_three_phase(double u, double i);
double formula_actual_power_three_phase(double u, double i, double cos);
double formula_rtot_series(double r1, double r2, double r3);

#endif
