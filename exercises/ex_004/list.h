#ifndef LIST_H
#define LIST_H

formula_info * list_add_formula(
    int id, char * name, char * info_text,
    int input_count, unit_type * inputs, unit_type output,
    formula_func2 formula2, formula_func3 formula3,
    formula_info * node);

formula_info * list_init_formulas(formula_info * node);

#endif
