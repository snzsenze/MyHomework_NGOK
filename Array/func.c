#include "func.h"
#include <stdio.h>
#include <stdlib.h>

void set_array(int *array, const unsigned int size){

    for (unsigned int i = 0; i < size; ++i) {
        printf(" Вводите числа через Enter ");
        scanf("%d", &array[i]);
        setbuf(stdin, NULL);
    }
}

void print_array(const int array[], const unsigned int size){
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

void resereserve_array(int *array, const unsigned int size)
{
    int go = array[0];
    for (unsigned int i = 0, j = size - 1; i < size / 2; ++i, --j) {
        array[i] = array[j];
        array[j] = go;
        go = array[i + 1];
    }
}

int comparsion_array(const int array[], const unsigned int PUP, const int double_array[], const unsigned int PUPU){
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

void bubble_sort(int *array, const unsigned int size){

    // Создали переменную для хранения
    int tmp = 0;

    // Цикл Без знаковый И = 0 если И меньше размера-1 тб(10-1)(9) то И++
    for(unsigned int i = 0; i < size - 1; i++){
        for(unsigned int j = 0; j < size - i - 1; j++){
   // Если элемент Джи больше следующего элемента то
            if(array[j] > array[j+1]){
                tmp = array[j];     // записываем в переменную тмп наш элемент
                array[j] = array[j+1]; // элемент будет равен другому тб(было 10 2\ стало 2 10)
                array[j+1] = tmp;   // а след элемент будет равен тому что мы записали на 2ст выше!(tmp = array[j];)
                tmp = array[j+1];   // БЕЗ ЭТОГО ТОЖЕ РОБИТ :)
            }

        }
    }
}

int binary_search(int array[], int size, int number){

    int min_i = 0; // нашли минимальное
    int max_i = size;  // максимальное
    int mid_i = max_i / 2; // находим центр
 
    int res = -1;  

    while (1)
    {
        if (number > array[mid_i]){  // если число которрое мы ввели больше центра то
            min_i = mid_i;                          // минимальное будет равно центральному
            mid_i = (min_i + max_i) / 2;                // и новый мид будет равен (если сложить минимальное и максимальное) и / 2 
        }else if( number == array[mid_i]){      // Иначе если (число которрое мы ввели будет равно нашему центру) то
            res = mid_i;                        // результат будет равен цент знач!
            break;                              // и сразу брейкаем
        }else{                                  // Иначе 
            max_i = mid_i;                      // Наше максимальное будет равно центру а
            mid_i = (max_i + mid_i - 1) / 2;    // центр будет равен (если сложить максимальное и центр-1) и / 2
        }
        if ((mid_i == 0 || mid_i == size - 1) && number != array[mid_i]){   // если наш мид == 0 или мид == размеру масива) и число которое мы ввели не равно центру нашего массива то
            break;                                                                                         // брейкаем
        }
    }
    return res; // возвращаем наш рес
}