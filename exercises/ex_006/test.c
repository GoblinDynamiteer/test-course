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
    TEST_ASSERT_EQUAL(1, 2);
}

void test_function_subtract(void)
{
    TEST_ASSERT_EQUAL(1, 2);
}

void test_function_multiply(void)
{
    TEST_ASSERT_EQUAL(1, 2);
}

void test_function_divide(void)
{
    TEST_ASSERT_EQUAL(1, 2);
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
