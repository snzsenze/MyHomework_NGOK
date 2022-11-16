#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 255

int main()
{
    char *str;
    char *double_str;
    char *tmp;
    char *triple_str;

    size_t len1;
    size_t len2;

    str = (char *)calloc(LEN, sizeof(char));
    // double_str = (char *)calloc(LEN, sizeof(char));
    // tmp = (char *)calloc(LEN, sizeof(char));

    printf("\nВведите строку 1\n");
    fgets(str, 255, stdin);
    // printf("\nВведите строку 2\n");
    // fgets(double_str, 255, stdin);
    printf("Строка 1 - %s", str);

    tmp = (char *)calloc(LEN, sizeof(char));

    int k = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] != ' ') {
            tmp[k] = str[i];
            ++k;
        } else {
            printf("tmp = %s\n", tmp);
            memset(tmp, '\0', strlen(tmp));
            k = 0;
        }
        if (i == strlen(str) - 1) {
            printf("tmp = %s\n", tmp);
        }
    }
    // printf("\n");

    // printf("Строка 2 - %s", double_str);
    // strncpy(str, str, strlen(str) - 1);
    // printf("Объединения строк  %s",
    //        strncpy(str, double_str, strlen(double_str) - 1));

    // memcpy(str, double_str, 2);
    // printf("Копирование %s", str);

    // memset(str, 'l', strlen(str));
    // printf("Заполнение %s", str);
    // printf("\n");

    // int res = 0;
    // res = strcmp(str, double_str);
    // if (res == 0) {
    //     printf("Строки одинаковые\n");
    // } else if (res < 0) {
    //     printf("1 строка меньше 2-ой\n");
    // } else if (res > 0) {
    //     printf("1 строка больше 2-ой\n");
    // }

    // printf("\n");
    // printf("Поиск 1 ввода символа  %s\n", strchr(str, 'y'));
    // printf("Поиск последнего ввода символа  %s", strrchr(double_str,
    // 'a'));

    // len1 = strlen(str);
    // len2 = strlen(double_str);

    // printf("\n");
    // printf("Длина 1 строки = %ld \n", len1);
    // printf("Длина 2 строки = %ld \n", len2);
    // printf("\n");

    // strcpy(str, double_str);
    // printf("Строка 1 после копирования - %s", str);
    // printf("Длина строки после копирования - %ld\n", strlen(str));

    free(str);
    // free(double_str);
}