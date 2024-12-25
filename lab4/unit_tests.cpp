#include "gtest/gtest.h"
#include "sort.h"
#include "area.h"

TEST(SortTest, BubbleSort) {
    int array[] = {5, 2, 8, 1, 3};
    int expected[] = {1, 2, 3, 5, 8};
    int size = sizeof(array) / sizeof(array[0]);

    sortBubble(array, 0, size);  

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(SortTest, QuickSort) {
    int array[] = {9, 7, 5, 11, 12};
    int expected[] = {5, 7, 9, 11, 12};
    int size = sizeof(array) / sizeof(array[0]);

    sortQuick(array, 0, size - 1);

    for (int i = 0; i < size; i++) {
        EXPECT_EQ(array[i], expected[i]);
    }
}

TEST(AreaTest, RectangleArea) {
    EXPECT_EQ(areaRectangle(5, 10), 50);
    EXPECT_EQ(areaRectangle(3, 7), 21);
}

TEST(AreaTest, TriangleArea) {
    EXPECT_EQ(areaTriangle(5, 10), 25);
    EXPECT_EQ(areaTriangle(6, 8), 24);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}