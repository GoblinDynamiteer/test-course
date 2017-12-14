#include "func.h"

bool dht_checksum_correct(void)
{
    return (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF));
}

uint8_t dht_poll_data(void)
{
    int bits_read = 0;
    int counter = 0;
    uint8_t laststate = HIGH;

    /* pull pin down for 18 milliseconds */
    pinMode(DHT_PIN, OUTPUT);
    digitalWrite(DHT_PIN, LOW);
    delay(18);

    /* prepare to read the pin */
    pinMode(DHT_PIN, INPUT);

    /* detect change and read data */
    for (int i = 0; i < DHT_MAX_TIMINGS; i++)
    {
        counter = 0;
        while (digitalRead(DHT_PIN) == laststate || counter < 255)
        {
            counter++;
            delayMicroseconds(1);
        }

        laststate = digitalRead(DHT_PIN);

        if (counter == 255)
        {
            break;
        }

        /* ignore first 3 transitions */
        if ((i >= 4) && (i % 2 == 0))
        {
            /* shove each bit into the storage bytes */
            data[bits_read / 8] <<= 1;

            if (counter > 16)
            {
                data[bits_read / 8] |= 1;
            }

            bits_read++;
        }
    }

    return bits_read;
}

float celcius_to_fahrenheit(float c)
{
    return c * 1.8f + 32;
}

/* stub/driver functions not fully developed yet */
void delay(int a)
{

}

void pinMode()
{

}

int wiringPiSetup()
{
    return 0;
}

void delayMicroseconds(int s1)
{
}

int digitalRead(int a)
{
    return 0;
}

void digitalWrite(int a, int b)
{

}
