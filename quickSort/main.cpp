#include "QuickSort.hpp"

#include <iostream>

int main() {
    int testArr1[10] = {5, 6, 4, 7, 3, 8, 2, 9, 1, 0};
    int expected1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Unsorted test array: ";
    for(const auto& el : testArr1) { std::cout << el << ' '; }
    std::cout << '\n';

    quickSort(testArr1, 0, 9);
    std::cout << "Test array after quickSort: ";
    for(const auto& el : testArr1) { std::cout << el << ' '; }
    std::cout << '\n';

    std::cout << "Expected array: ";
    for(const auto& el : expected1) { std::cout << el << ' '; }
    std::cout << '\n';

    return 0;
}
