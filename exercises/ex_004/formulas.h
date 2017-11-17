#ifndef FORMULAS_H
#define FORMULAS_H

#include <math.h>

/* Function pointers to formula calculations */
typedef double (*formula_func2)(double, double);
typedef double (*formula_func3)(double, double, double);

typedef struct
{
    int args;
    int input_types[3];
    formula_func2 formula2;
    formula_func3 formula3;
}struct_formula;

/* Function prototypes */
double formula_handler(int type);
double formula_ohms_law(double r, double i);
double formula_rtot(double r1, double r2, double r3);
double formula_effect_simple(double u, double i);
double formula_apparent_power(double u, double i);
double formula_actual_power(double u, double i, double cos);
double formula_apparent_power_three_phase(double u, double i);
double formula_actual_power_three_phase(double u, double i, double cos);

#endif
