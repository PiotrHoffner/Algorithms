#include "Fibonacci.hpp"
#include "TestingValues.hpp"

#include "gtest/gtest.h"

struct calculateFibTests : public ::testing::TestWithParam<TestingValues> {};

INSTANTIATE_TEST_SUITE_P(Inst1,
                         calculateFibTests,
                         ::testing::Values(TestingValues(0, 0),
                                           TestingValues(1, 1),
                                           TestingValues(1, 2),
                                           TestingValues(2, 3),
                                           TestingValues(3, 4),
                                           TestingValues(5, 5),
                                           TestingValues(8, 6),
                                           TestingValues(13, 7),
                                           TestingValues(21, 8),
                                           TestingValues(34, 9),
                                           TestingValues(55, 10),
                                           TestingValues(6765, 20),
                                           TestingValues(832040, 30)
));

TEST_P(calculateFibTests, checkExpectedForLcm) {
    EXPECT_EQ(GetParam().expected, calculateFib(GetParam().argument));
}
