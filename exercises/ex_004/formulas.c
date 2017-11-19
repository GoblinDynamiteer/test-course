#include "formulas.h"
#include "io.h"
#include <stdlib.h>

/**
 * Handles calculation formulas, gets user value input
 * @param f Pointer to formula information struct
 * @param u Pointer to unit information struct array
 * @return Formula calculated value
 */
double formula_handler(formula_info * f, unit_info * u)
{
    double value[3];

    /* Make sure  */
    if( (f->input_count == 2 && f->formula2 == NULL) ||
        (f->input_count == 3 && f->formula3 == NULL) ||
        (f->input_count != 3 && f->input_count != 2))
    {
        printf(STRING_ERROR_FORMULA_STRUCT "\n");
        return 0.0f;
    }

    /* Get user value input for formula calculations */
    for(int i = 0; i < f->input_count; i++)
    {
        value[i] = input_get_unit_value(
            &u[f->input[i]],
            /* Only RTOT formula uses unit numbering: R1 R2 R3 */
            (f->id == RTOT ? i + 1 : 0));
    }

    /* If formula uses 3 input values */
    if(f->input_count == 3)
    {
        return f->formula3(value[0], value[1], value[2]);
    }

    return f->formula2(value[0], value[1]);
}

/**
 * Calculates volage with Ohm's law
 * @param r Resistance
 * @param i Current
 * @return Voltage
 */
double formula_ohms_law(double r, double i)
{
    return i * r;
}

/**
 * Calculates total resistance
 * @param r1 Resistance R1
 * @param r2 Resistance R2
 * @param r3 Resistance R3
 * @return Total resistance rtot
 */
double formula_rtot(double r1, double r2, double r3)
{
     return 1.0f / ((1.0f / r1) + (1.0f / r2) + (1.0f / r3));
}

/**
 * Calculates power from voltage and current
 * @param u Voltage
 * @param i Current
 * @return Power p
 */
double formula_power(double u, double i)
{
    return  u * i;
}

/**
 * Calculates apparent power for one-phase
 * @param u Voltage
 * @param i Current
 * @return apparent power S
 */
double formula_apparent_power(double u, double i)
{
    return u * i;
}

/**
 * Calculates actual power for one-phase
 * @param u Voltage
 * @param i Current
 * @param cos Power factor
 * @return Actual power P
 */
double formula_actual_power(double u, double i, double cos)
{
    return u * i * cos;
}

/**
 * Calculates apparent power for three-phase
 * @param u Voltage
 * @param i Current
 * @return apparent power S
 */
double formula_apparent_power_three_phase(double u, double i)
{
    return u * i * sqrt(3);
}

/**
 * Calculates actual power for three-phase
 * @param u Voltage
 * @param i Current
 * @param cos Power factor
 * @return Actual power P
 */
double formula_actual_power_three_phase(
    double u, double i, double cos)
{
    return u * i * sqrt(3) * cos;
}

/* Test for refactoring:
    Added function that calculates resistance in series
    Main menu should add formula automatically */
double formula_rtot_series(double r1, double r2, double r3)
{
    return r1 + r2 + r3;
}
