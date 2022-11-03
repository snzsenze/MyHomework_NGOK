#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int eq_size(matrix_t *A, matrix_t *B)
{
    int res = 0;
    if (A->cols == B->cols && A->rows == B->rows) {
        res = 1;
    }
    return res;
}

matrix_t allocate_matrix(const int rows, const int cols)
{
    matrix_t neo;
    neo.rows = rows;
    neo.cols = cols;

    neo.matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; ++i) {
        neo.matrix[i] = (double *)calloc(cols, sizeof(double));
    }
    return neo;
}

void print_matrix(matrix_t *matrix)
{

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            printf(" %.2f ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(matrix_t *matrix)
{

    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            scanf("%lf", &matrix->matrix[i][j]);
            setbuf(stdin, NULL);
        }
        printf("\n");
    }
}

void free_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; ++i) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
}

int eq_matrix(matrix_t *A, matrix_t *B)
{
    int res = 0;
    if (eq_size(A, B)) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; i < B->cols; i++) {
                if (A->matrix[i][j] == B->matrix[i][j]) {
                    res = 1;
                }
            }
        }
        return res;
    }