#include "IsPrimeNumber.hpp"

#include <stdexcept>

bool isPrimeNumber(const unsigned argument) {
    if(argument == 0 || argument == 1) {
        return false;
    }
    for(unsigned divisor = 2; divisor < argument; ++divisor) {
        if(argument % divisor == 0) {
            return false;
        }
    }
    return true;
}