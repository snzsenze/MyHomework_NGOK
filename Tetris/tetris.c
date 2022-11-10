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

int up(figure_t *figure)
{
    int max = figure->figure[0][0];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (max < figure->figure[i][0]) {
            max = figure->figure[i][0];
        }
    }
    return max;
}

int down(figure_t *figure)
{
    int min = figure->figure[0][0];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (min > figure->figure[i][0]) {
            min = figure->figure[i][0];
        }
    }
    return min;
}

int dot_right(figure_t *figure)
{
    int min = figure->figure[0][1];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (min < figure->figure[i][1]) {
            min = figure->figure[i][1];
        }
    }
    return min;
}

int dot_left(figure_t *figure)
{
    int min = figure->figure[0][1];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (min > figure->figure[i][1]) {
            min = figure->figure[i][1];
        }
    }
    return min;
}

void copy_figure(figure_t *curr, figure_t *next)
{
    next->figure_x = curr->figure_x;
    next->figure_y = curr->figure_y;
    for (int i = 0; i < curr->figure_x; ++i) {
        for (int j = 0; j < curr->figure_y; ++j) {
            next->figure[i][j] = curr->figure[i][j];
        }
    }
}

int move_down(figure_t *figure, cup_t *cup)
{
    int downs = up(figure);
    int breaker = 1;

    if (downs == CUP_X - 1) {
        breaker = 0;
    }

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (cup->maincup[downs + 1][figure->figure[i][1]] != ' ') {
            breaker = 0;
        }
    }
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        figure->figure[i][0] += 1;
    }
    return breaker;
}

void move_left(figure_t *figure, cup_t *cup)
{
    int breaker = 1;
    int left = dot_left(figure);
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (figure->figure[i][1] == 0) {
            breaker = 0;
            break;
        }
    }
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (cup->maincup[figure->figure[i][0]][left - 1] != ' ') {
            breaker = 0;
        }
    }
    for (int i = 0; i < FIGURE_X && breaker; ++i) {
        figure->figure[i][1] -= 1;
    }
}

void move_right(figure_t *figure, cup_t *cup)
{
    int breaker = 1;
    int right = dot_right(figure);
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (figure->figure[i][1] == 9) {
            breaker = 0;
        }
    }
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (cup->maincup[figure->figure[i][0]][right + 1] != ' ') {
            breaker = 0;
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
    twink = create_figure(FIGURE_X, FIGURE_Y);

    added_figure(&cup, &smash);
    system("clear");
    print_cup(&cup);

    int res = 0, down = 1;
    while (res != Q) {

        res = getchar();
        setbuf(stdin, NULL);
        if (res != ENTER) {
            switch (res) {
            case W:

                break;

            case A:
                copy_figure(&smash, &twink);
                move_left(&smash, &cup);
                break;

            case S:
                copy_figure(&smash, &twink);
                down = move_down(&smash, &cup);
                break;

            case D:
                copy_figure(&smash, &twink);
                move_right(&smash, &cup);
                break;
            default:
                break;
            }
            delete_figure(&cup, &twink);

            added_figure(&cup, &smash);
            system("clear");
            print_cup(&cup);
            if (!down) {
                fill_smashboy(&smash);
            }
        }
    }
    remove_figure(&twink);

    remove_figure(&smash);
    remove_cup(&cup);
}