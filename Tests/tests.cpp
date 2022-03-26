#include <gtest/gtest.h>

extern "C" {
#include "../Include/similarity.h"
}

class TestSimilarity : public ::testing::Test {
protected:
};

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
    ASSERT_EQ(0, count_abs(size, array));
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


int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
