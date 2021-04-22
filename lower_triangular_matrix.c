#include "lower_triangular_matrix.h"

LowerTriangularMatrix create_lower_triangular_matrix(FILE* file) {
    LowerTriangularMatrix matrix;
    fread(&matrix.size, sizeof(int32_t), 1, file);
    matrix.matrix = malloc(sizeof(int32_t*) * matrix.size);
    for (int32_t i = 0; i < matrix.size; i++) {
        matrix.matrix[i] = malloc(sizeof(int32_t) * matrix.size);
        for (int32_t j = 0; j < matrix.size; j++) {
            if (j <= i) {
                fread(&matrix.matrix[i][j], sizeof(int32_t), 1, file);
            } else {
                matrix.matrix[i][j] = 0;
            }
        }
    }
    fread(&matrix.print_method, sizeof(int32_t), 1, file);
    return matrix;
}

void lower_triangular_matrix_write(LowerTriangularMatrix* matrix, FILE* file, PrintMethod print_method) {
    fprintf(file, "Lower triangular matrix:\n");
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

int32_t lower_triangular_matrix_get_sum(LowerTriangularMatrix* matrix) {
    int32_t result = 0;
    for (int32_t i = 0; i < matrix->size; i++) {
        for (int32_t j = 0; j < matrix->size; j++) {
            result += matrix->matrix[i][j];
        }
    }
    return result;
}

void lower_triangular_matrix_clear(LowerTriangularMatrix* matrix) {
    if (matrix->size) {
        for (int32_t i = 0; i < matrix->size; i++) {
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
}