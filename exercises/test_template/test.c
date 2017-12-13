#include "functions.h"
#include "unity.h"

void test_function_add(void)
{
    int a, b;

    a = 12, b = -33;
    TEST_ASSERT_EQUAL(a + b, function_add(a, b));

    a = 12324, b = 0;
    TEST_ASSERT_EQUAL(a + b, function_add(a, b));

    a = 33, b = 999999;
    TEST_ASSERT_EQUAL(a + b, function_add(a, b));
}

void test_function_char_cycle(void)
{
    TEST_ASSERT_TRUE(UP);
    TEST_ASSERT_FALSE(DOWN);

    char c = 'H';

    TEST_ASSERT_EQUAL(c + 1 , function_char_cycle(c, UP));
    TEST_ASSERT_EQUAL(c - 1 , function_char_cycle(c, DOWN));

    c = 'Z';
    TEST_ASSERT_EQUAL(c + 1 , function_char_cycle(c, UP));
    TEST_ASSERT_EQUAL(c - 1 , function_char_cycle(c, DOWN));

    c = '+';
    TEST_ASSERT_EQUAL(c + 1 , function_char_cycle(c, UP));
    TEST_ASSERT_EQUAL(c - 1 , function_char_cycle(c, DOWN));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_function_add);
    RUN_TEST(test_function_char_cycle);

    return UNITY_END();
}
