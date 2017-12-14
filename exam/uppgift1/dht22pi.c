/*
* dht.c:
* read temperature and humidity from DHT11 or DHT22 sensor
*/

//#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "func.h"

int main(int argc, char const *argv[])
{
    printf("Raspberry Pi DHT11/DHT22 temperature/humidity test\n");

    if (wiringPiSetup() == -1)
    {
        exit(1);
    }

    while(1)
    {
        uint8_t bits_read = 0;
        data[0] = data[1] = data[2] = data[3] = data[4] = 0;

        bits_read = dht_poll_data();

        /*
        * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
        * print it out if data is good
        */
        if ((bits_read >= 40) && dht_checksum_correct())
        {
            float h = (float)((data[0] << 8) + data[1]) / 10;

            if (h > 100)
            {
                h = data[0];	// for DHT11
            }

            float c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;

            if (c > 125)
            {
                c = data[2];	// for DHT11
            }

            if (data[2] & 0x80)
            {
                c = -c;
            }

            float f = celcius_to_fahrenheit(c);

            printf("Humidity = %.1f %% Temperature = %.1f *C (%.1f *F)\n",
                h, c, f);
        }

        else
        {
            printf("Data not good, skip\n");
        }

        delay(2000); /* wait 2 seconds before next read */
    }

    return 0;
}
