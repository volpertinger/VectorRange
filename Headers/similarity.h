#ifndef VECTORRANGE_SIMILARITY_H
#define VECTORRANGE_SIMILARITY_H

#include "math.h"

double count_range(int n, const double *lhs, const double *rhs);

double count_abs(int n, const double *vector);

double get_similarity(int n, double *lhs, double *rhs);

#endif //VECTORRANGE_SIMILARITY_H
