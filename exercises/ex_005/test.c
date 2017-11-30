#include <stdio.h>
#include "operations.h"
#include <stdbool.h>
#include "unity.h"

void test_addition(void)
{
    float values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f + 10.01f,
        operation_calculate(values1, n, ADDITION));

    float values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 + 0.003 + 12.345,
        operation_calculate(values2, n, ADDITION));

    float values3[OPERATION_INPUTS_MAX];
    double expected_result = 0.0f;

    for (int i = 0; i < OPERATION_INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result += values3[i];
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        operation_calculate(values3, OPERATION_INPUTS_MAX, ADDITION));
}

void test_multiplication(void)
{
    float values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f * 10.01f,
        operation_calculate(values1, n, MULTIPLICATION));

    float values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 * 0.003 * 12.345,
        operation_calculate(values2, n, MULTIPLICATION));

    float values3[OPERATION_INPUTS_MAX];
    double expected_result = 0.0f;
    bool first = true;

    for (int i = 0; i < OPERATION_INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result = first ? values3[i] : expected_result * values3[i];

        first = first ? false : false;
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        operation_calculate(values3, OPERATION_INPUTS_MAX, MULTIPLICATION));
}

void test_division(void)
{
    float values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f / 10.01f,
        operation_calculate(values1, n, DIVISION));

    float values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 / 0.003 / 12.345,
        operation_calculate(values2, n, DIVISION));

    float values3[OPERATION_INPUTS_MAX];
    double expected_result = 0.0f;
    bool first = true;

    for (int i = 0; i < OPERATION_INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result = first ? values3[i] : expected_result / values3[i];

        first = first ? false : false;
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        operation_calculate(values3, OPERATION_INPUTS_MAX, DIVISION));
}

void test_subraction(void)
{
    float values1[] = { 5.23, 10.01 };
    int n = sizeof(values1) / sizeof(values1[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        5.23f - 10.01f,
        operation_calculate(values1, n, SUBTRACTION));

    float values2[] = { -123.2345, 0.003, 12.345 };
    n = sizeof(values2) / sizeof(values2[0]);
    TEST_ASSERT_EQUAL_FLOAT(
        -123.2345 - 0.003 - 12.345,
        operation_calculate(values2, n, SUBTRACTION));

    float values3[OPERATION_INPUTS_MAX];
    double expected_result = 0.0f;
    bool first = true;

    for (int i = 0; i < OPERATION_INPUTS_MAX; i++)
    {
        values3[i] = 0.4 + i;
        expected_result = first ? values3[i] : expected_result - values3[i];

        first = first ? false : false;
    }

    TEST_ASSERT_EQUAL_FLOAT(
        expected_result,
        operation_calculate(values3, OPERATION_INPUTS_MAX, SUBTRACTION));
}

void test_to_string()
{
    float values1[] = { 123.12f, 22.02f, 11.11f, -33.2f };
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
        operation_result_to_string(result, values1, n, ADDITION, test_string)
    );
}

void test_operation_id_check()
{
    int op_id = ADDITION;
    TEST_ASSERT_TRUE(operation_is_valid_id(op_id));
    op_id = SUBTRACTION;
    TEST_ASSERT_TRUE(operation_is_valid_id(op_id));
    op_id = DIVISION;
    TEST_ASSERT_TRUE(operation_is_valid_id(op_id));
    op_id = MULTIPLICATION;
    TEST_ASSERT_TRUE(operation_is_valid_id(op_id));
    op_id = -1;
    TEST_ASSERT_FALSE(operation_is_valid_id(op_id));
    op_id = OPERATIONS_MAX + 1;
    TEST_ASSERT_FALSE(operation_is_valid_id(op_id));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_addition);
    RUN_TEST(test_multiplication);
    RUN_TEST(test_subraction);
    RUN_TEST(test_division);
    RUN_TEST(test_to_string);
    RUN_TEST(test_operation_id_check);

    return UNITY_END();
}
