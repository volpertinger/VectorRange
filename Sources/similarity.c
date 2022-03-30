# include "../Headers/similarity.h"

double count_range(int n, const double *lhs, const double *rhs) {
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += lhs[i] * rhs[i];
    }
    return result;
}

double count_abs(int n, const double *vector) {
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += vector[i] * vector[i];
    }
    return sqrt(result);
}

double get_similarity(int n, double *lhs, double *rhs) {
    double denominator = (count_abs(n, lhs) * count_abs(n, rhs));
    if (denominator == 0)
        return 0;
    return count_range(n, lhs, rhs) / denominator;
}

double get_distance(int n, double *lhs, double *rhs) {
    return fabs(get_similarity(n, lhs, rhs) - 1);
}
