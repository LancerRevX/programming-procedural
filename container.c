#include "container.h"
#include "matrix.h"

void container_init(Container* container) {
    container->first = NULL;
    container->size = 0;
}

void container_read(Container* container, FILE* file) {
    Node* node = NULL;
    if (container->first != NULL) {
        node = container->first;
        while (node->next) {
            node = node->next;
        }
    }
    
    while (true) {
        Matrix matrix = create_matrix(file);    
        if (feof(file)) {
            break;
        }
        Node* new_node = malloc(sizeof(Node));
        new_node->matrix = matrix;
        new_node->next = NULL;
        if (node) {
            node->next = new_node;
            node = node->next;
        } else {
            container->first = new_node;
            node = new_node;
        }
        container->size += 1;
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