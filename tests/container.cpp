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
    FILE* file = fopen("container.raw", "rb");
    ASSERT_TRUE(file);
    container_read(&container, file);
    fclose(file);
    EXPECT_NE(container.first, nullptr);
    EXPECT_EQ(container.size, 3);
}

TEST(Container, write) {
    Container container;
    container_init(&container);
    FILE* file = fopen("container.raw", "rb");
    ASSERT_TRUE(file);
    container_read(&container, file);
    fclose(file);
    
    open_test_file();
    container_write(&container, test_file, PrintMethod::DEFAULT, false);
    close_test_file();

    EXPECT_EQ(
        test_file_as_string(),
        ""
    );
}