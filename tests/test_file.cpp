#include "test_file.h"

FILE* test_file;

void open_test_file() {
    test_file = fopen("./test_file.txt", "w");
}

std::string test_file_to_string() {
    std::ifstream stream("./test_file.txt");
    std::stringstream buffer;
    buffer << stream.rdbuf();
    return buffer.str();
}

void close_test_file() {
    fclose(test_file);
}