#include "gtest/gtest.h"
#include "Palindrome.hpp"

TEST(PalindromeTests, returnsFalseIfEmptyStringPassedIn) {
    EXPECT_EQ(false, palindrome(""));
}
