# include "../Headers/vector_range_successively.h"

double *get_nearest_vector(double *vector, int vector_size, double **vectors, double vectors_size) {
    if (vector_size <= 0 || vectors_size <= 0 || vector == NULL || vectors == NULL)
        return NULL;
    double min = get_similarity(vector_size, vector, vectors[0]);
    double *nearest_vector = vectors[0];
    for (int i = 0; i < vectors_size; ++i) {
        double current_similarity = get_similarity(vector_size, vector, vectors[i]);
        if (current_similarity < min) {
            min = current_similarity;
            nearest_vector = vectors[i];
        }
    }
    return nearest_vector;
}
