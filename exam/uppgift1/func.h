/**
 * For Exam
 * Test, verifiering och certifiering
 * Mjukvaruutvecklare inbyggda system
 * 2017-12-14
 *
 * By Johan Kampe
 */

#ifndef FUNC_H
#define FUNC_H

#include <stdbool.h>
#include <stdint.h>

#define DHT_MAX_TIMINGS     85
#define DHT_PIN             3
#define INPUT               1
#define OUTPUT              2
#define LOW                 0
#define HIGH                1

int data[5];

/* Functon prototypes */
uint8_t dht_poll_data(void);
float celcius_to_fahrenheit(float c);
bool dht_checksum_correct(void);

/* Stub functon prototypes */
void delay(int a);
void pinMode();
int wiringPiSetup();
void delayMicroseconds(int s1);
int digitalRead(int a);
void digitalWrite(int a, int b);

#endif
