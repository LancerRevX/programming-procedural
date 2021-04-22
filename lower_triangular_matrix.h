#ifndef LOWER_TRIANGULAR_MATRIX_H
#define LOWER_TRIANGULAR_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    size_t size;
    int32_t** matrix;
} LowerTriangularMatrix;

LowerTriangularMatrix create_lower_triangular_matrix(FILE* file);

void lower_triangular_matrix_write(LowerTriangularMatrix* matrix, FILE* file);
void lower_triangular_matrix_clear(LowerTriangularMatrix* matrix);

#endif