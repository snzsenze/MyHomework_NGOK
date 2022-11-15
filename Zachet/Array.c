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
    int *array_new;
    int chet = 0;
    double orefm_1 = 0;
    double orefm_2 = 0;

    printf("\nВведите размер массива - ");
    scanf("%d", &size);
    printf("Введите размер массива 2 - ");
    scanf("%d", &size_2);

    int size_3 = size + size_2;

    array = (int *)calloc(size, sizeof(int));
    double_array = (int *)calloc(size_2, sizeof(int));
    array_new = (int *)calloc(size_3, sizeof(int));

    for (int i = 0; i < size; ++i) {
        printf("Массив 1 - ");
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; ++i) {
        printf("Массив 2 - ");
        scanf("%d", &double_array[i]);
    }

    for (int i = 0; i <= size; ++i) {
        array_new[i] = array[i];
        array_new[size_3 - i] = double_array[size_2 - i];
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
                printf("\nОдинаковые элементы массива - %d", array[i]);
                chet++;
            }
        }
    }

    bubble_sort(array, size);
    bubble_sort(double_array, size_2);

    printf("\nОдинаковых элементов - %d\n", chet);
    printf("\nМассив - 1 = ");
    print_array(array, size);
    printf("Массив - 2 = ");
    print_array(double_array, size);

    printf("\nСоединение массива - ");
    print_array(array_new, size_3);

    printf("\nOrefmet 1 mas - %f", orefm_1);
    printf("\nOrefmet 2 mas - %f \n\n", orefm_2);

    printf("Сумма эл.1 массивa - %d\n", sum_1);
    printf("Сумма эл.2 массивa - %d\n", sum_2);

    free(array);
    free(double_array);
    free(array_new);
}
