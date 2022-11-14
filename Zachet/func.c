#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(const int array[], const unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i) {
        printf(" |%d| ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int *array, const unsigned int size)
{

    int tmp = 0;

    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = 0; j < size - i - 1; j++) {

            if (array[j] > array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];

                array[j + 1] = tmp;

                tmp = array[j + 1];
            }
        }
    }
}
