#include "func.h"
#include <stdio.h>
#define PUP 10
#define PUPU 10
#define FIND 3

// ubble_sort сортирует
// binary_search работает

int main()
{
    int double_array[PUPU] = {0};

    int array[PUP] = {0};

    set_array(array, PUP);
    set_array(double_array, PUPU);
    bubble_sort(array, PUP);

    int a = binary_search(array, PUP, FIND);
    int b = search_index(array, PUP, FIND);
    printf("a = %d b = %d res = %s\n", a, b, a == b ? "true" : "false");

    print_array(array, PUP);
    print_array(double_array, PUPU);

    int res = comparsion_array(array, PUP, double_array, PUPU);
    printf("Массив (1-совпадает 0-не совпадает) = %d\n", res);

    printf("max - %d \n", search_max(array, PUP));
    printf("min - %d \n", search_min(array, PUP));
    reserve(array, PUP);
    print_array(array, PUP);
    // printf("Index = %d \n", search_index(array, PUP, 5));
}