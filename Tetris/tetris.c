#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // menu();
    cup_t cup;
    cup = create_cup(CUP_X, CUP_Y);

    figure_t smash;
    smash = create_figure(FIGURE_X, FIGURE_Y);
    fill_smash_boy(&smash);

    figure_t tmp;

    int res = 0, down = 1;
    tmp = create_figure(FIGURE_X, FIGURE_Y);
    added_figure(&cup, &smash);
    system("clear");
    print_cup(&cup);

    while (res != Q) {
        res = getchar();
        setbuf(stdin, NULL);
        if (res != ENTER) {
            switch (res) {
            case W:

                break;
            case A:
                copy_figure(&smash, &tmp);
                move_left(&smash, &cup);
                break;
            case S:
                copy_figure(&smash, &tmp);
                down = move_down(&smash, &cup);
                break;
            case D:
                copy_figure(&smash, &tmp);
                move_right(&smash, &cup);
                break;
            case SPACE:
                while (down) {
                    copy_figure(&smash, &tmp);
                    down = move_down(&smash, &cup);
                    delete_figure(&cup, &tmp);
                    added_figure(&cup, &smash);
                    system("clear");
                    print_cup(&cup);
                }
                break;
            }
            delete_figure(&cup, &tmp);
            added_figure(&cup, &smash);
            system("clear");
            print_cup(&cup);
            if (!down) {
                fill_smash_boy(&smash);
                added_figure(&cup, &smash);
                system("clear");
                print_cup(&cup);
            }
        }
    }
    remove_figure(&tmp);
    remove_figure(&smash);
    remove_cup(&cup);
}