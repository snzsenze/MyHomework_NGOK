#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size_1 = 0;
    int size_2 = 0;

    printf("\nВведите размер 1-ой матрицы - ");
    scanf("%d", &size_1);
    printf("Введите размер 2-ой матрицы - ");
    scanf("%d", &size_2);
    printf("\n");

    int **matrix = (int **)calloc(size_1, sizeof(int *));
    for (int i = 0; i < size_1; ++i) {
        matrix[i] = (int *)calloc(size_2, sizeof(int));
    }

    int **double_matrix = (int **)calloc(size_1, sizeof(int *));
    for (int i = 0; i < size_1; ++i) {
        double_matrix[i] = (int *)calloc(size_2, sizeof(int));
    }

    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            printf("Введите значение %d столбца 1-ой матрицы - ", i);
            scanf("%d", &matrix[i][j]);
            setbuf(stdin, NULL);
        }
        printf("\n");
    }

    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            printf("Введите значение %d столбца 2-ой матрицы - ", i);
            scanf("%d", &double_matrix[i][j]);
            setbuf(stdin, NULL);
        }
        printf("\n");
    }

    int sum = 0;
    int double_sum = 0;
    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            sum += matrix[i][j];
            double_sum += double_matrix[i][j];

        }
    }

    printf("-----Ваша-1-матрица-----\n");
    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            printf("[ %d ]", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nСумма 1-ой матрицы - %d\n", sum);
    printf("------------------------\n");

    printf("\n");

    printf("-----Ваша-2-матрица-----\n");
    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            printf("[ %d ]", double_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nСумма 2-ой матрицы - %d\n", double_sum);
    printf("------------------------\n");

    
}