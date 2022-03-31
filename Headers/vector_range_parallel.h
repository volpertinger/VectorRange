#ifndef VECTORRANGE_VECTOR_RANGE_PARALLEL_H
#define VECTORRANGE_VECTOR_RANGE_PARALLEL_H

#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Получить число процессов
int get_processes_number();

// Параллельный поиск ближайшего вектора. На вход: вектор, к которому ищется ближайший; размерность векторов;
// Массив векторов, в которых ищем ближайший; количество векторов.
double *get_nearest_vector_parallel(double *vector, int vector_size, double **vectors, int vectors_size);

// Получение шага для разделения массива векторов на куски для потоков. На входе - размер массива векторов.
int get_step(int vectors_size);

// Получение индекса конца промежутка в массиве векторов для потока
int get_end_index(int vectors_size, int index);

//Получение индекса начала промежутка в массиве векторов для потока
int get_begin_index(int vectors_size, int index);

// Поиск ближайшего вектора в промежутке массива векторов. На входе: вектор, к которому ищется ближайший;
// Размерность векторов; массив векторов, в котором ищем ближайший; индекс начала промежутка;
// индекс конца промежутка
double *get_nearest_vector_single_process(double *vector, int vector_size, double **vectors, int index_begin,
                                          int index_end);


#endif //VECTORRANGE_VECTOR_RANGE_PARALLEL_H
