#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#define CUP_X 20
#define CUP_Y 10
#define FIGURE_X 4
#define FIGURE_Y 2
#define A 97
#define S 115
#define D 100
#define ENTER 10
#define Q 113
#define W 119
#define SPACE 32

void delete_figure(cup_t *cup, figure_t *figure)
{

    for (int i = 0; i < figure->figure_x; ++i) {
        cup->maincup[figure->figure[i][0]][figure->figure[i][1]] = ' ';
    }
}

figure_t copy_figure(figure_t *curr)
{
    figure_t tmp;
    tmp = create_figure(curr->figure_x, curr->figure_y);
    tmp.figure_x = curr->figure_x;
    tmp.figure_y = curr->figure_y;
    for (int i = 0; i < curr->figure_x; ++i) {
        for (int j = 0; j < curr->figure_y; ++j) {
            tmp.figure[i][j] = curr->figure[i][j];
        }
    }
    return tmp;
}

int move_down(figure_t *figure)
{

    int breaker = 1;

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        for (int j = 0; j < figure->figure_y && breaker; ++j) {
            if (figure->figure[i][j] == CUP_X - 1) {
                breaker = 0;
                break;
            }
        }
    }
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        figure->figure[i][0] += 1;
    }

    return breaker;
}

void move_left(figure_t *figure)
{
    int breaker = 1;

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        for (int j = 0; j < figure->figure_y && breaker; ++j) {
            if (figure->figure[i][j] == 0) {
                breaker = 0;
                break;
            }
        }
    }
    for (int i = 0; i < FIGURE_X && breaker; ++i) {
        figure->figure[i][1] -= 1;
    }
}

void move_right(figure_t *figure)
{
    int breaker = 1;

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        for (int j = 0; j < figure->figure_y && breaker; ++j) {
            if (figure->figure[i][j] == 9) {
                breaker = 0;
                break;
            }
        }
    }

    for (int i = 0; i < FIGURE_X && breaker; ++i) {
        figure->figure[i][1] += 1;
    }
}

int main()
{

    // menu();
    cup_t cup;
    cup = create_cup(CUP_X, CUP_Y);

    figure_t smash;
    smash = create_figure(FIGURE_X, FIGURE_Y);
    fill_smashboy(&smash);

    figure_t twink;

    added_figure(&cup, &smash);
    system("clear");
    print_cup(&cup);

    int res = 0, down = 0;
    while (res != Q) {

        res = getchar();
        setbuf(stdin, NULL);
        if (res != ENTER) {
            switch (res) {
            case W:

                break;

            case A:
                twink = copy_figure(&smash);
                move_left(&smash);
                break;

            case S:
                twink = copy_figure(&smash);
                down = move_down(&smash);
                break;

            case D:
                twink = copy_figure(&smash);
                move_right(&smash);
                break;
            default:
                break;
            }
            delete_figure(&cup, &twink);
            remove_figure(&twink);
            added_figure(&cup, &smash);
            system("clear");
            print_cup(&cup);
            if (!down) {
                fill_smashboy(&smash);
            }
        }
    }

    remove_figure(&smash);
    remove_cup(&cup);
}