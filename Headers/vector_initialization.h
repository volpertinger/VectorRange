#include <stdio.h>
#include <stdlib.h>

#ifndef VECTORRANGE_VECTOR_INITIALIZATION_H
#define VECTORRANGE_VECTOR_INITIALIZATION_H

#define BAD_SIZE_EXIT 2
#define BAD_FILE_STREAM_EXIT 1
#define COMMON_RETURN 0
#define BUFFER_SIZE 20

// формула для получения элемента вектора по двум переменным
double get_current_element(int x, int y);

// генерирует вектор векторов размерности size с числом
// векторов number и выводит в поток output
// в каждой строке - вектор, через пробелы - его элементы
int generate_vectors(FILE *output, int size, int number);

double **get_vector(FILE *input, int size, int number, int index_start);

#endif //VECTORRANGE_VECTOR_INITIALIZATION_H
