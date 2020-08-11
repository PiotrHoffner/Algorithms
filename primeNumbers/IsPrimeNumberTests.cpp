#include "gtest/gtest.h"
#include "IsPrimeNumber.hpp"

struct TestingValues {
    TestingValues(unsigned argument, bool expected)
    :   argument(argument), expected(expected)
    {}

    unsigned argument;
    bool expected;
};

struct IsPrimeNumberTests : public ::testing::TestWithParam<TestingValues> {
};

INSTANTIATE_TEST_SUITE_P(ParamT1,
                         IsPrimeNumberTests,
                         ::testing::Values(
                                           TestingValues{0, false},
                                           TestingValues{1, false},
                                           TestingValues{2, true},
                                           TestingValues{3, true},
                                           TestingValues{4, false},
                                           TestingValues{5, true},
                                           TestingValues{6, false},
                                           TestingValues{7, true},
                                           TestingValues{20, false},
                                           TestingValues{23, true}
));

TEST_P(IsPrimeNumberTests, checkExpectedForIsPrimeNumber) {
    EXPECT_EQ(GetParam().expected, isPrimeNumber(GetParam().argument));
}
