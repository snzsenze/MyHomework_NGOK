#ifndef _FUNC_H
#define _FUNC_H

#define CUP_X 20
#define CUP_Y 10
#define FIGURE_X 4
#define FIGURE_Y 2

typedef struct {
    char **matrix;
    int cup_x;
    int cup_y;
} cup_t;

typedef struct {
    int **matrix;
    int figure_x;
    int figure_y;
} figure_t;

void menu();
cup_t allocate_cup(const int cup_x, const int cup_y);
void print_cup(cup_t *cup);
void remove_cup(cup_t *cup);

#endif // FUNC_H