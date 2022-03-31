#ifndef VECTORRANGE_VECTOR_RANGE_SUCCESSIVELY_H
#define VECTORRANGE_VECTOR_RANGE_SUCCESSIVELY_H

#include "similarity.h"
#include <stdio.h>

// последовательный поиск ближайшего вектора к вектору vector размерности vector_size
// в массиве векторов vectors размера vectors_size
double *get_nearest_vector(double *vector, int vector_size, double **vectors, int vectors_size);

#endif //VECTORRANGE_VECTOR_RANGE_SUCCESSIVELY_H
