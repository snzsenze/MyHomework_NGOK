#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    matrix_t spital_marix;
    spital_marix = allocate_matrix(10, 10);
    fill_matrix(&spital_marix);
    print_matrix(&spital_marix);
}