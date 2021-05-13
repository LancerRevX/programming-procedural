#include "square_matrix.h"

SquareMatrix create_square_matrix(FILE* file) {
    SquareMatrix matrix;
    fread(&matrix.size, sizeof(int32_t), 1, file);
    matrix.matrix = malloc(sizeof(int32_t*) * matrix.size);
    for (int32_t i = 0; i < matrix.size; i++) {
        matrix.matrix[i] = malloc(sizeof(int32_t) * matrix.size);
        for (int32_t j = 0; j < matrix.size; j++) {
            fread(&matrix.matrix[i][j], sizeof(int32_t), 1, file);
        }
    }
    fread(&matrix.print_method, sizeof(int32_t), 1, file);
    return matrix;
}

void square_matrix_write(SquareMatrix* matrix, FILE* file, PrintMethod print_method) {
    fprintf(file, "Square matrix:\n");
    if (print_method == DEFAULT) {
        print_method = matrix->print_method;
    }
    switch (print_method) {
        case BY_ROWS:
            fprintf(file, "Print method: by rows\n");
            for (int32_t i = 0; i < matrix->size; i++) {
                for (int32_t j = 0; j < matrix->size; j++) {
                    fprintf(file, "%d ", matrix->matrix[i][j]);
                }
                fprintf(file, "\n");
            }
            break;
        case BY_COLUMNS:
            fprintf(file, "Print method: by columns\n");
            for (int32_t j = 0; j < matrix->size; j++) {
                for (int32_t i = 0; i < matrix->size; i++) {
                    fprintf(file, "%d ", matrix->matrix[i][j]);
                }
                fprintf(file, "\n");
            }
            break;
        case ONE_DIMENSIONAL_ARRAY:
            fprintf(file, "Print method: one dimensional array\n");
            for (int32_t i = 0; i < matrix->size; i++) {
                for (int32_t j = 0; j < matrix->size; j++) {
                    fprintf(file, "%d ", matrix->matrix[i][j]);
                }
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
    matrix->size = 0;
    matrix->matrix = NULL;
}