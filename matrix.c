#include "matrix.h"

#include "diagonal_matrix.h"

Matrix create_matrix(FILE* file) {
    int32_t type;
    fread(&type, sizeof(type), 1, file);
    Matrix matrix = {.type = type};
    switch (type) {
        case DIAGONAL:
            matrix.diagonal_matrix = create_diagonal_matrix(file);
            break;
        case SQUARE:
            matrix.square_matrix = create_square_matrix(file);
            break;
        case LOWER_TRIANGULAR:
            matrix.lower_triangular_matrix = create_lower_triangular_matrix(file);
            break;
    }
    return matrix;
}

void matrix_write(Matrix* matrix, FILE* file, PrintMethod print_method) {
    switch (matrix->type) {
        case DIAGONAL:
            diagonal_matrix_write(&matrix->diagonal_matrix, file, print_method);
            break;
        case SQUARE:
            square_matrix_write(&matrix->square_matrix, file, print_method);
            break;
        case LOWER_TRIANGULAR:
            lower_triangular_matrix_write(&matrix->lower_triangular_matrix, file, print_method);
            break;
    }
}

int32_t matrix_get_sum(Matrix* matrix) {
    switch (matrix->type) {
        case DIAGONAL:
            return diagonal_matrix_get_sum(&matrix->diagonal_matrix);
        case SQUARE:
            return square_matrix_get_sum(&matrix->square_matrix);
        case LOWER_TRIANGULAR:
            return lower_triangular_matrix_get_sum(&matrix->lower_triangular_matrix);
    }
}

void matrix_multimethod(Matrix* left, Matrix* right, FILE* file) {
    switch (left->type)
    {
        case SQUARE:
            switch (right->type)
            {
                case SQUARE:
                    fprintf(file, "Two square matrices\n");
                    break;
                case DIAGONAL:
                    fprintf(file, "Square matrix and diagonal matrix\n");
                    break;
            }
            break;

        case DIAGONAL:
            switch (right->type)
            {
                case SQUARE:
                    fprintf(file, "Diagonal matrix and square matrix\n");
                    break;
                case DIAGONAL:
                    fprintf(file, "Two diagonal matrices\n");
                    break;
            }
    }
}

void matrix_clear(Matrix* matrix) {
    switch (matrix->type) {
        case DIAGONAL:
            diagonal_matrix_clear(&matrix->diagonal_matrix);
            break;
        case SQUARE:
            square_matrix_clear(&matrix->square_matrix);
            break;
        case LOWER_TRIANGULAR:
            lower_triangular_matrix_clear(&matrix->lower_triangular_matrix);
            break;
    }
}
