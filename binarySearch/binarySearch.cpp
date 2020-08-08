#include "binarySearch.hpp"

#include <stdexcept>

unsigned binarySearch(int searchedValue, int* array, unsigned size, unsigned left, unsigned right) {
    if(right > size) {
        throw std::invalid_argument("binarySearch: value of right is higher than array size!\n");
    }
    if(left > right) {
        throw std::invalid_argument("binarySearch: left is higher than right!\n");
    }
    unsigned middle = (left + right) / 2;
    if(array[middle] == searchedValue) {
        return middle;
    }
    if(middle == left || middle == right) {
        throw std::invalid_argument("binarySearch: searched argument not found!\n");
    }
    if(array[middle] > searchedValue) {
        return binarySearch(searchedValue, array, size,  left, middle - 1);
    }
    if(array[middle] < searchedValue) {
        return binarySearch(searchedValue, array, size, middle + 1, right);
    }
    throw std::logic_error("binarySearch: unknown logic error!\n");
}
