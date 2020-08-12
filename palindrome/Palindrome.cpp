#include "Palindrome.hpp"

bool palindrome(const std::string& argument) {
    if(argument.size() == 0) {
        return false;
    }
    if(argument.size() == 1) {
        return true;
    }
    if(argument.size() == 2 && argument[0] == argument[1]) {
        return true;
    }

    return false;
}