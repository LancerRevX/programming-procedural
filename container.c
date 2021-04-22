#include "container.h"
#include "matrix.h"

bool compare(Matrix* left, Matrix* right) {
    return matrix_get_sum(left) > matrix_get_sum(right);
}

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

void container_sort(Container* container) {
    for (size_t i = 0; i < container->size - 1; i++) {
        Node* node = container->first;
        for (size_t j = 0; j < container->size - i - 1; j++) {
            if (compare(&node->matrix, &node->next->matrix)) {
                Matrix tmp = node->matrix;
                node->matrix = node->next->matrix;
                node->next->matrix = tmp;
            }
            node = node->next;
        }
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