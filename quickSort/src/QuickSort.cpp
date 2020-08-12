#include "QuickSort.hpp"

#include <algorithm>

void quickSort(int* array, unsigned left, unsigned right) {
    if(right <= left) { return; }

    int middleValue = array[(left + right) / 2];
    unsigned i = left - 1;
    unsigned j = right + 1;

    while(true){
        while(array[++i] < middleValue);
        while(array[--j] > middleValue);

        if(i <= j) {
            std::swap(array[i], array[j]);
        }
        else {
            break;
        }
    }
    if(left < j)    quickSort(array, left, j);
    if(right > i)   quickSort(array, i, right);
}
