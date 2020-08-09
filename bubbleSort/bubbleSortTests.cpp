#include "gtest/gtest.h"
#include "areEqual.hpp"
#include "bubbleSort.hpp"

constexpr unsigned arrSize = 10;

struct BubbleSortTests : public ::testing::Test {
    int testArray[arrSize] = {5,6,4,7,3,8,2,9,1,0};
    int sortedArray[arrSize] = {0,1,2,3,4,5,6,7,8,9};
};

TEST_F(BubbleSortTests, checkExpectedForBubbleSort) {
    bubbleSort(testArray, arrSize);
    EXPECT_TRUE(areEqual(testArray, sortedArray, arrSize));
}
