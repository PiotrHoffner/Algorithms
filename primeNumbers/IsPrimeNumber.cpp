#include "IsPrimeNumber.hpp"

#include <stdexcept>

bool isPrimeNumber(const int argument) {
    if(argument == 0 || argument == 1)
        return false;
    if(argument == 2 || argument ==3)
        return true;
        
    throw std::logic_error("Err!\n");
}