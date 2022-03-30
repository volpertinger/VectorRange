#include "../Headers/vector_initialization.h"

double get_current_element(int x, int y) {
    return -500 + 0.2 * x + y * 4.3;
}

int generate_vectors(FILE *output, int size, int number) {
    if (output == NULL)
        return BAD_FILE_STREAM_EXIT;
    if (size <= 0 || number <= 0)
        return BAD_SIZE_EXIT;

    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < size; ++j) {
            fprintf(output, "%f ", get_current_element(i, j));
        }
        fprintf(output, "\n");
    }

    return COMMON_RETURN;
}

double **get_vector(FILE *input, int size, int number) {
    if (input == NULL || size <= 0 || number <= 0)
        return NULL;

    double **vectors;
    vectors = malloc(sizeof(double *) * number);
    if (vectors == NULL)
        return NULL;

    char buffer[BUFFER_SIZE];
    for (int i = 0; i < number; ++i) {
        double *current_vector;
        current_vector = malloc(sizeof(double) * size);
        if (current_vector == NULL)
            return NULL;

        for (int j = 0; j < size; ++j) {
            if (fscanf(input, "%s", buffer) == EOF)
                return NULL;
            current_vector[j] = strtod(buffer, NULL);
        }
        vectors[i] = current_vector;
    }
    return vectors;
}

