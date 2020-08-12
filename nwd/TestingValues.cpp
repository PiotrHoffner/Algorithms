#include "TestingValues.hpp"

TestingValues::TestingValues(int expected, int firstArg, int secondArg, std::string msg)
    :   expected(expected), firstArg(firstArg), secondArg(secondArg), msg(msg)
    {}

std::ostream& operator<< (std::ostream& os, const TestingValues& tv) {
    os << "\nExpected value: " << tv.msg << ", first arg: " << tv.firstArg << ", second arg: " << tv.secondArg;
    return os;
}
