#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

   float f, c;
   char string[50];

   system("chcp 65001");
   system("cls");

   printf("FAHRENHEIT - CELCIUS\n");
   printf("====================\n\n");

   printf("Ange temperaturen i Fahrenheit : ");
   scanf("%f", &f);

   c = (f-32)/1.8;

   printf("Temperaturen �r %.1f C\n\n\n", c);

   printf("En g�ng till (J/N)?");
   scanf("%s", string);

   if (strcmp(string, "J") == 0) {
      main();
   }

   return 0;
}
