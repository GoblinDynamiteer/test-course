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

void test_to_string()
{
    double values1[] = { 123.12f, 22.02f, 11.11f, -33.2f };
    int n = sizeof(values1) / sizeof(values1[0]);
    double result = 123.12f + 22.02f + 11.11f - 33.2f;
    char test_string[256];

    char expected_string[300];
    sprintf(
        expected_string,
        "%0.2f + %0.2f + %0.2f + %0.2f = %0.2f",
        values1[0], values1[1], values1[2], values1[3], result
    );

    TEST_ASSERT_EQUAL_STRING(
        expected_string,
        result_to_string(result, values1, n, ADDITION, test_string)
    );
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_addition);
    RUN_TEST(test_multiplication);
    RUN_TEST(test_subraction);
    RUN_TEST(test_division);
    RUN_TEST(test_to_string);

    return UNITY_END();
}
