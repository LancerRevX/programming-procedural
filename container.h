#ifndef CONTAINER_C
#define CONTAINER_C

#include <stdio.h>

#include "matrix.h"

typedef struct Node Node;
struct Node {
    Matrix matrix;
    Node* next;
};

typedef struct Container Container;
struct Container {
    Node* first;
    size_t size;
};

void container_init(Container*);
void container_read(Container*, FILE*);
void container_write(Container*, FILE*);
void container_clear(Container*);

#endif