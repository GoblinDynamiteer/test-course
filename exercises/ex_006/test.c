/**
 * Unity tests
 * test.c
 *
 * By Johan Kampe
 */

#include "functions.h"
#include "unity.h"

void test_function_add(void)
{
    double a, b;

    a = 1.0; b = 2.5;
    TEST_ASSERT_EQUAL_FLOAT(a + b, operation_add(a, b));

    a = -332.123; b = 11.23;
    TEST_ASSERT_EQUAL_FLOAT(a + b, operation_add(a, b));

    a = 0.0; b = 222;
    TEST_ASSERT_EQUAL_FLOAT(a + b, operation_add(a, b));
}

void test_function_subtract(void)
{
    double a, b;

    a = 1.0; b = 2.5;
    TEST_ASSERT_EQUAL_FLOAT(a - b, operation_subtract(a, b));

    a = -333.1234; b = 222322;
    TEST_ASSERT_EQUAL_FLOAT(a - b, operation_subtract(a, b));

    a = -333.1234; b = -222322;
    TEST_ASSERT_EQUAL_FLOAT(a - b, operation_subtract(a, b));

    a = 0.002; b = 0.0;
    TEST_ASSERT_EQUAL_FLOAT(a - b, operation_subtract(a, b));
}

void test_function_multiply(void)
{
    double a, b;

    a = 1.0; b = 2.5;
    TEST_ASSERT_EQUAL_FLOAT(a * b, operation_multiply(a, b));

    a = 1.0; b = 0.0;
    TEST_ASSERT_EQUAL_FLOAT(a * b, operation_multiply(a, b));

    a = -3312.098; b = 2213.3;
    TEST_ASSERT_EQUAL_FLOAT(a * b, operation_multiply(a, b));

    a = -1234.22; b = 123.55;
    TEST_ASSERT_EQUAL_FLOAT(a * b, operation_multiply(a, b));
}

void test_function_divide(void)
{
    double a, b;

    a = 1.0; b = 2.5;
    TEST_ASSERT_EQUAL_FLOAT(a / b, operation_divide(a, b));

    a = -343.021; b = 22.35;
    TEST_ASSERT_EQUAL_FLOAT(a / b, operation_divide(a, b));

    a = -23.23; b = 1235.2;
    TEST_ASSERT_EQUAL_FLOAT(a / b, operation_divide(a, b));

    a = 123.2; b = 0; // Divide by zero!
    TEST_ASSERT_EQUAL_FLOAT(0, operation_divide(a, b));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_function_add);
    RUN_TEST(test_function_subtract);
    RUN_TEST(test_function_multiply);
    RUN_TEST(test_function_divide);

    return UNITY_END();
}
