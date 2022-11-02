#ifndef _FUNC_H_
#define _FUNC_H_

//////////////////////////////////////////////////
// допиши аргументы
void set_array(int *array, const unsigned int size);
void print_array(const int array[], const unsigned int size);
int search_max(const int array[], const unsigned int size);
int search_min(const int array[], const unsigned int size);
void reserve(int *array, const unsigned int size);
int search_index(const int array[], const unsigned int size, const int number);
int comparsion_array(const int array[], const unsigned int PUP,
                     const int double_array[], const unsigned int PUPU);
void bubble_sort(int *array, const unsigned int size);
int binary_search(int array[], int size, int number);

#endif // _FUNC_H_