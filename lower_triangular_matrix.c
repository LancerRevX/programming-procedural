#include "lower_triangular_matrix.h"

LowerTriangularMatrix create_lower_triangular_matrix(FILE* file) {
    int32_t size;
    fread(&size, sizeof(size), 1, file);
    LowerTriangularMatrix matrix;
    matrix.size = size;
    matrix.matrix = malloc(sizeof(int32_t) * size);
    for (int32_t i = 0; i < size; i++) {
        matrix.matrix[i] = malloc(sizeof(int32_t) * size);
        for (int32_t j = 0; j < size; j++) {
            if (j <= i) {
                fread(&matrix.matrix[i][j], sizeof(int32_t), 1, file);
            } else {
                matrix.matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

void lower_triangular_matrix_write(LowerTriangularMatrix* matrix, FILE* file) {
    fprintf(file, "Lower triangular matrix:\n");
    for (int32_t i = 0; i < matrix->size; i++) {
        for (int32_t j = 0; j < matrix->size; j++) {
            fprintf(file, "%d ", matrix->matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

void lower_triangular_matrix_clear(LowerTriangularMatrix* matrix) {
    if (matrix->size) {
        for (int32_t i = 0; i < matrix->size; i++) {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
}