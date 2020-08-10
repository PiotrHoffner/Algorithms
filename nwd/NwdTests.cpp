#include "gtest/gtest.h"
#include "Nwd.hpp"

TEST(NwdTests, returns4When12And8PassedIn) {
    EXPECT_EQ(4, gcd(12, 8));
}
TEST(NwdTests, returns4When8And12PassedIn) {
    EXPECT_EQ(4, gcd(8, 12));
}
TEST(NwdTests, returns4WhenNegative8And12PassedIn) {
    EXPECT_EQ(4, gcd(-8, 12));
}
TEST(NwdTests, returns4When8AndNegative12PassedIn) {
    EXPECT_EQ(4, gcd(8, -12));
}
TEST(NwdTests, returns4WhenNegative8AndNegative12PassedIn) {
    EXPECT_EQ(4, gcd(-8, -12));
}

TEST(NwdTests, returns3When6And9PassedIn) {
    EXPECT_EQ(3, gcd(6, 9));
}
TEST(NwdTests, returns3When9And6PassedIn) {
    EXPECT_EQ(3, gcd(9, 6));
}

TEST(NwdTests, returns9When9And0PassedIn) {
    EXPECT_EQ(9, gcd(9, 0));
}
TEST(NwdTests, returns9When0And9PassedIn) {
    EXPECT_EQ(9, gcd(0, 9));
}
TEST(NwdTests, returns9WhenNegative9And0PassedIn) {
    EXPECT_EQ(9, gcd(-9, 0));
}
TEST(NwdTests, returns9When0AndNegative9PassedIn) {
    EXPECT_EQ(9, gcd(0, -9));
}

TEST(NwdTests, throwExceptionWhenZerosPassedIn) {
    EXPECT_THROW(gcd(0,0), std::invalid_argument);
}
