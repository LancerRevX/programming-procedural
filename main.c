// Условие задачи №3
// Квадратные матрицы с целочисленными элементами
// 1. Обычный двумерный массив
// 2. Диагональная матрица на основе одномерного массива

// Организация контейнера №2
// Контейнер на основе однонаправленного линейного списка

// Модульная структура №2
// Разбиение на модули осуществляется по объектному принципу.
// То есть описание абстракций и функций их обработки группируются по виду абстракций.
// При этом проводится разделение описания типов, сигнатур и классов от их реализации.
// Клиентский модуль связан с основной частью программы только минимально необходимым интерфейсом.

// Организация обобщений через Union

#include <stdio.h>
#include <stdlib.h>

#include "container.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stdout, "Please specify input and output files\n");
        return EXIT_FAILURE;
    }
    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        fprintf(stdout, "Couldn't open the input file.\n");
        return EXIT_FAILURE;
    }
    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stdout, "Couldn't open the output file.\n");
        return EXIT_FAILURE;
    }

    fprintf(output_file, "Start\n");

    Container container;
    container_init(&container);

    container_read(&container, input_file);
    fprintf(output_file, "Filled container\n");
    container_multimethod(&container, output_file);
    fprintf(output_file, "Written container multimethod\n");

    fprintf(output_file, "Stop\n");
    fflush(output_file);
    fclose(output_file);
    fclose(input_file);

    return EXIT_SUCCESS;
}
