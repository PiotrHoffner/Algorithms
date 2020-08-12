#include "Palindrome.hpp"

#include <algorithm>
#include <cctype>

bool palindrome(const std::string& str) {
    if(str.size() == 0) return false;
    std::string modifiedString;
    std::copy_if(str.cbegin(), str.cend(), std::back_inserter(modifiedString), ::isalpha);
    std::transform(modifiedString.cbegin(), modifiedString.cend(), modifiedString.begin(), ::tolower);
    return std::equal(modifiedString.cbegin(),
                      modifiedString.cbegin() + modifiedString.size() / 2,
                      modifiedString.crbegin());
}
