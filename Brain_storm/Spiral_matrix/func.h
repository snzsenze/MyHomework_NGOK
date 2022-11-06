#ifndef _FUNC_H_
#define _FUNC_H_


typedef struct {
    double **matrix;
    int rows;
    int cols;
} matrix_t;


matrix_t allocate_matrix(const unsigned int rows, const unsigned int cols);
void print_matrix(matrix_t *matrix);
void fill_matrix(matrix_t *matrix);

#endif // _FUNC_H_