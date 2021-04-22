#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "diagonal_matrix.h"
#include "square_matrix.h"

typedef enum Type Type;
enum Type {
    DIAGONAL = 2,
    SQUARE = 1
};

typedef struct Matrix Matrix;
struct Matrix {
    Type type;
    union {
        DiagonalMatrix diagonal_matrix;
        SquareMatrix square_matrix;
    };
};

Matrix create_matrix(FILE* file);

void matrix_write(Matrix* matrix, FILE* file);
void matrix_clear(Matrix* matrix);

#endif