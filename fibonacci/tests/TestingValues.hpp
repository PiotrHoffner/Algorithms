#pragma once

#include <string>
#include <ostream>

struct TestingValues {
    TestingValues(unsigned expected, unsigned argument, std::string msg = "");

    unsigned expected;
    unsigned argument;
    std::string msg;
};

std::ostream& operator<< (std::ostream& os, const TestingValues& tv);
