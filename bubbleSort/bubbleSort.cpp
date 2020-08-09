#include "bubbleSort.hpp"

void bubbleSort(int* array, unsigned size) {
    unsigned loopRuns = size - 1;
    int tempValue{};
    for(unsigned j = 0; j < loopRuns; ++j) {
        for(unsigned i = 0; i < loopRuns; ++i) {
            if(array[i + 1] < array[i]) {
                tempValue = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tempValue;
            }
        }
    }
}
