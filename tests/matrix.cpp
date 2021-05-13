#include <gtest/gtest.h>

extern "C" {
    #include "matrix.h"
    #include "square_matrix.h"
    #include "diagonal_matrix.h"
    #include "lower_triangular_matrix.h"
}

#include "test_file.h"

TEST(Matrix, create) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    Matrix matrix = create_matrix(square_matrix_file);
    fclose(square_matrix_file);
    EXPECT_EQ(matrix.type, Type::SQUARE);
}

TEST(Matrix, get_sum) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    Matrix matrix = create_matrix(square_matrix_file);
    fclose(square_matrix_file);
    EXPECT_EQ(matrix_get_sum(&matrix), 1+2+3+4+5+6+7+8+9);
}

TEST(Matrix, write) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    Matrix matrix = create_matrix(square_matrix_file);
    fclose(square_matrix_file);

    open_test_file();
    matrix_write(&matrix, test_file, PrintMethod::DEFAULT);
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

TEST(Matrix, clear) {
    FILE* square_matrix_file = fopen("./square_matrix.raw", "rb");
    Matrix matrix = create_matrix(square_matrix_file);
    fclose(square_matrix_file);

    matrix_clear(&matrix);
    open_test_file();
    matrix_write(&matrix, test_file, PrintMethod::DEFAULT);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "Square matrix:\n"
        "Print method: by rows\n"
    );
}