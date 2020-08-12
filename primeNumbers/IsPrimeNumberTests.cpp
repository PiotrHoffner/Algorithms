#include "gtest/gtest.h"
#include "IsPrimeNumber.hpp"
#include <string>
#include <ostream>


struct TestingValues {
    TestingValues(unsigned argument, bool expected, std::string msg = "")
    :   argument(argument), expected(expected), msg(msg)
    {}

    unsigned argument;
    bool expected;
    std::string msg;
};

std::ostream& operator<<(std::ostream& os, const TestingValues& tv) 
{
    os << "with argument: " << tv.argument << " and expected value: " << tv.expected << "\ndetailed testcase name: " << tv.msg;
    return os;
}



struct IsPrimeNumberTests : public ::testing::TestWithParam<TestingValues> {
};

INSTANTIATE_TEST_SUITE_P(ParamT1,
                         IsPrimeNumberTests, 
                         ::testing::Values(
                                           TestingValues(0, false, "non prime numbers starts"),
                                           TestingValues(1, false),
                                           TestingValues(4, false),
                                           TestingValues(6, false),
                                           TestingValues(9, false),
                                           TestingValues(20, false),
                                           TestingValues(1214, false),
                                           TestingValues(1215, false),
                                           TestingValues(1216, false),
                                           TestingValues(10068, false),
                                           TestingValues(11577, false),
                                           TestingValues(2, true, "first prime number"),
                                           TestingValues(3, true),
                                           TestingValues(5, true),
                                           TestingValues(7, true),
                                           TestingValues(1213, true),
                                           TestingValues(1217, true),
                                           TestingValues(10067, true),
                                           TestingValues(11003, true)
));

TEST_P(IsPrimeNumberTests, checkExpectedForIsPrimeNumber) {
    EXPECT_EQ(GetParam().expected, isPrimeNumber(GetParam().argument));
}
