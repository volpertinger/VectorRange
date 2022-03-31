#ifndef VECTORRANGE_SIMILARITY_H
#define VECTORRANGE_SIMILARITY_H

#include <math.h>
# include <stdlib.h>

// Считает числитель косинусного расстояния; на вход: размерность векторов и два вектора.
double count_range(int n, const double *lhs, const double *rhs);

// Считает знаменатель косинусного расстояния для одного из векторов. На вход: размерность вектора и вектор.
double count_abs(int n, const double *vector);

// Считается косинусное расстояние. На вход: размерность векторов и два вектора.
double get_similarity(int n, double *lhs, double *rhs);

// Переход от косинусного расстояния к более удобному для сравнения в дальнейшем.
// На вход: размерность векторов и два вектора.
double get_distance(int n, double *lhs, double *rhs);

#endif //VECTORRANGE_SIMILARITY_H
