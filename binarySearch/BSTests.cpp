#include "gtest/gtest.h"
#include "binarySearch.hpp"

#include <stdexcept>

struct TestingValues {
    TestingValues(int expected, int searched, unsigned size, unsigned left, unsigned right)
    :   expected(expected), searched(searched), size(size), left(left), right(right)
    {}
    int expected;
    int searched;
    unsigned size;
    unsigned left;
    unsigned right;
};

struct BinarySearchTests : public ::testing::TestWithParam<TestingValues> {
    int array[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
};

INSTANTIATE_TEST_SUITE_P(Param1,
                         BinarySearchTests,
                         testing::Values(TestingValues{0, 11, 10, 0, 10},
                                         TestingValues{2, 13, 10, 0, 10},
                                         TestingValues{8, 19, 10, 0, 10},
                                         TestingValues{9, 20, 10, 0, 10}
));

TEST_P(BinarySearchTests, checkExpectedValuesForBinarySearch) {
    EXPECT_EQ(GetParam().expected, 
              binarySearch(GetParam().searched,
                           array,
                           GetParam().size,
                           GetParam().left,
                           GetParam().right));
}

TEST_F(BinarySearchTests, shouldThrowAnExceptionIfArgumentNotFound) {
    EXPECT_THROW(binarySearch(99, array, 10,  0, 10), std::exception);
}
TEST_F(BinarySearchTests, shouldThrowAnExceptionIfRightExceedsSize) {
    EXPECT_THROW(binarySearch(15, array, 10,  0, 11), std::exception);
}
TEST_F(BinarySearchTests, shouldThrowAnExceptionIfLeftIsHigherThanRight) {
    EXPECT_THROW(binarySearch(15, array, 10,  10, 9), std::exception);
}
