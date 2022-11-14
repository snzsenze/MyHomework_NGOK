#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum_1 = 0;
    int sum_2 = 0;
    int size = 0;
    int size_2 = 0;
    int *array;
    int *double_array;
    int chet = 0;
    double orefm_1 = 0;
    double orefm_2 = 0;

    printf(" \n Введите размер массива - ");
    scanf("%d", &size);

    printf(" \n Введите размер массива 2 - ");
    scanf("%d", &size_2);

    array = (int *)calloc(size, sizeof(int));
    double_array = (int *)calloc(size_2, sizeof(int));

    for (int i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; ++i) {
        scanf("%d", &double_array[i]);
    }

    for (int i = 0; i < size; ++i) {
        sum_1 += array[i];
        sum_2 += double_array[i];

        orefm_1 = sum_1 / size;
        orefm_2 = sum_2 / size;
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (array[i] == double_array[j]) {
                printf("\n Одинаковые элементы массива - %d", array[i]);
                chet++;
            }
        }
    }

    bubble_sort(array, size);
    bubble_sort(double_array, size_2);

    printf("\n Одинаковых элементов - %d", chet);
    printf(" \n Array - 1 = ");
    print_array(array, size);
    printf(" \n Array - 2 = ");
    print_array(double_array, size);

    printf("\n Orefmet 1 mas - %f", orefm_1);
    printf("\n Orefmet 2 mas - %f \n", orefm_2);

    printf("Сумма эл.1 массивa - %d\n", sum_1);

    printf("Сумма эл.2 массивa - %d\n", sum_2);
}