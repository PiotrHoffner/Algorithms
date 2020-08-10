#include "GenPrimeNumbers.hpp"

#include <iostream>
#include <vector>

int main() {
    std::vector<int> primeNumbers{};
    std::cout << "Generate prime numbers with upper limit 100:\n";
    primeNumbers = genPrimeNumbers(100);
    for(const auto& num : primeNumbers) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    
    return 0;
}
