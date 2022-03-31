# include "../Headers/vector_range_parallel.h"
# include "../Headers/similarity.h"

#include <stdio.h>

int get_process_number() {
    return (int) sysconf(_SC_NPROCESSORS_ONLN) / 2;
}

int get_step(int vectors_size) {
    return vectors_size / get_process_number();
}

int get_end_index(int vectors_size, int index) {
    if (index < 0 || index == get_process_number() - 1)
        return vectors_size - 1;
    // не последний кусок
    return get_step(vectors_size) * (index + 1);

}

int get_begin_index(int vectors_size, int index) {
    if (index < 0)
        return 0;
    // не последний кусок
    if (index != get_process_number() - 1) {
        return get_step(vectors_size) * index;
    }
    // начало последнего куска - конец предпоследнего
    return get_end_index(vectors_size, index - 1);
}

double *get_nearest_vector_process(double *vector, int vector_size, double **vectors, int index_begin,
                                   int index_end) {
    if (index_begin > index_end || index_begin < 0 || index_end < 0)
        return NULL;

    double min = get_distance(vector_size, vector, vectors[index_begin]);
    double *nearest_vector = vectors[index_begin];
    for (int i = index_begin; i <= index_end; ++i) {
        double current_distance = get_distance(vector_size, vector, vectors[i]);
        if (current_distance < min) {
            min = current_distance;
            nearest_vector = vectors[i];
        }
    }
    return nearest_vector;
}

double *get_nearest_vector_parallel(double *vector, int vector_size, double **vectors, int vectors_size) {
    if (vector_size <= 0 || vectors_size <= 0 || vector == NULL || vectors == NULL)
        return NULL;

    int process_number = get_process_number();
    // дальше создаются процессы и чтобы цикл работал верно, нужно знать родительский pid
    pid_t main_pid = getpid();
    // массив pid созданных
    pid_t pid_array[process_number];


    for (int i = 0; i < process_number; ++i) {
        pid_array[i] = fork();
        // проверка, чтобы создать нужное количество процессов только в главном
        if (getpid() != main_pid) {
            printf("BEGIN: %d %d\n", get_begin_index(vectors_size, i), get_end_index(vectors_size, i));
            double *vector_nearest = get_nearest_vector_process(vector, vectors_size, vectors,
                                                                get_begin_index(vectors_size, i),
                                                                get_end_index(vectors_size, i));
            for (int j = 0; j < vector_size; ++j)
                printf("%f ", vector_nearest[j]);
            printf("\n");
            return vector_nearest;
        }
    }

    if (getpid() == main_pid) {
        for (int i = 0; i < process_number; ++i) {
            printf("ARR:%d \n", pid_array[i]);
            waitpid(pid_array[i], 0, 0);
        }
    }

    /*
     for (int j = 0; j < vector_size; ++j)
                printf("%f ", vector_nearest[j]);
            break;
     */
/*
double min = get_distance(vector_size, vector, vectors[0]);
double *nearest_vector = vectors[0];
for (int i = 0; i < vectors_size; ++i) {
    double current_distance = get_distance(vector_size, vector, vectors[i]);
    if (current_distance < min) {
        min = current_distance;
        nearest_vector = vectors[i];
    }
}
return nearest_vector;
 */
}