#include "Nwd.hpp"
#include "Nww.hpp"

#include <stdexcept>

int lcm(int first, int second) {
    if(first == 0 && second ==0) {
        throw std::invalid_argument("You can't pass two zeros for LCM calculation!");
    }
    if(first < 0 || second < 0) {
        throw std::invalid_argument("You can't pass negative numbers for LCM calculation!");
    }
    return first * second / gcd(first, second);
}
