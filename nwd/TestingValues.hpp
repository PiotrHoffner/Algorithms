#pragma once

struct TestingValues {
    TestingValues(int expected, int firstArg, int secondArg)
    :   expected(expected), firstArg(firstArg), secondArg(secondArg)
    {}

    int expected;
    int firstArg;
    int secondArg;
};
