#include "Nwd.hpp"

#include <algorithm>
#include <cmath>
#include <stdexcept>

int gcd(int first, int second) {
    if(first == 0 && second == 0) {
        throw std::invalid_argument("You can't pass two zeros for GCD calculation!");
    }

    first = std::abs(first);
    second = std::abs(second);

    if(first > second) {
        std::swap(first, second);
    }

    while(second != 0) {
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}
