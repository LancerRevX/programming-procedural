#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct SquareMatrix SquareMatrix;
struct SquareMatrix {
    size_t size;
    int32_t** matrix;
};

SquareMatrix create_square_matrix(FILE* file);

void square_matrix_write(SquareMatrix* matrix, FILE* file);
void square_matrix_clear(SquareMatrix* matrix);

#endif