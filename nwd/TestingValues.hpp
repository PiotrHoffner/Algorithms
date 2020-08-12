#pragma once

#include <string>
#include <ostream>

struct TestingValues {
    TestingValues(int expected, int firstArg, int secondArg, std::string msg = "");

    int expected;
    int firstArg;
    int secondArg;
    std::string msg;
};

std::ostream& operator<< (std::ostream& os, const TestingValues& tv);
