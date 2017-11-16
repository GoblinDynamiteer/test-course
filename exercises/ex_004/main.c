
/*Detta program �r en r�knare som kan anv�ndas f�r ell�ra med enbart v�xelsp�nningar och v�xelstr�mmar. R�knaren
tar upp r�kning med sp�nningar i volt(U), resistanser upp till 20 000/ohm(R).
Str�m upp till 440 Ampere(I), effekter P i watt(W). 3 faser upp till 400V mellan faserna.
�ven tar denna upp Skenbar effekt vid 3-fas och enfas, aktiv effekt vid 3-fas och enfas d�r cosinus fi/cosinus() anv�nds
som effektfaktorn som �r mindre �n 1 och inte mindre �n 0.
Frekvenser i (Hz):  och totala motst�ndet i parallellkopplade kretsar med max 3 motst�nd.

50 Hertz(Hz) Finns det i v�ra uttag i sverige Vid 50 Hz byter �sp�nningen polaritet och str�mmen riktning 100 g�nger per
sekund. Sp�nningen i svenska eluttag pendlar upp och ner fr�n -325 V till +325 V. Att vi talar om 230 V beror p� att det
�r sp�nningens(v�xelstr�m ~) effektivv�rde eller roten ur. Sp�nningen V(U)=Toppv�rdet/sqrt(2)=325V/sqrt(2).

OHMS LAG: Sp�nning i volt(U)=Resistans i ohm(R)*Str�m i ampere(I)
RESISTANSTOTAL PARALLELLA RESISTANSER: Rtot=1/R1R2R3
EFFEKTLAGEN ENKEL f�r likstr�m: Effekt i watt(P)=U*I
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
    int val;

    while(1)
    {
        output_display_main_menu();
        val = input_main_menu_user_selection();

        /* User entered invalid menu option */
        while(val == INPUT_MENU_OPTION_ERROR)
        {
            printf("Fel alternativ f�rs�k igen!: \n");
            val = input_main_menu_user_selection();
        }

        printf("val: %d\n", val);
        printf("quit: %d\n", MENU_OPTION_QUIT);

        if(val == MENU_OPTION_QUIT)
        {
            printf("SKA AVLSUTA!!!!");
            return 0;
        }

        output_display_selection_info(val);
        printf("%f V\n", formula_handler(val));
    }
}
/*
        return 0;
        if(val == 2)
        {

            double r1,r2,r3;
            r1 = input_get_unit_value(RESISTANCE, 1);
            if(r1 > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("Skriv resistans R2 < 20 000ohm: \n ");
            scanf("%lf", &r2);
            if(r2 > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("Skriv resistans R3 < 20 000ohm: \n ");
            scanf("%lf", &r3);
            if(r3 > 20000)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f Ohm\n", res_tot(r1, r2, r3));
        }

        else if(val == 3)
        {

            printf("Effektlagen enkel f�r likstr�m �r effekten P i Watt (W) lika med sp�nningen U i volt(V)\n");
            printf("g�nger str�mmen I i Ampere(A): \n\n");
            double u, i;
            //printf("Skriv sp�nnngen U i volt(V): \n ");
            u = input_get_unit_value(VOLTAGE, 0);
            printf("Skriv str�m Ampere I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f W\n", eff_enk(u, i));
        }
        else if(val == 4)
        {

            printf("Skenbar effekt enfas r�knas med storheten VA(VoltAmpere) som �r lika med sp�nningen U i volt(V)\n");
            printf("g�nger str�mmen I i ampere(A)\n\n");
            double u, i;
            printf("Skriv Sp�nningen U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv str�m I < 440A: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f VA\n", sken_eff(u, i));
        }

        else if(val == 5)
        {
            printf("Aktiv medelefdekt enfas �r lika med effekt P i watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I \n");
            printf("i Ampere g�nger cosinus fi/efkektfaktor < 1:\n\n");
            double u, i, cos;
            printf("Skriv sp�nning U i volt: \n ");
            scanf("%lf", &u);
            printf("Skriv str�m I: \n");
            scanf("%lf", &i);
            if(i > 440){
                printf("F�r h�gt v�rde, f�rs�k igen:\n");
                continue;
            }
            printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("Fel v�rde, f�rs�k igen\n");
                continue;
            }
            printf("%f W\n", aktiv_eff(u, i, cos));
        }
        else if(val == 6)
        {
            printf("3-fas skenbar effekt �r v�xelsp�nning �r skenbar effekt S i voltampere(VA) lika med sp�nningen U i volt(V) \n");
            printf("g�nger str�mmen I i ampere(A) g�nger roten ur 3 SQRT(3).\n\n");
            double u, i;
            printf("Skriv sp�nning U i volt(V) < 400V: \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }

            printf("Skriv str�m I i ampere < 440: \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }
            printf("%f VA\n", sken_3fas(u, i));
        }
        else if(val == 7)
        {

            printf("3-fas aktiv effekt �r effekten P i Watt(W) lika med sp�nningen U i volt(V) g�nger str�mmen I i ampere(A)\n");
            printf("g�nger cos < 1 && cos > 0 g�nger roten ur 3 SQRT(3).\n\n");
            double u, i, cos;
            printf("Skriv Sp�nningen U i volt(V): \n ");
            scanf("%lf", &u);
            if(u > 400)
            {
                printf("F�r h�gt v�rde, f�rs�k igen.\n");
                continue;
            }
            printf("Skriv str�m I i ampere(A): \n");
            scanf("%lf", &i);
            if(i > 440)
            {
                printf("F�r h�gt v�rde, f�rs�k igen.\n");
                continue;
            }

            printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
            scanf("%lf", &cos);
            if (cos < 0 && cos > 1)
            {
                printf("F�r h�gt v�rde, f�rs�k igen: \n");
                continue;
            }

            printf("%f W\n", aktiv_3fas(u ,i, cos));
        }
        else if (val == 0)
        {
            exit = true;
        }


    return 0;
} */
