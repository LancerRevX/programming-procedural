#include "container.h"
#include "matrix.h"

void container_init(Container* container) {
    container->first = NULL;
}

void container_read(Container* container, FILE* file) {
    Node* node;
    if (container->first != NULL) {
        node = container->first;
        while (node->next) {
            node = node->next;
        }
    } else {
        node = malloc(sizeof(Node));
        container->first = node;
    }
    node->matrix = create_matrix(file);
    node->next = NULL;
    while (!feof(file)) {
        node->next = malloc(sizeof(Node));
        node = node->next;
        node->matrix = create_matrix(file);
        node->next = NULL;
    }
}

void container_write(Container* container, FILE* file) {
    Node* node = container->first;
    if (!node) {
        fprintf(file, "The container is empty!\n");
    } else {
        fprintf(file, "The container contains:\n");
        while (node) {
            matrix_write(&node->matrix, file);
            node = node->next;
        }
    }
}

void container_clear(Container* container) {
    Node* node = container->first;
    while (node)
    {
        Node* next = node->next;
        matrix_clear(&node->matrix);
        free(node);
        node = next;
    }
    
    container_init(container);
}