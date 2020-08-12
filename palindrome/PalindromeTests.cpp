#include "gtest/gtest.h"
#include "Palindrome.hpp"

TEST(PalindromeTests, returnsFalseIfEmptyStringPassedIn) {
    EXPECT_EQ(false, palindrome(""));
}

TEST(PalindromeTests, returnsTrueIfOneLetterStringPassedIn) {
    EXPECT_EQ(true, palindrome("a"));
}

TEST(PalindromeTests, returnsTrueIfTwoSameLettersPassedIn) {
    EXPECT_EQ(false, palindrome("ab"));
    EXPECT_EQ(true, palindrome("bb"));
}

TEST(PalindromeTests, returnsTrueIfThreeLetterPalindromePassedIn) {
    EXPECT_EQ(true, palindrome("did"));
}

TEST(PalindromeTests, returnsFalseIfThreeLetterNonPalindromePassedIn) {
    EXPECT_EQ(false, palindrome("pon"));
}

TEST(PalindromeTests, returnsTrueIfFourLetterPalindromePassedIn) {
    EXPECT_EQ(true, palindrome("abba"));
    EXPECT_EQ(false, palindrome("ccba"));
}
