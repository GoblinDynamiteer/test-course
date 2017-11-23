#include <stdio.h>
#include "operations.h"
#include <stdbool.h>
#include "../../unity/src/unity.h"

void test_addition(void)
{
    double values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f + 10.01f,
        calculate(values1, n, ADDITION));

    double values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 + 0.003 + 12.345,
        calculate(values2, n, ADDITION));

    double values3[INPUTS_MAX];
    double expected_result = 0.0f;

    for (int i = 0; i < INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result += values3[i];
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        calculate(values3, INPUTS_MAX, ADDITION));
}

void test_multiplication(void)
{
    double values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f * 10.01f,
        calculate(values1, n, MULTIPLICATION));

    double values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 * 0.003 * 12.345,
        calculate(values2, n, MULTIPLICATION));

    double values3[INPUTS_MAX];
    double expected_result = 0.0f;
    bool first = true;

    for (int i = 0; i < INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result = first ? values3[i] : expected_result * values3[i];

        first = first ? false : false;
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        calculate(values3, INPUTS_MAX, MULTIPLICATION));
}

void test_division(void)
{
    double values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f / 10.01f,
        calculate(values1, n, DIVISION));

    double values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 / 0.003 / 12.345,
        calculate(values2, n, DIVISION));

    double values3[INPUTS_MAX];
    double expected_result = 0.0f;
    bool first = true;

    for (int i = 0; i < INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result = first ? values3[i] : expected_result / values3[i];

        first = first ? false : false;
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        calculate(values3, INPUTS_MAX, DIVISION));
}

void test_subraction(void)
{
    double values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f - 10.01f,
        calculate(values1, n, SUBTRACTION));

    double values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 - 0.003 - 12.345,
        calculate(values2, n, SUBTRACTION));

    double values3[INPUTS_MAX];
    double expected_result = 0.0f;
    bool first = true;

    for (int i = 0; i < INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result = first ? values3[i] : expected_result - values3[i];

        first = first ? false : false;
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        calculate(values3, INPUTS_MAX, SUBTRACTION));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_addition);
    RUN_TEST(test_multiplication);
    RUN_TEST(test_subraction);
    RUN_TEST(test_division);

    return UNITY_END();
}
