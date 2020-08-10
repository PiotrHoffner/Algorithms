#include "gtest/gtest.h"
#include "../bubbleSort/areEqual.hpp"
#include "quickSort.hpp"

#include <iostream>

constexpr unsigned arr1Size = 10;
constexpr unsigned arr2Size = 11;

struct quickSortTests : public ::testing::Test {
    int testArray1[arr1Size] = {5,6,4,7,3,8,2,9,1,0};
    int expected1[arr1Size] = {0,1,2,3,4,5,6,7,8,9};

    int testArray2[arr2Size] = {25,26,24,27,23,28,22,29,21,20,19};
    int expected2[arr2Size] = {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
};

TEST_F(quickSortTests, shouldReturnExpected1WhenTestArray1WasPassedIn) {
    quickSort(testArray1, 0, 9);
    EXPECT_TRUE(areEqual(expected1, testArray1, 10));
}

TEST_F(quickSortTests, shouldReturnExpected2WhenTestArray2WasPassedIn) {
    quickSort(testArray2, 0, 10);
    EXPECT_TRUE(areEqual(expected2, testArray2, 11));
}
