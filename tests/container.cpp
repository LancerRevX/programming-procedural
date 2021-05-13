#include <gtest/gtest.h>

extern "C" {
    #include "container.h"
    #include "matrix.h"
    #include "square_matrix.h"
    #include "diagonal_matrix.h"
    #include "lower_triangular_matrix.h"
}

#include "test_file.h" 

TEST(Container, init) {
    Container container;
    container_init(&container);
    EXPECT_EQ(container.first, nullptr);
    EXPECT_EQ(container.size, 0);
}

TEST(Container, read) {
    Container container;
    container_init(&container);
    FILE* container_file = fopen("./container.raw", "rb");
    ASSERT_TRUE(container_file);
    container_read(&container, container_file);
    fclose(container_file);
    EXPECT_NE(container.first, nullptr);
    EXPECT_EQ(container.size, 3);
}

TEST(Container, write) {
    Container container;
    container_init(&container);
    FILE* container_file = fopen("./container.raw", "rb");
    ASSERT_TRUE(container_file);
    container_read(&container, container_file);
    fclose(container_file);
    
    open_test_file();
    container_write(&container, test_file, PrintMethod::DEFAULT, false);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "The container contains:\n"
        "Square matrix:\n"
        "Print method: by rows\n"
        "1 2 3 \n"
        "4 5 6 \n"
        "7 8 9 \n"
        "Diagonal matrix:\n"
        "Print method: by rows\n"
        "1 0 0 \n"
        "0 2 0 \n"
        "0 0 3 \n"
        "Lower triangular matrix:\n"
        "Print method: by rows\n"
        "1 0 0 \n"
        "2 3 0 \n"
        "4 5 6 \n"
    );
}

TEST(Container, sort) {
    Container container;
    container_init(&container);
    FILE* container_file = fopen("./container.raw", "rb");
    ASSERT_TRUE(container_file);
    container_read(&container, container_file);
    fclose(container_file);
    
    container_sort(&container);
    open_test_file();
    container_write(&container, test_file, PrintMethod::DEFAULT, false);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "The container contains:\n"
        "Diagonal matrix:\n"
        "Print method: by rows\n"
        "1 0 0 \n"
        "0 2 0 \n"
        "0 0 3 \n"
        "Lower triangular matrix:\n"
        "Print method: by rows\n"
        "1 0 0 \n"
        "2 3 0 \n"
        "4 5 6 \n"
        "Square matrix:\n"
        "Print method: by rows\n"
        "1 2 3 \n"
        "4 5 6 \n"
        "7 8 9 \n"
    );
}

TEST(Container, clear) {
    Container container;
    container_init(&container);
    FILE* container_file = fopen("./container.raw", "rb");
    ASSERT_TRUE(container_file);
    container_read(&container, container_file);
    fclose(container_file);
    
    container_clear(&container);
    open_test_file();
    container_write(&container, test_file, PrintMethod::DEFAULT, false);
    close_test_file();

    EXPECT_EQ(
        test_file_to_string(),
        "The container is empty!\n"
    );
}