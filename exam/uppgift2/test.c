/**
 * For Exam
 * Test, verifiering och certifiering
 * Mjukvaruutvecklare inbyggda system
 * 2017-12-14
 *
 * By Johan Kampe
 */

#include "functions.h"
#include "unity.h"
#include <string.h>

/**
 * Tests for function number_check
 */
void test_number_check(void)
{
    TEST_ASSERT_TRUE(number_check("8306191910"));
    TEST_ASSERT_TRUE(number_check("830619-1910"));
    TEST_ASSERT_TRUE(number_check("5801251912"));
    TEST_ASSERT_TRUE(number_check("580125-1912"));
    TEST_ASSERT_TRUE(number_check("781119-1915"));

    TEST_ASSERT_FALSE(number_check("12345678901011"));
    TEST_ASSERT_FALSE(number_check("33-21"));
}

/**
 * Tests for function test_check_gender
 */
void test_check_gender(void)
{
    TEST_ASSERT_EQUAL_INT(GENDER_MALE, check_gender("8306191910"));
    TEST_ASSERT_EQUAL_INT(GENDER_FEMALE, check_gender("830619-1920"));
    TEST_ASSERT_EQUAL_INT(GENDER_MALE, check_gender("8306191970"));
    TEST_ASSERT_EQUAL_INT(GENDER_FEMALE, check_gender("830619+1960"));
    TEST_ASSERT_EQUAL_INT(GENDER_MALE, check_gender("8306191990"));
    TEST_ASSERT_EQUAL_INT(GENDER_FEMALE, check_gender("830619+1900"));
}

int main()
{
    UNITY_BEGIN();

    RUN_TEST(test_number_check);
    RUN_TEST(test_check_gender);

    return UNITY_END();
}
