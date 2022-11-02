#include <stdio.h>

int main()
{

    int numbers = 0;
    int sum = 0;
    int tmp = 0;

    scanf("%d", &numbers);

    while (numbers != 0) {

        // 123 = 123 % 10 = 3
        // 123 / 10 = 12
        // 12 % 10 = 2
        // 12 / 10 = 1

        tmp = numbers % 10;
        numbers /= 10;
        sum += tmp;
    }
    printf("sum = %d\n", sum);
}