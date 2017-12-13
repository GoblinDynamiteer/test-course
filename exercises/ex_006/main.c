/**
 * Calc operations main file
 * TDD / Refactor exercise
 * based on code from
 * https://www.programiz.com/c-programming/c-switch-case-statement
 *
 * main.c
 *
 * By Johan Kampe
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char calc_op;
    double val1, val2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &calc_op);

    printf("Enter two operands: ");
    scanf("%lf %lf", &val1, &val2);

    switch(calc_op)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf", val1, val2, val1 + val2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf", val1, val2, val1 - val2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf", val1, val2, val1 * val2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf", val1, val2, val1 / val2);
            break;

        default:
            printf("Error! operator is not correct");
            break;
    }

    return 0;
}
