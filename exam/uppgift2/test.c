#include "functions.h"
#include "unity.h"
#include <string.h>

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
