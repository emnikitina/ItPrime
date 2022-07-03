#include <iostream>
#include "XNumber.hpp"

void countDiffSum(unsigned long long* sumSet, unsigned nbrSystem, unsigned capacity) {
    XNbr x(nbrSystem, capacity / 2);
    XNbr max("max", nbrSystem, capacity / 2);
    unsigned long maxSum = ((nbrSystem - 1) * (capacity / 2));

    for (size_t i = 0; i <= maxSum; i++)
        sumSet[i] = 0;    
    for (; x < max; ++x)
        sumSet[x.digitSum()]++;
    sumSet[x.digitSum()]++;
}

unsigned long long countBeautifulNumbers(unsigned nbrSystem, unsigned capacity) {
    unsigned long long count = 0;
    unsigned long long* sumSet;
    
    sumSet = new unsigned long long[(nbrSystem - 1) * (capacity / 2) + 1];
    countDiffSum(sumSet, nbrSystem, capacity);
    for (size_t i = 0; i <= ((nbrSystem - 1) * (capacity / 2)); i++)
        count += (sumSet[i] * sumSet[i]);
    delete[] sumSet;
    return count * nbrSystem;
}

int main() {
    std::cout << countBeautifulNumbers(13, 13) << std::endl;
    return 0;
}