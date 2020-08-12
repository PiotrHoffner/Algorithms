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
    if(str.size() == 3 && str[0] == str[str.size()-1]) {
        return true;
    }
    
    return false;
}
