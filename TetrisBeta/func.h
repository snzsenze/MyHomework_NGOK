#ifndef _FUNC_H_
#define _FUNC_H_

#define CUP_X 20
#define CUP_Y 10
#define FIGURE_X 4
#define FIGURE_Y 2
#define A 97
#define S 115
#define D 100
#define Q 113
#define ENTER 10
#define W 119
#define SPACE 32

typedef struct {
    char **cup;
    int cup_x;
    int cup_y;
} cup_t;

typedef struct {
    int **figure;
    int figure_x;
    int figure_y;
} figure_t;

cup_t create_cup(int cup_x, int cup_y);
void print_cup(cup_t *matrix);
figure_t create_figure(int figure_x, int figure_y);
void print_figure(figure_t *figure);
void remove_figure(figure_t *figure);
void remove_cup(cup_t *cup);

void fill_smash_boy(figure_t *figure);

void added_figure(cup_t *cup, figure_t *figure);
int move_down(figure_t *figure, cup_t *cup);
void move_left(figure_t *figure, cup_t *cup);
void move_right(figure_t *figure, cup_t *cup);
void copy_figure(figure_t *curr, figure_t *next);
void delete_figure(cup_t *cup, figure_t *figure);
int up_dot(figure_t *figure);
int down_dot(figure_t *figure);

int left_dot(figure_t *figure);
int right_dot(figure_t *figure);

void clear_ghost(cup_t *cup, figure_t *figure);

void menu();

#endif // _FUNC_H_