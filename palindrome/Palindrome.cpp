#include "Palindrome.hpp"

bool palindrome(const std::string& str) {
    if(str.size() == 0) {
        return false;
    }
    if(str.size() == 1) {
        return true;
    }
    if(str.size() == 2 && str[0] == str[1]) {
        return true;
    }
    bool firstAndLastCharMatches = str[0] == str[str.size()-1];
    if(str.size() == 3 && firstAndLastCharMatches) {
        return true;
    }
    if(str.size() == 4 && firstAndLastCharMatches && str[1] == str[str.size()-2]) {
        return true;
    }
    return false;
}
