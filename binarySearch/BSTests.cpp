#include "gtest/gtest.h"
#include "binarySearch.hpp"

#include <stdexcept>

struct TestingValues {
    TestingValues(int expected, int searched, unsigned size)
    :   expected(expected), searched(searched), size(size)
    {}

    int expected;
    int searched;
    unsigned size;
};

struct binarySearchTests : public ::testing::TestWithParam<TestingValues> {
    int testArray[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
};

struct binarySearchTests2 : public ::testing::TestWithParam<TestingValues> {
    int testArray2[9] = {51, 52, 53, 54, 55, 56, 57, 58, 59};
};

INSTANTIATE_TEST_SUITE_P(Param1,
                         binarySearchTests,
                         testing::Values(TestingValues{4, 15, 10},
                                         TestingValues{0, 11, 10},
                                         TestingValues{1, 12, 10},
                                         TestingValues{8, 19, 10},
                                         TestingValues{9, 20, 10}                                         
));

INSTANTIATE_TEST_SUITE_P(Param1,
                         binarySearchTests2,
                         testing::Values(TestingValues{4, 55, 10},
                                         TestingValues{0, 51, 10},
                                         TestingValues{1, 52, 10},
                                         TestingValues{7, 58, 10},
                                         TestingValues{8, 59, 10}                                         
));

TEST_P(binarySearchTests, checkExpectedValuesForBinarySearch) {
    EXPECT_EQ(GetParam().expected, 
              binarySearch(GetParam().searched,
                                 testArray,
                                 GetParam().size));
}

TEST_F(binarySearchTests, shouldThrowAnExceptionIfArgumentIsTooLow) {
    EXPECT_THROW(binarySearch(1, testArray, 10), std::exception);
}

TEST_F(binarySearchTests, shouldThrowAnExceptionIfArgumentIsTooHigh) {
    EXPECT_THROW(binarySearch(101, testArray, 10), std::exception);
}

TEST_P(binarySearchTests2, checkExpectedValuesForBinarySearch) {
    EXPECT_EQ(GetParam().expected, 
              binarySearch(GetParam().searched,
                                 testArray2,
                                 GetParam().size));
}

TEST_F(binarySearchTests2, shouldThrowAnExceptionIfArgumentIsTooLow) {
    EXPECT_THROW(binarySearch(1, testArray2, 9), std::exception);
}

TEST_F(binarySearchTests2, shouldThrowAnExceptionIfArgumentIsTooHigh) {
    EXPECT_THROW(binarySearch(101, testArray2, 9), std::exception);
}
