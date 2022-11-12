#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {}

int analyzator(cup_t *cup, int up_dot, int down_dot)
{
    int count = 0;
    int res = 0;
    int k = 0;
    int max[4] = {-1};
    for (int i = down_dot; i >= up_dot; --i) {
        for (int j = 0; j < CUP_Y; ++j) {
            if (cup->cup[i][j] != ' ') {
                count++;
            }
        }
        if (count == 10) {
            max[k] = i;
            ++k;
            count = 0;
            res++;
        }
    }
    return res;
}

cup_t create_cup(int cup_x, int cup_y)
{
    cup_t cup;
    cup.cup_x = cup_x;
    cup.cup_y = cup_y;
    cup.cup = (char **)calloc(cup_x, sizeof(char *));
    for (int i = 0; i < cup_x; ++i) {
        cup.cup[i] = (char *)calloc(cup_x, sizeof(char));
    }
    for (int i = 0; i < cup_x; ++i) {
        for (int j = 0; j < cup_y; ++j) {
            cup.cup[i][j] = ' ';
        }
    }
    return cup;
}

void print_cup(cup_t *cup)
{
    for (int i = 0; i < cup->cup_x; ++i) {
        for (int j = 0; j < cup->cup_y; ++j) {
            printw(" %c ", cup->cup[i][j]);
        }
        printw("\n");
    }
}

void remove_cup(cup_t *cup)
{
    for (int i = 0; i < cup->cup_x; ++i) {
        free(cup->cup[i]);
    }
    free(cup->cup);
}

figure_t create_figure(int figure_x, int figure_y)
{
    figure_t figure;
    figure.figure_x = figure_x;
    figure.figure_y = figure_y;
    figure.figure = (int **)calloc(figure_x, sizeof(int *));
    for (int i = 0; i < figure_x; ++i) {
        figure.figure[i] = (int *)calloc(figure_x, sizeof(int));
    }
    return figure;
}

void print_figure(figure_t *figure)
{
    for (int i = 0; i < figure->figure_x; ++i) {
        for (int j = 0; j < figure->figure_y; ++j) {
            printf(" %d ", figure->figure[i][j]);
        }
        printf("\n");
    }
}

void remove_figure(figure_t *figure)
{
    for (int i = 0; i < figure->figure_x; ++i) {
        free(figure->figure[i]);
    }
    free(figure->figure);
}

void fill_smash_boy(figure_t *figure)
{
    figure->figure[0][0] = 0;
    figure->figure[0][1] = 4;

    figure->figure[1][0] = 0;
    figure->figure[1][1] = 5;

    figure->figure[2][0] = 1;
    figure->figure[2][1] = 4;

    figure->figure[3][0] = 1;
    figure->figure[3][1] = 5;
}

void added_figure(cup_t *cup, figure_t *figure)
{
    for (int i = 0; i < figure->figure_x; ++i) {
        cup->cup[figure->figure[i][0]][figure->figure[i][1]] = '*';
    }
}

int move_down(figure_t *figure, cup_t *cup)
{

    int down = down_dot(figure);
    int breaker = 1;

    if (down == CUP_X - 1) {
        breaker = 0;
    }

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (cup->cup[down + 1][figure->figure[i][1]] != ' ') {
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
    int left = left_dot(figure);
    int breaker = 1;
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (figure->figure[i][1] == 0) {
            breaker = 0;
        }
    }

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (cup->cup[figure->figure[i][0]][left - 1] != ' ') {
            breaker = 0;
        }
    }

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        figure->figure[i][1] -= 1;
    }
}

void move_right(figure_t *figure, cup_t *cup)
{
    int right = right_dot(figure);
    int breaker = 1;
    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (figure->figure[i][1] == CUP_Y - 1) {
            breaker = 0;
        }
    }

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        if (cup->cup[figure->figure[i][0]][right + 1] != ' ') {
            breaker = 0;
        }
    }

    for (int i = 0; i < figure->figure_x && breaker; ++i) {
        figure->figure[i][1] += 1;
    }
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

void delete_figure(cup_t *cup, figure_t *figure)
{
    for (int i = 0; i < figure->figure_x; ++i) {
        cup->cup[figure->figure[i][0]][figure->figure[i][1]] = ' ';
    }
}

int up_dot(figure_t *figure)
{
    int min = figure->figure[0][0];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (min > figure->figure[i][0]) {
            min = figure->figure[i][0];
        }
    }
    return min;
}

int down_dot(figure_t *figure)
{
    int max = figure->figure[0][0];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (max < figure->figure[i][0]) {
            max = figure->figure[i][0];
        }
    }
    return max;
}

int left_dot(figure_t *figure)
{

    int min = figure->figure[0][1];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (min > figure->figure[i][1]) {
            min = figure->figure[i][1];
        }
    }
    return min;
}

int right_dot(figure_t *figure)
{
    int max = figure->figure[0][1];
    for (int i = 1; i < figure->figure_x; ++i) {
        if (max < figure->figure[i][1]) {
            max = figure->figure[i][1];
        }
    }
    return max;
}
