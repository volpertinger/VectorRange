#include "Headers/vector_range_successively.h"
#include "Headers/vector_initialization.h"
#include "Headers/vector_range_parallel.h"

#define MAX_PATH 260

int main() {
    printf("Usage: {vectors filename} {size of vector} {number of vectors} {parallel} {vector}\n "
           "Data format: each vector on a new line, elements separated by spaces\n"
           "Parallel: 0 - successively 1 - parallel\n");

    char filename[MAX_PATH];
    int size, number, parallel;
    if (!scanf("%s %d %d %d", filename, &size, &number, &parallel))
        return 1;
    double vector[size];
    for (int i = 0; i < size; ++i) {
        if (!scanf("%lf", &vector[i]))
            return 1;
    }

    FILE *file;
    file = fopen(filename, "r");
    if (!file)
        return 1;
    double **vectors = get_vector(file, size, number);

    double *nearest_vector;
    if (!parallel) {
        nearest_vector = get_nearest_vector(vector, size, vectors, number);
    } else {
        nearest_vector = get_nearest_vector_parallel(vector, size, vectors, number);
    }

    for (int i = 0; i < size; ++i) {
        printf("%f ", nearest_vector[i]);
    }

    for (int i = 0; i < number; ++i)
        free(vectors[i]);
    free(vectors);

    fclose(file);

    return 0;
}
