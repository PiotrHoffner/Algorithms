#include "gtest/gtest.h"
#include "IsPrimeNumber.hpp"

TEST(IsPrimeNumberTests, returnFalseIfPassed0) {
    EXPECT_EQ(false, isPrimeNumber(0));
}
TEST(IsPrimeNumberTests, returnFalseIfPassed1) {
    EXPECT_EQ(false, isPrimeNumber(1));
}
