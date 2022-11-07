#ifndef _FUNC_H_
#define _FUNC_H_

typedef struct {

    double **matrix;
    int rows;
    int cols;

} matrix_t;

int eq_size(matrix_t *A, matrix_t *B);
int eq_matrix(matrix_t *A, matrix_t *B);
double detriminant(matrix_t *A);
matrix_t transport(matrix_t *A);
matrix_t multiplic(matrix_t *A, matrix_t *B);
matrix_t sum_matrix(matrix_t *A, matrix_t *B);
matrix_t sub_matrix(matrix_t *A, matrix_t *B);
matrix_t mult_number(matrix_t *A, double num);
matrix_t allocate_matrix(const int rows, const int cols);
void print_matrix(matrix_t *matrix);
void free_matrix(matrix_t *matrix);
void fill_matrix(matrix_t *matrix);

#endif
