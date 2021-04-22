#ifndef SQUARE_MATRIX_H
#define SQUARE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "print_method.h"

typedef struct SquareMatrix SquareMatrix;
struct SquareMatrix {
    size_t size;
    int32_t** matrix;
    PrintMethod print_method;
};

SquareMatrix create_square_matrix(FILE* file);

int32_t square_matrix_get_sum(SquareMatrix* matrix);
void square_matrix_write(SquareMatrix* matrix, FILE* file, PrintMethod print_method);
void square_matrix_clear(SquareMatrix* matrix);

#endif