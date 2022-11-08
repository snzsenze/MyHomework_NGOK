#include "func.h"
#include <stdio.h>
#include <stdlib.h>

cup_t allocate_cup(const int cup_x, const int cup_y)
{
    cup_t cup;
    cup.cup_x = cup_x;
    cup.cup_y = cup_y;

    cup.matrix = (char **)calloc(cup_x, sizeof(char *));
    for (int i = 0; i < cup_x; ++i) {
        cup.matrix[i] = (char *)calloc(cup_y, sizeof(char));
    }

    for (int i = 0; i < CUP_X; ++i) {
        for (int j = 0; j < CUP_Y; ++j) {
            cup.matrix[i][j] = '*';
        }
    }

    return cup;
}

void print_cup(cup_t *cup)
{
    for (int i = 0; i < cup->cup_x; ++i) {
        for (int j = 0; j < cup->cup_y; ++j) {
            printf("%c", cup->matrix[i][j]);
        }
        printf("\n");
    }
}

void remove_cup(cup_t *cup)
{
    for (int i = 0; i < cup->cup_x; ++i) {
        free(cup->matrix[i]);
    }
    free(cup->matrix);
}

figure_t allocate_figure(const int figure_x, const int figure_y) {}

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