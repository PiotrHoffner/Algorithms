#include "gtest/gtest.h"
#include "Nwd.hpp"
#include "TestingValues.hpp"

struct NwdTests : public ::testing::TestWithParam<TestingValues> {};

INSTANTIATE_TEST_SUITE_P(ParamT1,
                         NwdTests,
                         ::testing::Values(TestingValues(4, 12, 8, "Passing two positive numbers(12,8)"),
                                           TestingValues(4, 8, 12, "Passing two positive numbers(8,12)"),
                                           TestingValues(4, -8, 12, "Passing first negative than positive number(-8,12)"),
                                           TestingValues(4, 8, -12, "Passing first positive than negative number(8, -12)"),
                                           TestingValues(4, -8, -12, "Passing two negative numbers(-8, -12)"),
                                           TestingValues(9, 9, 0, "Passing first positive number than zero(9,0)"),
                                           TestingValues(9, 0, 9, "Passing zero first than positie number(0,9)"),
                                           TestingValues(9, -9, 0, "Passing negative number first than 0(-9, 0)"),
                                           TestingValues(9, 0, -9, "Passing zero first, than negative number(0, -9)")
                                           )
);

TEST_P(NwdTests, checkExpectedForGcd) {
    EXPECT_EQ(GetParam().expected, gcd(GetParam().firstArg, GetParam().secondArg));
}

TEST(NwdTests, throwExceptionWhenZerosPassedIn) {
    EXPECT_THROW(gcd(0,0), std::invalid_argument);
}