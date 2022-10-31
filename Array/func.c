#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void set_mass(int *array, const unsigned int size){

    for (unsigned int i = 0; i < size; ++i) {
        printf(" Вводите числа через Enter ");
        scanf("%d", &array[i]);
        setbuf(stdin, NULL);
    }
}

void print_mass(const int array[], const unsigned int size){
    for (unsigned int i = 0; i < size; ++i) {
        printf(" |%d| ", array[i]);
    }
    printf("\n");
}

int search_max(const int array[], const unsigned int size){
    int max = array[0];
    for (unsigned int i = 1; i < size; ++i) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}

int search_index(const int array[], const unsigned int size, const int number){
    int index = 0;
    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] == number) {
            index = i;
            break;
        }
    }
    return index;
}

int search_min(const int array[], const unsigned int size)
{
    int min = array[0];
    for (unsigned int i = 1; i < size; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}

void reserve(int *array, const unsigned int size)
{
    int go = array[0];
    for (unsigned int i = 0, j = size - 1; i < size / 2; ++i, --j) {
        array[i] = array[j];
        array[j] = go;
        go = array[i + 1];
    }
}

int comparsion(const int array[], const unsigned int PUP, const int double_array[], const unsigned int PUPU){
    int res = 1;

    if (PUP == PUPU) {

        for (unsigned int i = 0; i < PUP; i++)
            if (array[i] != double_array[i]) {
                res = 0;
                break;
            }
    } else {
        res = 0;
    }
    return res;
}