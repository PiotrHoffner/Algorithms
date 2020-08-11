#include "binarySearch.hpp"

#include <stdexcept>

unsigned binarySearch(int searchedValue, int* array, unsigned size) {
    if(size == 0) {
        throw std::invalid_argument("binarySearch: searched value not found!\n");
    }
    
    unsigned middleIndex = size / 2;
    int middleValue = array[middleIndex];

    if(searchedValue == middleValue) {
        return middleIndex;
    }

    if(searchedValue < middleValue) {
        return binarySearch(searchedValue, array, middleIndex);
    }

    if(searchedValue > middleValue) {
        unsigned nextIndex = middleIndex + 1;
        return nextIndex + binarySearch(searchedValue, array + nextIndex, size - nextIndex);
    }
    throw std::logic_error("binarySearch: unknown error!");
}
