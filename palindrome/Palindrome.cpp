#include "Palindrome.hpp"

#include <algorithm>

bool palindrome(const std::string& str) {
    if(str.size() == 0) return false;
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2, str.crbegin());
}
