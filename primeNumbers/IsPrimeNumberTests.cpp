#include "gtest/gtest.h"
#include "IsPrimeNumber.hpp"

TEST(IsPrimeNumberTests, returnFalseIfPassed0) {
    EXPECT_EQ(false, isPrimeNumber(0));
}
TEST(IsPrimeNumberTests, returnFalseIfPassed1) {
    EXPECT_EQ(false, isPrimeNumber(1));
}
TEST(IsPrimeNumberTests, returnTrueIfPassed2) {
    EXPECT_EQ(true, isPrimeNumber(2));
}
TEST(IsPrimeNumberTests, returnTrueIfPassed3) {
    EXPECT_EQ(true, isPrimeNumber(3));
}
TEST(IsPrimeNumberTests, returnFalseIfPassed4) {
    EXPECT_EQ(false, isPrimeNumber(4));
}
TEST(IsPrimeNumberTests, returnTrueIfPassed5) {
    EXPECT_EQ(true, isPrimeNumber(5));
}
TEST(IsPrimeNumberTests, returnFalseIfPassed6) {
    EXPECT_EQ(false, isPrimeNumber(6));
}
TEST(IsPrimeNumberTests, returnTrueIfPassed7) {
    EXPECT_EQ(true, isPrimeNumber(7));
}
TEST(IsPrimeNumberTests, returnFalseIfPassed20) {
    EXPECT_EQ(false, isPrimeNumber(20));
}
TEST(IsPrimeNumberTests, returnTrueIfPassed23) {
    EXPECT_EQ(true, isPrimeNumber(23));
}
