#include "IsPrimeNumber.hpp"

#include <cmath>
#include <stdexcept>

bool isPrimeNumber(const unsigned argument) {
    if(argument == 0 || argument == 1) {
        return false;
    }
    for(unsigned divisor = 2; divisor <= std::sqrt(argument); ++divisor) {
        if(argument % divisor == 0) {
            return false;
        }
    }
    return true;
}