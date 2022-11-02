#include "func.h"
#include <stdio.h>
#define PUP 10
#define PUPU 10
#define FIND 3

int main()
{
    int array[PUP] = {0};
    int double_array[PUPU] = {0};

    fill_random(array, PUP);
    fill_random(double_array, PUPU);

    // set_array(array, PUP);
    // set_array(double_array, PUPU);

    bubble_sort(array, PUP);
    bubble_sort(double_array, PUPU);

    print_array(array, PUP);
    print_array(double_array, PUPU);

    array_swap(array, PUP, double_array, PUPU);

    print_array(array, PUP);
    print_array(double_array, PUPU);

    int res = comparsion_array(array, PUP, double_array, PUPU);
    printf("Массив (1-совпадает 0-не совпадает) = %d\n", res);
    printf("max - %d \n", search_max(array, PUP));
    printf("min - %d \n", search_min(array, PUP));
    reserve(array, PUP);

    print_array(array, PUP);
    binary_search(array, PUP, FIND);
    printf("Index = %d \n", search_index(array, PUP, FIND));

    int a = binary_search(array, PUP, FIND);
    int b = search_index(array, PUP, FIND);
    printf("a = %d b = %d res = %s\n", a, b, a == b ? "true" : "false");
}