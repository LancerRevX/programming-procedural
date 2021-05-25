#include "matrix.h"

#include "diagonal_matrix.h"

Matrix create_matrix(FILE* file) {
    int32_t type;
    fread(&type, sizeof(type), 1, file);
    Matrix matrix = {.type = type};
    switch (type)
    {
        case DIAGONAL:
            matrix.diagonal_matrix = create_diagonal_matrix(file);
            break;
        
        case SQUARE:
            matrix.square_matrix = create_square_matrix(file);
            break;
    }
    return matrix;
}

void matrix_write(Matrix* matrix, FILE* file) {
    switch (matrix->type) {
        case DIAGONAL:
            diagonal_matrix_write(&matrix->diagonal_matrix, file);
            break;
        case SQUARE:
            square_matrix_write(&matrix->square_matrix, file);
            break;
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
    }
}
