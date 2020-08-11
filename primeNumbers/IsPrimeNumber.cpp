#include "IsPrimeNumber.hpp"

#include <stdexcept>

bool isPrimeNumber(const unsigned argument) {
    if(argument == 0 || argument == 1) {
        return false;
    }
    bool isArgumentPrime = true;
    for(unsigned divisor = 2; divisor < argument; ++divisor) {
        if(argument % divisor == 0) {
            isArgumentPrime = false;
        }
    }
    return isArgumentPrime;
}