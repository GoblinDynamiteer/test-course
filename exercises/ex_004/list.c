#include "formulas.h"
#include "io.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool is_empty(formula_info * node)
{
    return (node == NULL);
}

formula_info * list_getnext(formula_info * node)
{
   if(is_empty(node))
   {
      printf(STRING_ERROR_LINKED_LIST_GET_NEXT_FROM_NULL "\n");
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

formula_info * list_get_index(formula_info * node, int index)
{
    while(index--)
    {
        node = node->next;
    }

    return node;
}

int list_get_size(formula_info * node)
{
    int s = 0;
    while(!is_empty(node))
    {
        s++;
        node = list_getnext(node);
    }

    return s;
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
    while(!is_empty(list_getnext(node)))
    {
        node = list_getnext(node);
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
