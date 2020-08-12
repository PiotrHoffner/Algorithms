#include "QuickSort.hpp"
#include "gtest/gtest.h"

#include <algorithm>

struct QuickSortTests : public ::testing::Test {
    int testArr1[10] = {5, 6, 4, 7, 3, 8, 2, 9, 1, 0};
    int expected1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int testArr2[11] = {15, 16, 14, 17, 13, 18, 12, 19, 11, 10, 9};
    int expected2[11] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
};

TEST_F(QuickSortTests, checkExpectedForEvenSizedArray) {
    quickSort(testArr1, 0, 9);
    EXPECT_TRUE(std::equal(std::cbegin(testArr1),
                           std::cend(testArr1),
                           std::cbegin(expected1)));
}

TEST_F(QuickSortTests, checkExpectedForOddSizedArray) {
    quickSort(testArr2, 0, 10);
    EXPECT_TRUE(std::equal(std::cbegin(testArr2),
                           std::cend(testArr2),
                           std::cbegin(expected2)));
}
