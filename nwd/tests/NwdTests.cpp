#include "gtest/gtest.h"
#include "Nwd.hpp"
#include "TestingValues.hpp"

struct NwdTests : public ::testing::TestWithParam<TestingValues> {};

INSTANTIATE_TEST_SUITE_P(ParamT1,
                         NwdTests,
                         ::testing::Values(TestingValues(4, 12, 8, "Passing two positive numbers"),
                                           TestingValues(4, 8, 12, "Passing two positive numbers"),
                                           TestingValues(4, -8, 12, "Passing first negative than positive number"),
                                           TestingValues(4, 8, -12, "Passing first positive than negative number"),
                                           TestingValues(4, -8, -12, "Passing two negative numbers"),
                                           TestingValues(9, 9, 0, "Passing first positive number than zero"),
                                           TestingValues(9, 0, 9, "Passing zero first than positie number"),
                                           TestingValues(9, -9, 0, "Passing negative number first than 0"),
                                           TestingValues(9, 0, -9, "Passing zero first, than negative number"),
                                           TestingValues(8, 8, 16, "Passing GCD in first argument"),
                                           TestingValues(1, 14, 15, "Passing Coprime integers")
                                           )
);

TEST_P(NwdTests, checkExpectedForGcd) {
    EXPECT_EQ(GetParam().expected, gcd(GetParam().firstArg, GetParam().secondArg));
}

TEST(NwdTests, throwExceptionWhenZerosPassedIn) {
    EXPECT_THROW(gcd(0,0), std::invalid_argument);
}
