#include "gtest/gtest.h"
#include "IsPrimeNumber.hpp"

TEST(IsPrimeNumberTests, returnFalseIfPassed0) {
    EXPECT_EQ(false, isPrimeNumber(0));
}
