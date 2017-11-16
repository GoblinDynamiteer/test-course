#ifndef FORMULAS_H
#define FORMULAS_H

#include <math.h>

/* Function prototypes */
double ohms_lag(double r, double i);
double res_tot(double r1, double r2, double r3);
double eff_enk(double u, double i);
double sken_eff(double u, double i);
double aktiv_eff(double u, double i, double cos);
double sken_3fas(double u, double i);
double aktiv_3fas(double u, double i, double cos);

#endif
