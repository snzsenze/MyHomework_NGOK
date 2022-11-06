#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main(){
    matrix_t spital_marix;
    spital_marix = allocate_matrix(7, 7);
    fill_matrix(&spital_marix);
    print_matrix(&spital_marix);
}