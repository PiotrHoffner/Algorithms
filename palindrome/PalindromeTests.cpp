#include "gtest/gtest.h"
#include "Palindrome.hpp"

TEST(PalindromeTests, returnsFalseIfEmptyStringPassedIn) {
    EXPECT_EQ(false, palindrome(""));
}

TEST(PalindromeTests, returnsTrueIfOneLetterStringPassedIn) {
    EXPECT_EQ(true, palindrome("a"));
}
