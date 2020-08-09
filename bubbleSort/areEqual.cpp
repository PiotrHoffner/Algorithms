#include "areEqual.hpp"

bool areEqual(int* arr1, int* arr2, unsigned size) {
    bool arraysAreEqual{true};
    for(unsigned i = 0; i < size; ++i) {
        if(arr1[i] != arr2[i]) {
            arraysAreEqual = false;
            break;
        }
    }
    return arraysAreEqual;
}
