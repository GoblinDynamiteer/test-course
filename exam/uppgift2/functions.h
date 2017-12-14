/**
 * For Exam
 * Test, verifiering och certifiering
 * Mjukvaruutvecklare inbyggda system
 * 2017-12-14
 *
 * By Johan Kampe
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdbool.h>

#define NUMBER_INPUT_CORRECT    true
#define NUMBER_INPUT_FALSE      false
#define NUMBER_MIN_LENGTH       10
#define NUMBER_MAX_LENGTH       11
#define INPUT_BUFFER            200

enum { GENDER_MALE, GENDER_FEMALE };

/* Function prototypes */
bool number_check(char * number);
bool number_input(char * number);
int check_gender(char * number);
bool get_user_input_yes_no(void);

#endif
