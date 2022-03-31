# include "../Headers/similarity.h"

double count_range(const int n, const double *lhs, const double *rhs) {
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += lhs[i] * rhs[i];
    }
    return result;
}

double count_abs(const int n, const double *vector) {
    if (n <= 0)
        return INVALID_SIZE_RETURN;
    double result = 0;
    for (int i = 0; i < n; ++i) {
        result += pow(vector[i], 2);
    }
    return sqrt(result);
}

double get_similarity(const int n, const double *lhs, const double *rhs) {
    double denominator = (count_abs(n, lhs) * count_abs(n, rhs));
    if (denominator == 0)
        return 0;
    return count_range(n, lhs, rhs) / denominator;
}

double get_distance(const int n, const double *lhs, const double *rhs) {
    if (n <= 0)
        return INVALID_SIZE_RETURN;
    return fabs(get_similarity(n, lhs, rhs) - 1);
}
