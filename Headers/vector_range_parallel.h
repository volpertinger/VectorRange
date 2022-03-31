#ifndef VECTORRANGE_VECTOR_RANGE_PARALLEL_H
#define VECTORRANGE_VECTOR_RANGE_PARALLEL_H

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int get_process_number();

double *get_nearest_vector_parallel(double *vector, int vector_size, double **vectors, int vectors_size);

#endif //VECTORRANGE_VECTOR_RANGE_PARALLEL_H
