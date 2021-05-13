#include <gtest/gtest.h>

extern "C" {
    #include "matrix.h"
    #include "square_matrix.h"
    #include "diagonal_matrix.h"
    #include "lower_triangular_matrix.h"
}


using namespace std;

TEST(Matrix, create) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    Matrix matrix = create_matrix(square_matrix_file);
    EXPECT_EQ(matrix.type, Type::SQUARE);
}

TEST(Matrix, get_sum) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    Matrix matrix = create_matrix(square_matrix_file);
    EXPECT_EQ(matrix_get_sum(&matrix), 1+2+3+4+5+6+7+8+9);
}