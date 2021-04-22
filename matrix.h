#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "diagonal_matrix.h"
#include "square_matrix.h"
#include "lower_triangular_matrix.h"

typedef enum Type Type;
enum Type {
    DIAGONAL = 2,
    SQUARE = 1,
    LOWER_TRIANGULAR = 3
};

typedef struct Matrix Matrix;
struct Matrix {
    Type type;
    union {
        DiagonalMatrix diagonal_matrix;
        SquareMatrix square_matrix;
        LowerTriangularMatrix lower_triangular_matrix;
    };
};

Matrix create_matrix(FILE* file);

void matrix_write(Matrix* matrix, FILE* file);
int32_t matrix_get_sum(Matrix* matrix);
void matrix_clear(Matrix* matrix);

#endif