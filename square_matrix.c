#include "square_matrix.h"

SquareMatrix create_square_matrix(FILE* file) {
    int32_t size;
    fread(&size, sizeof(size), 1, file);
    SquareMatrix matrix;
    matrix.size = size;
    matrix.matrix = malloc(sizeof(int32_t*) * size);
    for (int32_t i = 0; i < size; i++) {
        matrix.matrix[i] = malloc(sizeof(int32_t) * size);
        for (int32_t j = 0; j < size; j++) {
            fread(&matrix.matrix[i][j], sizeof(int32_t), 1, file);
        }
    }
    return matrix;
}

void square_matrix_write(SquareMatrix* matrix, FILE* file) {
    fprintf(file, "Square matrix:\n");
    for (int32_t i = 0; i < matrix->size; i++) {
        for (int32_t j = 0; j < matrix->size; j++) {
            fprintf(file, "%d ", matrix->matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

int32_t square_matrix_get_sum(SquareMatrix* matrix) {
    int32_t result = 0;
    for (int32_t i = 0; i < matrix->size; i++) {
        for (int32_t j = 0; j < matrix->size; j++) {
            result += matrix->matrix[i][j];
        }
    }
    return result;
}

void square_matrix_clear(SquareMatrix* matrix) {
    if (matrix->size) {
        for (int32_t i = 0; i < matrix->size; i++) {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
}