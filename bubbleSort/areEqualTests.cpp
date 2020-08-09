#include "gtest/gtest.h"
#include "areEqual.hpp"

constexpr unsigned testArraySize = 10;

struct AreEqualTests : public ::testing::Test {
    int testArray[testArraySize] = {5,6,4,7,3,8,2,9,1,0};
    int equalArray[testArraySize] = {5,6,4,7,3,8,2,9,1,0};
    int notEqualArray[testArraySize] = {0,2,0,7,3,8,2,9,1,1};
};

TEST_F(AreEqualTests, returnsTrueIfArraysAreEqual) {
    EXPECT_TRUE(areEqual(testArray, equalArray, testArraySize));
}

TEST_F(AreEqualTests, returnsFalseIfArraysAreDifferent) {
    EXPECT_FALSE(areEqual(testArray, notEqualArray, testArraySize));
}
