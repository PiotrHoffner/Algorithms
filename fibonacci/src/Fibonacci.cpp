#include "Fibonacci.hpp"

unsigned calculateFib(unsigned argument) {
    if(argument <= 1) {
        return argument;
    }

    unsigned beforePrevElement = 0;
    unsigned prevElement = 1;
    unsigned currentElement = 1;
    for(unsigned i = 1 ; i < argument; ++i) {
        currentElement = beforePrevElement + prevElement;
        beforePrevElement = prevElement;
        prevElement = currentElement;
    }
    return currentElement;
}
