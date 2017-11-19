#include "formulas.h"
#include "io.h"

/* Uses formula functions to calculate value */
double formula_handler(formula_info * f, unit_info * u)
{
    double value[3];

    for(int i = 0; i < f->input_count; i++)
    {
        value[i] = input_get_unit_value(
            &u[f->input[i]],
            (f->id == RTOT ? i + 1 : 0));
    }

    if(f->input_count == 3)
    {
        return f->formula3(value[0], value[1], value[2]);
    }

    return f->formula2(value[0], value[1]);
}

double formula_ohms_law(double r, double i)
{
    return i * r;
}

double formula_rtot(double r1, double r2, double r3)
{
     return 1.0f / ((1.0f / r1) + (1.0f / r2) + (1.0f / r3));
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
