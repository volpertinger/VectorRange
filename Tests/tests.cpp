#include <gtest/gtest.h>
#include <stdlib.h>

extern "C" {
#include "../Headers/similarity.h"
#include "../Headers/vector_range_successively.h"
#include "../Headers/vector_range_parallel.h"
#include "../Headers/vector_initialization.h"
}

class TestSimilarity : public ::testing::Test {
};

class TestVectorRangeSuccessively : public ::testing::Test {
};

class TestVectorInitialization : public ::testing::Test {
public:
    int size = 3;
    int number = 10;
    char fileName[20] = "fileTest";
    double **vectors;
    FILE *file;

    void SetUp() {
        file = fopen(fileName, "w");
        fclose(file);

        vectors = new double *[number];
        for (int i = 0; i < number; ++i) {
            auto current_vector = new double[size];
            for (int j = 0; j < size; ++j) {
                current_vector[j] = get_current_element(i, j);
            }
            vectors[i] = current_vector;
        }
    }

    void TearDown() {
        remove(fileName);
        for (int i = 0; i < number; ++i) {
            delete[] vectors[i];
        }
        delete[] vectors;
    }
};

class TestVectorRangeParallel : public ::testing::Test {};

TEST_F(TestSimilarity, count_range) {
    const int size = 4;
    double lhs[size] = {10, 0, 20, 3};
    double rhs[size] = {0, 0, 2, 5};
    ASSERT_EQ(55, count_range(size, lhs, rhs));
}

TEST_F(TestSimilarity, count_range_zeros) {
    const int size = 4;
    double lhs[size] = {0, 0, 0, 0};
    double rhs[size] = {0, 0, 0, 0};
    ASSERT_EQ(0, count_range(size, lhs, rhs));
}

TEST_F(TestSimilarity, count_range_empty) {
    const int size = 0;
    double lhs[size] = {};
    double rhs[size] = {};
    ASSERT_EQ(0, count_range(size, lhs, rhs));
}

TEST_F(TestSimilarity, count_range_doubles) {
    const int size = 4;
    double lhs[size] = {1, 2, 3, 5};
    double rhs[size] = {6.345, -9.245, -100, 34.343};
    ASSERT_EQ(-140.42999999999995, count_range(size, lhs, rhs));
}

TEST_F(TestSimilarity, count_abs) {
    const int size = 4;
    double array[size] = {2, 2, 2, 2};
    ASSERT_EQ(4, count_abs(size, array));
}

TEST_F(TestSimilarity, count_abs_zeros) {
    const int size = 4;
    double array[size] = {0, 0, 0, 0};
    ASSERT_EQ(0, count_abs(size, array));
}

TEST_F(TestSimilarity, count_abs_empty) {
    const int size = 0;
    double array[size] = {};
    ASSERT_EQ(-1, count_abs(size, array));
}

TEST_F(TestSimilarity, count_abs_doubles) {
    const int size = 4;
    double array[size] = {1.5, 123.322, -345.65, 0};
    ASSERT_EQ(366.99385306023856, count_abs(size, array));
}

TEST_F(TestSimilarity, get_similarity) {
    const int size = 4;
    double lhs[size] = {1, 2, 3, 5};
    double rhs[size] = {6, -9, -1, 34};
    ASSERT_EQ(0.69536796727361272, get_similarity(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_similarity_zeros) {
    const int size = 4;
    double lhs[size] = {0, 0, 0, 0};
    double rhs[size] = {0, 0, 0, 0};
    ASSERT_EQ(0, get_similarity(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_similarity_empty) {
    const int size = 0;
    double lhs[size] = {};
    double rhs[size] = {};
    ASSERT_EQ(0, get_similarity(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_similarity_doubles) {
    const int size = 4;
    double lhs[size] = {1.24, 2.4433, 3, 5.2};
    double rhs[size] = {6, -9.34, -1.1, 34.2};
    ASSERT_EQ(0.67045646948567628, get_similarity(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_distance) {
    const int size = 4;
    double lhs[size] = {1, 2, 3, 5};
    double rhs[size] = {6, -9, -1, 34};
    ASSERT_EQ(0.30463203272638728, get_distance(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_distance_zeros) {
    const int size = 4;
    double lhs[size] = {0, 0, 0, 0};
    double rhs[size] = {0, 0, 0, 0};
    ASSERT_EQ(1, get_distance(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_distance_empty) {
    const int size = 0;
    double lhs[size] = {};
    double rhs[size] = {};
    ASSERT_EQ(-1, get_distance(size, lhs, rhs));
}

TEST_F(TestSimilarity, get_distance_doubles) {
    const int size = 4;
    double lhs[size] = {1.24, 2.4433, 3, 5.2};
    double rhs[size] = {6, -9.34, -1.1, 34.2};
    ASSERT_EQ(0.32954353051432372, get_distance(size, lhs, rhs));
}

TEST_F(TestVectorRangeSuccessively, common_data) {
    const int size_vector = 3;
    const int size_vectors = 3;
    auto **vectors = new double *[size_vectors];
    for (int i = 0; i < size_vectors; ++i) {
        vectors[i] = new double[size_vector];
    }
    vectors[0][0] = 1.4;
    vectors[0][1] = 1.2;
    vectors[0][2] = 1.;
    vectors[1][0] = 5.34;
    vectors[1][1] = 5.;
    vectors[1][2] = 5.2;
    vectors[2][0] = 10.32;
    vectors[2][1] = 18.23;
    vectors[2][2] = 70.;
    auto *vector = new double[size_vector];
    vector[0] = vectors[1][0];
    vector[1] = vectors[1][1];
    vector[2] = vectors[1][2];
    auto nearestVector = get_nearest_vector(vector, size_vector, vectors, size_vectors);
    ASSERT_EQ(vectors[1], nearestVector);
}

TEST_F(TestVectorInitialization, get_current_element) {
    ASSERT_EQ(-495.5, get_current_element(0, 0));
    ASSERT_EQ(-430.4, get_current_element(0, 1));
    ASSERT_EQ(-149.89999999999998, get_current_element(0, 2));
    ASSERT_EQ(54.100000000000065, get_current_element(2748, 0));
    ASSERT_EQ(1123.5, get_current_element(8095, 0));
}

TEST_F(TestVectorInitialization, write_vectors) {
    file = fopen(fileName, "w");
    write_vectors(file, size, number);
    fclose(file);
    file = fopen(fileName, "r");
    auto vectors_test = get_vector(file, size, number);

    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < size; ++j) {
            // Округляем т.к. точность при чтении с файла теряется
            ASSERT_EQ(round(vectors_test[i][j] * 100) / 100., round(vectors[i][j] * 100) / 100.);
        }
    }
}

TEST_F(TestVectorRangeParallel, common_data) {
    const int size_vector = 3;
    const int size_vectors = 3;
    auto **vectors = new double *[size_vectors];
    for (int i = 0; i < size_vectors; ++i) {
        vectors[i] = new double[size_vector];
    }
    vectors[0][0] = 1.4;
    vectors[0][1] = 1.2;
    vectors[0][2] = 1.;
    vectors[1][0] = 5.34;
    vectors[1][1] = 5.;
    vectors[1][2] = 5.2;
    vectors[2][0] = 10.32;
    vectors[2][1] = 18.23;
    vectors[2][2] = 70.;
    auto *vector = new double[size_vector];
    vector[0] = vectors[2][0];
    vector[1] = vectors[2][1];
    vector[2] = vectors[2][2];
    auto nearestVector = get_nearest_vector_parallel(vector, size_vector, vectors, size_vectors);
    for (int i = 0; i < size_vectors; ++i) {
        ASSERT_EQ(round(vectors[2][i] * 100) / 100., round(nearestVector[i] * 100) / 100.);
    }
}


int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
