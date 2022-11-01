#ifndef _ARRAY_H_
#define _ARRAY_H_

void set_array(int *array, const unsigned int size);
void print_array(const int array[], const unsigned int size);
int search_max(const int array[], const unsigned int size);
int search_min(const int array[], const unsigned int size);
void reserve_array(int *array, const unsigned int size);
int search_index(const int array[], const unsigned int size, const int number);
int comparsion_array(const int arrayFirst[], const unsigned int sizeFirst,
               const int arraySecond[], const unsigned int sizeSecond);
void bubble_sort(int *array, const unsigned int size);
int binary_search(int array[], int size, int number);


#endif // _FUNC_H_
