#include <gtest/gtest.h>

extern "C" {
    #include "matrix.h"
    #include "square_matrix.h"
    #include "diagonal_matrix.h"
    #include "lower_triangular_matrix.h"
}

#include "test_file.h"

TEST(LowerTriangularMatrix, create) {
    FILE* lower_triangular_matrix_file = fopen("./lower_triangular_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), lower_triangular_matrix_file);
    LowerTriangularMatrix matrix = create_lower_triangular_matrix(lower_triangular_matrix_file);
    fclose(lower_triangular_matrix_file);

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
            {2, 3, 0},
            {4, 5, 6}
        })
    );
}

TEST(LowerTriangularMatrix, write) {
    FILE* lower_triangular_matrix_file = fopen("./lower_triangular_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), lower_triangular_matrix_file);
    LowerTriangularMatrix matrix = create_lower_triangular_matrix(lower_triangular_matrix_file);
    fclose(lower_triangular_matrix_file);

    open_test_file();
    lower_triangular_matrix_write(&matrix, test_file, PrintMethod::DEFAULT);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "Lower triangular matrix:\n"
        "Print method: by rows\n"
        "1 0 0 \n"
        "2 3 0 \n"
        "4 5 6 \n"
    );
}

TEST(LowerTriangularMatrix, clear) {
    FILE* lower_triangular_matrix_file = fopen("./lower_triangular_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), lower_triangular_matrix_file);
    LowerTriangularMatrix matrix = create_lower_triangular_matrix(lower_triangular_matrix_file);
    fclose(lower_triangular_matrix_file);

    lower_triangular_matrix_clear(&matrix);
    open_test_file();
    lower_triangular_matrix_write(&matrix, test_file, PrintMethod::DEFAULT);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "Lower triangular matrix:\n"
        "Print method: by rows\n"
    );
}

TEST(LowerTriangularMatrix, get_sum) {
    FILE* lower_triangular_matrix_file = fopen("./lower_triangular_matrix.raw", "rb");
    int32_t type; fread(&type, 1, sizeof(int32_t), lower_triangular_matrix_file);
    LowerTriangularMatrix matrix = create_lower_triangular_matrix(lower_triangular_matrix_file);
    fclose(lower_triangular_matrix_file);
    EXPECT_EQ(lower_triangular_matrix_get_sum(&matrix), 1+2+3+4+5+6);
}