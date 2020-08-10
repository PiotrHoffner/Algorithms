#include "gtest/gtest.h"
#include "Nww.hpp"
#include "TestingValues.hpp"

struct NwwTests : public ::testing::TestWithParam<TestingValues> {};

INSTANTIATE_TEST_SUITE_P(ParamT1,
                         NwwTests,
                         ::testing::Values(TestingValues{3, 1, 3},
                                           TestingValues{3, 3, 1},
                                           TestingValues{15, 3, 5},
                                           TestingValues{15, 5, 3},
                                           TestingValues{12, 6, 4},
                                           TestingValues{12, 4, 6},
                                           TestingValues{0, 0, 7},
                                           TestingValues{0, 7, 0}

));

TEST_P(NwwTests, checkExpectedForLcm) {
    EXPECT_EQ(GetParam().expected, lcm(GetParam().firstArg, GetParam().secondArg));
}

TEST(NwwTests, throwExceptionWhenAllArgumentsAreEqualZero) {
    EXPECT_THROW(lcm(0,0), std::invalid_argument);
}
TEST(NwwTests, throwExceptionWhenFirstArgumentIsNegative) {
    EXPECT_THROW(lcm(-7,6), std::invalid_argument);
}
TEST(NwwTests, throwExceptionWhenSecondArgumentIsNegative) {
    EXPECT_THROW(lcm(6,-7), std::invalid_argument);
}
