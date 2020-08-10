#include "quickSort.hpp"
#include <iostream>
#include <algorithm>

void quickSort(int* array, unsigned left, unsigned right) {
    if(left >= right) return;
    unsigned i = left - 1;
    unsigned j = right + 1;
    int pivot = array[(left + right) / 2];

    while(true) {
        while(array[++i] < pivot);
        while(array[--j] > pivot);
        if(i <= j) { std::swap(array[i], array[j]); }
        else { break; }
    }

    if(left < j) { quickSort(array, left, j); }
    if(right > i) { quickSort(array, i, right); }
}
