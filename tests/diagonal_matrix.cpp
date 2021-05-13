#include <gtest/gtest.h>

extern "C" {
    #include "matrix.h"
    #include "square_matrix.h"
    #include "diagonal_matrix.h"
    #include "lower_triangular_matrix.h"
}

using namespace std;

TEST(DiagonalMatrix, create) {
    FILE* diagonal_matrix_file = fopen("./diagonal_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), diagonal_matrix_file);
    DiagonalMatrix matrix = create_diagonal_matrix(diagonal_matrix_file);

    std::vector<std::vector<int32_t>> matrix_vector(matrix.size);
    for (size_t i {0}; i < matrix.size; i++) {
        matrix_vector[i].resize(matrix.size);
        for (size_t j {0}; j < matrix.size; j++) {
            matrix_vector[i][j] = matrix.matrix[i][j];
        }
    }
    EXPECT_EQ(
        matrix_vector, 
        std::vector<std::vector<int32_t>>({
            {1, 0, 0},
            {0, 2, 0},
            {0, 0, 3}
        })
    );
}

TEST(DiagonalMatrix, get_sum) {
    FILE* diagonal_matrix_file = fopen("./diagonal_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), diagonal_matrix_file);
    DiagonalMatrix matrix = create_diagonal_matrix(diagonal_matrix_file);
    EXPECT_EQ(diagonal_matrix_get_sum(&matrix), 1+2+3);
}