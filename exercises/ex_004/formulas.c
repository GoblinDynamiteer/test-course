#include "formulas.h"
#include "io.h"

/* Args, units used in formula, formula function (2 or 3 args) */
struct_formula formula_info[MAX_FORMULAS] =
{
    {2, {RESISTANCE, UNIT_CURRENT}, formula_ohms_law, NULL},
    {3, {RESISTANCE, RESISTANCE, RESISTANCE}, NULL, formula_rtot},
    {2, {VOLTAGE, UNIT_CURRENT}, formula_effect_simple, NULL},
    {2, {VOLTAGE, UNIT_CURRENT}, formula_apparent_power, NULL},
    {3, {VOLTAGE, UNIT_CURRENT, COS}, NULL, formula_actual_power},
    {2, {VOLTAGE, UNIT_CURRENT}, formula_apparent_power_three_phase, NULL},
    {3, {VOLTAGE, UNIT_CURRENT, COS}, NULL, formula_actual_power_three_phase}
};

/* Uses formula functions to calculate value */
double formula_handler(int type)
{
    double value[3];

    for(int i = 0; i < formula_info[type].args; i++)
    {
        value[i] = input_get_unit_value(
            formula_info[type].input_types[i],
            (type == RTOT ? i + 1 : 0));
    }

    if(formula_info[type].args == 3)
    {
        return formula_info[type].formula3(value[0], value[1], value[3]);
    }

    return formula_info[type].formula2(value[0], value[1]);
}

double formula_ohms_law(double r, double i)
{
    return i * r;
}

double formula_rtot(double r1, double r2, double r3)
{
    double rtot = (1 / r1) + (1 / r2) + (1 / r3);
    rtot = 1 / rtot;
    return rtot;
}

double formula_effect_simple(double u, double i)
{
    return  u * i;
}

double formula_apparent_power(double u, double i)
{
    return u * i;
}

double formula_actual_power(double u, double i, double cos)
{
    return u * i * cos;
}

double formula_apparent_power_three_phase(double u, double i)
{
    return u * i * sqrt(3);
}

double formula_actual_power_three_phase(
    double u, double i, double cos)
{
    return u * i * sqrt(3) * cos;
}
