#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size_1 = 0;
    int size_2 = 0;

    printf("\nВведите размер 1 - ");
    scanf("%d", &size_1);
    printf("Введите размер 2 - ");
    scanf("%d", &size_2);

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
            scanf("%d", &matrix[i][j]);
            setbuf(stdin, NULL);
        }
        printf("\n");
    }

    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            scanf("%d", &double_matrix[i][j]);
            setbuf(stdin, NULL);
        }
        printf("\n");
    }

    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < size_1; ++i) {
        for (int j = 0; j < size_2; ++j) {
            printf(" %d ", double_matrix[i][j]);
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
    printf("\nСумма 1-ой матрицы - %d ", sum);
    printf("\nСумма 2-ой матрицы - %d ", double_sum);
}