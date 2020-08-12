#include "Palindrome.hpp"

bool palindrome(const std::string& argument) {
    if(argument.size() == 1) {
        return true;
    }
    return false;
}