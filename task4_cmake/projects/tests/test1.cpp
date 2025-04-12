#include <gtest/gtest.h>
// #include "io.hpp"
#include "sortings.hpp"

TEST(SortTest, EmptyArray) {
    int len = 0;
    int arr[] = {};
    gra::sortings::bubble_sort(arr, len);
    SUCCEED();
}

TEST(SortTest, SingleElement) {
    int len = 1;
    int arr[] = {5};
    gra::sortings::bubble_sort(arr, len);
    EXPECT_EQ(arr[0], 5);
}

TEST(SortTest, Standart) {
    int len = 4;
    int arr[] = {3, 1, 4, 2};
    const int expected[] = {1, 2, 3, 4};
    gra::sortings::bubble_sort(arr, len);

    for (int i = 0; i < len; ++i) {
        EXPECT_EQ(arr[i], expected[i]);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
