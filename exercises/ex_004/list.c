#include "formulas.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool is_empty(formula_info * node)
{
    return (node == NULL);
}

formula_info * get_next(formula_info * node)
{
   if(is_empty(node))
   {
      printf("ERROR: trying to get_next from NULL pointer\n");
      return 0;
   }

   return node->next;
}

formula_info * insert_first(
    int id, char * name, char * info_text,
    int input_count, unit_type * inputs, unit_type output,
    formula_func2 formula2, formula_func3 formula3,
    formula_info * node)
{
    formula_info * new_node =
        (formula_info *)malloc(sizeof(formula_info));

    new_node->id = id;
    strcpy(new_node->name, name);
    strcpy(new_node->info, info_text);
    new_node->input_count = input_count;
    new_node->input[0] = inputs[0];
    new_node->input[1] = inputs[1];
    new_node->input[2] = inputs[2];
    new_node->output = output;
    new_node->formula2 = formula2;
    new_node->formula3 = formula3;
    new_node->next = NULL;

    return new_node;
}

formula_info * list_add_formula(
    int id, char * name, char * info_text,
    int input_count, unit_type * inputs, unit_type output,
    formula_func2 formula2, formula_func3 formula3,
    formula_info * node)
{
    formula_info * link;

    if(is_empty(node))
    {
        return insert_first(
            id,
            name,
            info_text,
            input_count,
            inputs,
            output,
            formula2,
            formula3,
            node);
    }

    link = node;
    while(!is_empty(get_next(node)))
    {
        node = get_next(node);
    }

    node->next = insert_first(
                    id,
                    name,
                    info_text,
                    input_count,
                    inputs,
                    output,
                    formula2,
                    formula3,
                    NULL);

    return link;
}

formula_info * list_init_formulas(formula_info * node)
{
    unit_type input_types[3];

    input_types[0] = RESISTANCE;
    input_types[1] = CURRENT;
    input_types[3] = NONE;
    node = list_add_formula(
        OHMS_LAW, "OHMS LAG", // Id and name
        "Ohms lag spänningen(volt/V) betäckning U " // Info
        "lika med Resistansen(Ohm) betäckning R \n"
        "gånger Strömmen(Ampere) med betäckningen I. "
        "Kort U=R*I. \n\n",
        2, input_types, VOLTAGE,  // Input & output type
        formula_ohms_law, NULL, // Pointer to formula function
        node);

    input_types[0] = RESISTANCE;
    input_types[1] = RESISTANCE;
    input_types[3] = RESISTANCE;
    node = list_add_formula(
        RTOT, "RTOT PARALLELL",
        "Resistans sammankopplade i parallella kretsar är "
        "lika med 1 delat Resistans R total är lika med\n"
        "Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder "
        "tre resistanser.\n\n",
        3, input_types, RESISTANCE,
        NULL, formula_rtot,
        node);

    input_types[0] = RESISTANCE;
    input_types[1] = RESISTANCE;
    input_types[3] = NONE;
    node = list_add_formula(
        RTOT_SERIES, "RTOT SERIE",
        "Resistans sammankopplade i seriekretsar är "
        "summan av delresistanserna R1 R2 och R3.\n\n",
        3, input_types, RESISTANCE,
        NULL, formula_rtot_series,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[3] = NONE;
    node = list_add_formula(
        POWER_CALC, "EFFEKTLAGEN ENKEL",
        "Effektlagen enkel för likström är effekten P i Watt (W)"
        "lika med spänningen U i volt(V)\n"
        "gånger strömmen I i Ampere(A): \n\n",
        2, input_types, POWER,
        formula_power, NULL,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[3] = NONE;
    node = list_add_formula(
        APPARANT_POWER_ONE_PHASE, "SKENBAR EFFEKT ENFAS",
        "Skenbar effekt enfas räknas med storheten VA(VoltAmpere)"
        "som är lika med spänningen U i volt(V)\n"
        "gånger strömmen I i ampere(A)\n\n",
        2, input_types, VOLT_AMPERE,
        formula_apparent_power, NULL,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[3] = COS;
    node = list_add_formula(
        REAL_POWER_ONE_PHASE, "AKTIV EFFEKT/MEDELEFFEKT ENFAS",
        "Aktiv medelefdekt enfas är lika med effekt P i watt(W)"
        "lika med spänningen U i volt(V) gånger strömmen I \n"
        "i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n",
        3, input_types, POWER,
        NULL, formula_actual_power,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[3] = NONE;
    node = list_add_formula(
        APPARANT_POWER_THREE_PHASE, "SKENBAR EFFEKT 3-FAS",
        "3-fas skenbar effekt är växelspänning är skenbar effekt S "
        "i voltampere(VA) lika med spänningen U i volt(V) \n"
        "gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n",
        2, input_types, VOLT_AMPERE,
        formula_apparent_power_three_phase, NULL,
        node);

    input_types[0] = VOLTAGE;
    input_types[1] = CURRENT;
    input_types[3] = COS;
    node = list_add_formula(
        REAL_POWER_THREE_PHASE, "AKTIV EFFEKT 3-FAS",
        "3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen"
        "U i volt(V) gånger strömmen I i ampere(A)\n"
        "gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n",
        3, input_types, POWER,
        NULL, formula_actual_power_three_phase,
        node);

    return node;
}
