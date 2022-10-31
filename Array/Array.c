#include "func.h"
#include <stdio.h>
#define PUP 10
#define PUPU 10

int main()
{
    int double_array[PUPU] = {0};
    int array[PUP] = {0};

    set_mass(array, PUP);
    set_mass(double_array, PUPU);

    print_mass(array, PUP);
    print_mass(double_array, PUPU);

    // printf("max - %d \n", search_max(array, PUP));
    // printf("min - %d \n", search_min(array, PUP));
    // reserve(array, PUP);
    // printf("Index = %d \n", search_index(array, PUP, 5));
    int res = comparsion(array, PUP, double_array, PUPU);
    printf("res = %d\n", res);
}