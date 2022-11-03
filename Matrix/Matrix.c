#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    matrix_t neo;
    neo = allocate_matrix(5, 5);

    matrix_t morfius;
    morfius = allocate_matrix(5, 5);

    // fill_matrix(&neo);
    // print_matrix(&neo);

    // fill_matrix(&morfius);
    // print_matrix(&morfius);

    printf("eq_matrix = %d\n", eq_size(&neo, &morfius));

    free_matrix(&neo);
    free_matrix(&morfius);
}
