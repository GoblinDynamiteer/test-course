#include <stdio.h>

int input_integer(char * text);
int old_main(void);

int main(int argc, char const *argv[])
{

    int number_a, number_b, sum_of_numbers;

    number_a = input_integer("Enter number A: ");
    number_b = input_integer("Enter number B: ");
    sum_of_numbers = number_a + number_b;
    printf("The sum of %d and %d is %d.", number_a, number_b, sum_of_numbers);

    return 0;
}

int input_integer(char * text)
{
    int retval;
    printf(text);
    scanf("%d", &retval);
    return retval;
}

int old_main(void)
{

    int number_a, number_b, sum_of_numbers;

    printf("Enter number A: ");
    scanf("%d", &number_a);
    printf("Enter number B: ");
    scanf("%d", &number_b);
    sum_of_numbers = number_a + number_b;
    printf("The sum of %d and %d is %d.", number_a, number_b, sum_of_numbers);

    return 0;
}
