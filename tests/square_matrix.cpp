#include <gtest/gtest.h>

extern "C" {
    #include "matrix.h"
    #include "square_matrix.h"
    #include "diagonal_matrix.h"
    #include "lower_triangular_matrix.h"
}

#include "test_file.h"

TEST(SquareMatrix, create) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), square_matrix_file);
    SquareMatrix matrix = create_square_matrix(square_matrix_file);

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
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        })
    );
}

TEST(SquareMatrix, write) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), square_matrix_file);
    SquareMatrix matrix = create_square_matrix(square_matrix_file);
    fclose(square_matrix_file);

    open_test_file();
    square_matrix_write(&matrix, test_file, PrintMethod::DEFAULT);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "Square matrix:\n"
        "Print method: by rows\n"
        "1 2 3 \n"
        "4 5 6 \n"
        "7 8 9 \n"
    );
}

TEST(SquareMatrix, clear) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), square_matrix_file);
    SquareMatrix matrix = create_square_matrix(square_matrix_file);
    fclose(square_matrix_file);

    square_matrix_clear(&matrix);
    open_test_file();
    square_matrix_write(&matrix, test_file, PrintMethod::DEFAULT);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "Square matrix:\n"
        "Print method: by rows\n"
    );
}

TEST(SquareMatrix, get_sum) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), square_matrix_file);
    SquareMatrix matrix = create_square_matrix(square_matrix_file);
    EXPECT_EQ(square_matrix_get_sum(&matrix), 1+2+3+4+5+6+7+8+9);
}