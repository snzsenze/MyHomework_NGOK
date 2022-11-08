#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#define CUP_X 20
#define CUP_Y 10
#define FIGURE_X 4
#define FIGURE_Y 2

int main()
{
    // menu();
    cup_t cup;
    cup = create_cup(CUP_X, CUP_Y);

    figure_t smash;
    smash = create_figure(FIGURE_X, FIGURE_Y);
    fill_smashboy(&smash);

    added_figure(&cup, &smash);
    print_cup(&cup);
    remove_figure(&smash);
    remove_cup(&cup);
}