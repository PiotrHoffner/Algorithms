#include "GenPrimeNumbers.hpp"

#include <algorithm>
#include <cmath>
#include <vector>
#include <stdexcept>

std::vector<int> genPrimeNumbers(std::size_t upperLimit) {
    if(upperLimit < 2) {
        throw std::invalid_argument("You cannot pass argument less then 2 for genPrimeNumbers()!");
    }
    std::vector<int> primeNumbers(upperLimit - 1);
    std::generate(primeNumbers.begin(), primeNumbers.end(), [x = 1]() mutable { return ++x; });
    
    unsigned divisorCount = static_cast<unsigned>(std::sqrt(upperLimit));
    std::vector<int> divisors(divisorCount);
    std::copy_n(primeNumbers.begin(), divisorCount, divisors.begin());
    
    int currentPrime{};
    for(const auto& currentDivisor : divisors) {
        for(auto primeIt = primeNumbers.begin(); primeIt != primeNumbers.end(); ++primeIt) {
            currentPrime = *primeIt;
            if((currentPrime != currentDivisor) && (currentPrime % currentDivisor == 0)) {
                primeNumbers.erase(primeIt);
                primeIt = primeNumbers.begin();
            }
        }
    }
    return primeNumbers;
}
