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

void test_input_operation(void)
{
    operation_id id;

    // Add to stdin to fake scanf
    // file contents: +2-*/a
    freopen("test/ops.txt", "r", stdin);

    id = ADDITION;
    TEST_ASSERT_EQUAL(id, input_operation());

    id = ERROR_OP_NOT_FOUND;
    TEST_ASSERT_EQUAL(id, input_operation());

    id = SUBTRACTION;
    TEST_ASSERT_EQUAL(id, input_operation());

    id = MULTIPLICATION;
    TEST_ASSERT_EQUAL(id, input_operation());

    id = DIVISION;
    TEST_ASSERT_EQUAL(id, input_operation());

    id = ERROR_OP_NOT_FOUND;
    TEST_ASSERT_EQUAL(id, input_operation());
}

void test_input_value(void)
{
    // Add to stdin to fake scanf
    // file contents: 22.33 1.3 -0.3 .4 .05 a f
    freopen("test/values.txt", "r", stdin);

    double value[] = {22.33, 1.3, -0.3, .4, .05};
    int i = 0;

    TEST_ASSERT_EQUAL_FLOAT(value[0], input_value());
    TEST_ASSERT_EQUAL_FLOAT(value[1], input_value());
    TEST_ASSERT_EQUAL_FLOAT(value[2], input_value());
    TEST_ASSERT_EQUAL_FLOAT(value[3], input_value());
    TEST_ASSERT_EQUAL_FLOAT(value[4], input_value());

    TEST_ASSERT_EQUAL_FLOAT(0.0f, input_value());
    TEST_ASSERT_EQUAL_FLOAT(0.0f, input_value());
}

void test_get_operation_sign(void)
{
    operation_id id = ERROR_OP_NOT_FOUND;
    TEST_ASSERT_EQUAL('0', get_operation_sign(id));

    id = ADDITION;
    TEST_ASSERT_EQUAL('+', get_operation_sign(id));

    id = SUBTRACTION;
    TEST_ASSERT_EQUAL('-', get_operation_sign(id));

    id = DIVISION;
    TEST_ASSERT_EQUAL('/', get_operation_sign(id));

    id = MULTIPLICATION;
    TEST_ASSERT_EQUAL('*', get_operation_sign(id));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_function_add);
    RUN_TEST(test_function_subtract);
    RUN_TEST(test_function_multiply);
    RUN_TEST(test_function_divide);
    RUN_TEST(test_input_operation);
    RUN_TEST(test_get_operation_sign);
    RUN_TEST(test_input_value);

    return UNITY_END();
}
