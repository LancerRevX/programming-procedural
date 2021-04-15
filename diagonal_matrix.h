#ifndef DIAGONAL_MATRIX_H
#define DIAGONAL_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct DiagonalMatrix DiagonalMatrix;
struct DiagonalMatrix {
    size_t size;
    int32_t** matrix;
};

DiagonalMatrix create_diagonal_matrix(FILE* file);

void diagonal_matrix_write(DiagonalMatrix* matrix, FILE* file);
void diagonal_matrix_clear(DiagonalMatrix* matrix);

#endif