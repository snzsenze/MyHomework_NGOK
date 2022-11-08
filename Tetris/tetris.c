#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    cup_t cup = allocate_cup(CUP_X, CUP_Y);
    print_cup(&cup);
    remove_cup(&cup);
    // menu();
}