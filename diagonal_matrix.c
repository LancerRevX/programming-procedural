#include "diagonal_matrix.h"

DiagonalMatrix create_diagonal_matrix(FILE* file) {
    int32_t size;
    fread(&size, sizeof(size), 1, file);
    DiagonalMatrix matrix;
    matrix.size = size;
    matrix.matrix = malloc(sizeof(int32_t*) * size);
    for (int32_t i = 0; i < size; i++) {
        matrix.matrix[i] = malloc(sizeof(int32_t) * size);
        for (int32_t j = 0; j < size; j++) {
            matrix.matrix[i][j] = 0;
        }
        fread(&matrix.matrix[i][i], sizeof(int32_t), 1, file);
    }
    return matrix;
}

void diagonal_matrix_write(DiagonalMatrix* matrix, FILE* file, PrintMethod print_method) {
    fprintf(file, "Diagonal matrix:\n");
        switch (print_method) {
        case BY_ROWS:
            for (int32_t i = 0; i < matrix->size; i++) {
                for (int32_t j = 0; j < matrix->size; j++) {
                    fprintf(file, "%d ", matrix->matrix[i][j]);
                }
                fprintf(file, "\n");
            }
            break;
        case BY_COLUMNS:
            for (int32_t j = 0; j < matrix->size; j++) {
                for (int32_t i = 0; i < matrix->size; i++) {
                    fprintf(file, "%d ", matrix->matrix[i][j]);
                }
                fprintf(file, "\n");
            }
            break;
        case ONE_DIMENSIONAL_ARRAY:
            for (int32_t i = 0; i < matrix->size; i++) {
                for (int32_t j = 0; j < matrix->size; j++) {
                    fprintf(file, "%d ", matrix->matrix[i][j]);
                }
            }
    }   
}

void diagonal_matrix_clear(DiagonalMatrix* matrix) {
    if (matrix->size) {
        for (int32_t i = 0; i < matrix->size; i++) {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
}