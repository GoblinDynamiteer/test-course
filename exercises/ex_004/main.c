
/*Detta program är en räknare som kan användas för ellära med enbart växelspänningar och växelströmmar. Räknaren
tar upp räkning med spänningar i volt(U), resistanser upp till 20 000/ohm(R).
Ström upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
Även tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas där cosinus fi/cosinus() används
som effektfaktorn som är mindre än 1 och inte mindre än 0.
Frekvenser i (Hz):  och totala motståndet i parallellkopplade kretsar med max 3 motstånd.

50 Hertz(Hz) Finns det i våra uttag i sverige Vid 50 Hz byter ­spänningen polaritet och strömmen riktning 100 gånger per
sekund. Spänningen i svenska eluttag pendlar upp och ner från -325 V till +325 V. Att vi talar om 230 V beror på att det
är spänningens(växelström ~) effektivvärde eller roten ur. Spänningen V(U)=Toppvärdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Spänning i volt(U)=Resistans i ohm(R)*Ström i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL för likström: Effekt i watt(P)=U*I
SKENBAR EFFEKT ENFAS ~: Skenbar(S/VA)=U*I
AKTIV EFFEKT/MEDELEFFEKT ENFAS ~:P=U*I*cos()
SKENBAR EFFEKT 3-FAS ~: Skenbar S/VA=U*I*sqrt(3)
AKTIV EFFEKT 3-FAS ~: P=U*I*sqrt(3)*cos()

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include "formulas.h"
#include "io.h"

int main()
{
    system("chcp 1252");
    system("cls");
    init_io();
    bool exit = false;
    int val;

    while (exit == false)
    {
        output_display_main_menu();
        val = input_main_menu_user_selection();

        /* Userer entered invalid menu option */
        while(val == INPUT_MENU_OPTION_ERROR)
        {
            printf("Fel alternativ försök igen!: \n");
            val = input_main_menu_user_selection();
        }

        if(val == 1)
        {

            printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n");
            printf("gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
            double r, i;
            printf("Skriv resistans R < 20 000ohm: \n ");
            scanf("%lf", &r);
            if(r > 20000)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("Skriv ström I < 440 Ampere: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("%f V\n", ohms_lag(r, i));

        }

        else if(val == 2)
        {
            printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n");
            printf("Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n");
            double r1,r2,r3;
            r1 = input_get_unit_value(UNIT_RESISTANCE, 1);
            if(r1 > 20000)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("Skriv resistans R2 < 20 000ohm: \n ");
            scanf("%lf", &r2);
            if(r2 > 20000)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("Skriv resistans R3 < 20 000ohm: \n ");
            scanf("%lf", &r3);
            if(r3 > 20000)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("%f Ohm\n", res_tot(r1, r2, r3));
        }

        else if(val == 3)
        {

            printf("Effektlagen enkel för likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n");
            printf("gånger strömmen I i Ampere(A): \n\n");
            double u, i;
            //printf("Skriv spännngen U i volt(V): \n ");
            u = input_get_unit_value(UNIT_VOLTAGE, 0);
            printf("Skriv ström Ampere I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("%f W\n", eff_enk(u, i));
        }
        else if(val == 4)
        {

            printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n");
            printf("gånger strömmen I i ampere(A)\n\n");
            double u, i;
            printf("Skriv Spänningen U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv ström I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("%f VA\n", sken_eff(u, i));
        }

        else if(val == 5)
        {
            printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger strömmen I \n");
            printf("i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n");
            double u, i, cos;
            printf("Skriv spänning U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv ström I: \n");
            scanf("%lf", &i);
            if(i > 440){
                printf("För högt värde, försök igen:\n");
                continue;
            }
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("Fel värde, försök igen\n");
                continue;
            }
            printf("%f W\n", aktiv_eff(u, i, cos));
        }
        else if(val == 6)
        {
            printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n");
            printf("gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n");
            double u, i;
            printf("Skriv spänning U i volt(V) < 400V: \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("Skriv ström I i ampere < 440: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }
            printf("%f VA\n", sken_3fas(u, i));
        }
        else if(val == 7)
        {

            printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger strömmen I i ampere(A)\n");
            printf("gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n");
            double u, i, cos;
            printf("Skriv Spänningen U i volt(V): \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                printf("För högt värde, försök igen.\n");
                continue;
            }
            printf("Skriv ström I i ampere(A): \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("För högt värde, försök igen.\n");
                continue;
            }

            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("För högt värde, försök igen: \n");
                continue;
            }

            printf("%f W\n", aktiv_3fas(u ,i, cos));
        }
        else if (val == 0)
        {
            exit = true;
        }
    }

    return 0;
}
