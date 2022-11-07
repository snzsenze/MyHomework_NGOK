#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    matrix_t neo;
    neo = allocate_matrix(2, 2);

    // matrix_t morfius;
    // morfius = allocate_matrix(3, 3);

    printf("1 - Матрица \n");
    fill_matrix(&neo);
    print_matrix(&neo);
    printf("\n");

    // morfius = minor(&neo, 2, 2);
    // print_matrix(&morfius);

    // printf("2 - Матрица \n");
    // fill_matrix(&morfius);
    // print_matrix(&morfius);
    // printf("\n");

    // printf("eq_matrix = %d\n", eq_size(&neo, &morfius));

    // printf("\n Сумма матриц \n");
    // matrix_t fog = sum_matrix(&neo, &morfius);
    // print_matrix(&fog);

    // printf("\n Вычитание матриц \n");
    // matrix_t subs = sub_matrix(&neo, &morfius);
    // print_matrix(&subs);

    // printf("\n Умножение матриц \n");
    // matrix_t Mults = mult_number(&neo, 5);
    // print_matrix(&Mults);

    // printf("\n Переумножение \n");
    // matrix_t Multi = multiplic(&neo, &morfius);
    // print_matrix(&Multi);

    // printf("\n Транспонированная матрица \n");
    // matrix_t trans = transport(&neo);
    // print_matrix(&trans);

    // printf("\n Минор матрицы \n");
    // matrix_t min = minor(&neo, 1, 1);
    // print_matrix(&min);

    free_matrix(&neo);
    // free_matrix(&morfius);
}
