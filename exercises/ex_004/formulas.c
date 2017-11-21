#include "formulas.h"
#include "io.h"
#include "list.h"
#include <stdlib.h>

/**
 * Handles calculation formulas, gets user value input
 * @param f Linked list with formula information, first node
 * @param index Index in linked list
 * @param u Pointer to unit information struct array
 * @return Formula calculated value
 */
double formula_handler(formula_info * f, int index, unit_info * u)
{
    double value[3], output_value;
    f = list_get_index(f, index);

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

    output_value = ((f->input_count == 3) ?
        f->formula3(value[0], value[1], value[2]) :
        f->formula2(value[0], value[1]));

    /* Prints result of formula calculation,
        example "P = 2.32W" */
    printf("%c = %0.2f%s",
        u[f->output].si_char,
        output_value,
        u[f->output].value_char);

    /* Also return calculated value, but not used in program */
    return output_value;
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

/**
 * Handles calculation formulas, gets user value input
 * @param node Linked list with formula information, first node
 * @return First node of linked list
 */
formula_info * formula_init_formulas(formula_info * node)
{
    unit_type input_types[3];

    input_types[0] = RESISTANCE;
    input_types[1] = CURRENT;
    input_types[2] = NONE;
    node = list_add_formula(
        OHMS_LAW, "OHMS LAG", // Id and name
        "Ohms lag spänningen(volt/V) betäckning U " // Info
        "lika med Resistansen(Ohm) betäckning R \n"
        "gånger Strömmen(Ampere) med betäckningen I. "
        "Kort U=R*I. \n\n",
        2, input_types, VOLTAGE,  // Input & output type
        formula_ohms_law, NULL, // Pointer to formula function
        node);

    input_types[0] = RESISTANCE;
    input_types[1] = RESISTANCE;
    input_types[2] = RESISTANCE;
    node = list_add_formula(
        RTOT, "RTOT PARALLELL",
        "Resistans sammankopplade i parallella kretsar är "
        "lika med 1 delat Resistans R total är lika med\n"
        "Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder "
        "tre resistanser.\n\n",
        3, input_types, RESISTANCE,
        NULL, formula_rtot,
        node);

    input_types[0] = RESISTANCE;
    input_types[1] = RESISTANCE;
    input_types[2] = NONE;
    node = list_add_formula(
        RTOT_SERIES, "RTOT SERIE",
        "Resistans sammankopplade i seriekretsar är "
        "summan av delresistanserna R1 R2 och R3.\n\n",
        3, input_types, RESISTANCE,
        NULL, formula_rtot_series,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[2] = NONE;
    node = list_add_formula(
        POWER_CALC, "EFFEKTLAGEN ENKEL",
        "Effektlagen enkel för likström är effekten P i Watt (W)"
        "lika med spänningen U i volt(V)\n"
        "gånger strömmen I i Ampere(A): \n\n",
        2, input_types, POWER,
        formula_power, NULL,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[2] = NONE;
    node = list_add_formula(
        APPARANT_POWER_ONE_PHASE, "SKENBAR EFFEKT ENFAS",
        "Skenbar effekt enfas räknas med storheten VA(VoltAmpere)"
        "som är lika med spänningen U i volt(V)\n"
        "gånger strömmen I i ampere(A)\n\n",
        2, input_types, VOLT_AMPERE,
        formula_apparent_power, NULL,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[2] = COS;
    node = list_add_formula(
        REAL_POWER_ONE_PHASE, "AKTIV EFFEKT/MEDELEFFEKT ENFAS",
        "Aktiv medelefdekt enfas är lika med effekt P i watt(W)"
        "lika med spänningen U i volt(V) gånger strömmen I \n"
        "i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n",
        3, input_types, POWER,
        NULL, formula_actual_power,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[2] = NONE;
    node = list_add_formula(
        APPARANT_POWER_THREE_PHASE, "SKENBAR EFFEKT 3-FAS",
        "3-fas skenbar effekt är växelspänning är skenbar effekt S "
        "i voltampere(VA) lika med spänningen U i volt(V) \n"
        "gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n",
        2, input_types, VOLT_AMPERE,
        formula_apparent_power_three_phase, NULL,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[2] = COS;
    node = list_add_formula(
        REAL_POWER_THREE_PHASE, "AKTIV EFFEKT 3-FAS",
        "3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen"
        "U i volt(V) gånger strömmen I i ampere(A)\n"
        "gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n",
        3, input_types, POWER,
        NULL, formula_actual_power_three_phase,
        node);

    return node;
}
