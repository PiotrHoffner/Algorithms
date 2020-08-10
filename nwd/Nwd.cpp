#include "Nwd.hpp"

#include <stdexcept>

int gcd(int first, int second) {
    if(first == 0 && second == 0) {
        throw std::invalid_argument("You can't pass two zeros for GCD calculation!");
    }
    if(first < 0) {
        first *= -1;
    }
    if(second < 0) {
        second *= -1;
    }
    int temp{0};
    if(first > second) {
        temp = second;
        second = first;
        first = temp;
    }
    while(second != 0) {
        temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}
