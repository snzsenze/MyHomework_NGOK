#include "func.h"
#include <stdio.h>
#include <stdlib.h>

cup_t create_cup(int cup_x, int cup_y)
{
    cup_t cup;
    cup.cup_x = cup_x;
    cup.cup_y = cup_y;
    cup.maincup = (char **)calloc(cup_x, sizeof(char *));
    for (int i = 0; i < cup_x; ++i) {
        cup.maincup[i] = (char *)calloc(cup_x, sizeof(char));
    }
    for (int i = 0; i < cup_x; ++i) {
        for (int j = 0; j < cup_y; ++j) {
            cup.maincup[i][j] = '^';
        }
    }
    return cup;
}

void print_cup(cup_t *cup)
{
    for (int i = 0; i < cup->cup_x; ++i) {
        for (int j = 0; j < cup->cup_y; ++j) {
            printf(" %c ", cup->maincup[i][j]);
        }
        printf("\n");
    }
}

void remove_cup(cup_t *cup)
{
    for (int i = 0; i < cup->cup_x; ++i) {
        free(cup->maincup[i]);
    }
    free(cup->maincup);
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

void added_figure(cup_t *cup, figure_t *figure)
{
    for (int i = 0; i < figure->figure_x; ++i) {
        cup->maincup[figure->figure[i][0]][figure->figure[i][1]] = '*';
    }
}

void fill_smashboy(figure_t *figure)
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

void menu()
{
    int result = 0;
    while (result != 2) {
        printf("1 - Начать игру\n");
        printf("2 - Exit\n");
        scanf("-%d-", &result);
        setbuf(stdin, NULL);
        switch (result) {
        case 1:
                
            break;
        default:
            break;
        }
    }
}