#include "func.h"
#include <stdio.h>
#include <stdlib.h>

double detriminant(matrix_t *A)
{
    double det = 0;
    if (A->rows == A->cols) {
        if (A->rows == 1) {
            det = A->matrix[0][0];
        } else if (A->rows == 2) {
            det = (A->matrix[0][0] * A->matrix[1][1]) -
                  (A->matrix[1][0] * A->matrix[0][1]);
        }
    }
    return det;
}

matrix_t minor(matrix_t *A, int ip, int jp)
{

    matrix_t neo;
    neo = allocate_matrix(A->rows - 1, A->cols - 1);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            if (i != ip && j != jp) {

                if (i > ip && j < jp) {
                    neo.matrix[i - 1][j] = A->matrix[i][j];
                } else if (i < ip && j > jp) {
                    neo.matrix[i][j - 1] = A->matrix[i][j];
                } else if (i > ip && j > jp) {
                    neo.matrix[i - 1][j - 1] = A->matrix[i][j];
                } else {

                    neo.matrix[i][j] = A->matrix[i][j];
                }
            }
        }
    }
    return neo;
}

matrix_t transport(matrix_t *A)
{

    matrix_t neo;
    neo = allocate_matrix(A->rows, A->cols);

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            neo.matrix[i][j] = A->matrix[j][i];
        }
    }
    return neo;
}

matrix_t multiplic(matrix_t *A, matrix_t *B)
{

    matrix_t neo;
    if (A->cols == B->rows) {
        neo = allocate_matrix(A->rows, B->cols);

        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < B->cols; ++j) {
                for (int k = 0; k < A->cols; ++k) {
                    neo.matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                }
            }
        }
    }
    return neo;
}

matrix_t mult_number(matrix_t *A, double num)
{

    matrix_t neo;
    neo = allocate_matrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->cols; ++j) {
            neo.matrix[i][j] = A->matrix[i][j] * num;
        }
    }
    return neo;
}

matrix_t sum_matrix(matrix_t *A, matrix_t *B)
{

    matrix_t neo;
    if (eq_size(A, B)) {
        neo = allocate_matrix(A->rows, B->cols);

        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < B->cols; ++j) {
                neo.matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
    return neo;
}

matrix_t sub_matrix(matrix_t *A, matrix_t *B)
{

    matrix_t neo;
    if (eq_size(A, B)) {
        neo = allocate_matrix(A->rows, B->cols);

        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < B->cols; ++j) {
                neo.matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return neo;
}

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
    }
    return res;
}
