#include <stdio.h>
#include <stdlib.h>
#include "func.h"

matrix_t allocate_matrix(const unsigned int rows, const unsigned int cols)
{
    matrix_t spiral;
    spiral.cols = cols;
    spiral.rows = rows;
    spiral.matrix = (double **)calloc(rows, sizeof(double *));
    for (unsigned int i = 0; i < rows; ++i) {
        spiral.matrix[i] = (double *)calloc(cols, sizeof(double));
    }
    return spiral;
}


void fill_matrix(matrix_t *matrix)
{   

   int value = 0;

   int rowsmin = matrix->rows - 2;

   int i = 0;

   int n = 0;

   int num = 1;
   int result = 0;
   int z = 0;



        while(z<=matrix->rows*matrix->cols){


        for(int j = value; j < matrix->rows - n; ++j){
            matrix->matrix[i][j] = num; num++;
        
            if(num == matrix->rows*matrix->cols + 1){
                // printf("%d", num);
                result = 1;
            }

        }


        for(int j = value + 1; j < matrix->rows - n; ++j){
            matrix->matrix[j][matrix->rows - i - 1] = num; num++;

            if(num == matrix->rows*matrix->cols + 1){
                result = 1;
            }

        }


        for(int j = rowsmin;j >= 0 + n; --j){
            matrix->matrix[matrix->rows - i - 1][j] = num; num++;

            if(num == matrix->rows*matrix->cols + 1){
                result = 1;

            }

        }



        for(int j = rowsmin; j >= 1 + n; --j){
            matrix->matrix[j][i] = num; num++;

            if(num == matrix->rows*matrix->cols + 1){
                result = 1;

            }
        }

    n++; 

    rowsmin--;

    i++;

    value++;


    if(result == 1){
    break;
    }


    }   
}

void print_matrix(matrix_t *matrix)
{
    printf(" Последние значение - %d \n\n", matrix->cols * matrix->rows);
    for (int i = 0; i < matrix->rows; ++i) {
        for (int j = 0; j < matrix->cols; ++j) {
            printf(" |%.2f| ", matrix->matrix[i][j]);
        }
        
        printf("\n\n");
    }
}