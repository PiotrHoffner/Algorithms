#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "GenPrimeNumbers.hpp"

#include <vector>

struct GenPrimeNumbersTests : public ::testing::Test {
    size_t argument1 = 20;
    size_t argument2 = 50;
    size_t argument3 = 100;
    size_t argument4 = 2;
    std::vector<int> expected1 = {2, 3, 5, 7, 11, 13, 17, 19};
    std::vector<int> expected2 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    std::vector<int> expected3 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
        53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    std::vector<int> expected4 = {2};     
};

TEST_F(GenPrimeNumbersTests, checkExpected1ForGenPrimeNumbers) {
    EXPECT_THAT(genPrimeNumbers(argument1), testing::Eq(expected1));
}
TEST_F(GenPrimeNumbersTests, checkExpected2ForGenPrimeNumbers) {
    EXPECT_THAT(genPrimeNumbers(argument2), testing::Eq(expected2));
}
TEST_F(GenPrimeNumbersTests, checkExpected3ForGenPrimeNumbers) {
    EXPECT_THAT(genPrimeNumbers(argument3), testing::Eq(expected3));
}
TEST_F(GenPrimeNumbersTests, checkExpected4ForGenPrimeNumbers) {
    EXPECT_THAT(genPrimeNumbers(argument4), testing::Eq(expected4));
}
TEST_F(GenPrimeNumbersTests, throwsExceptionIfPassedArgumentEquals0) {
    EXPECT_THROW(genPrimeNumbers(0), std::invalid_argument);
}
TEST_F(GenPrimeNumbersTests, throwsExceptionIfPassedArgumentEquals1) {
    EXPECT_THROW(genPrimeNumbers(1), std::invalid_argument);
}
