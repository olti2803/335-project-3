/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
StdSort.cpp
*/

// StdSort.cpp
#include "StdSort.hpp"
#include <algorithm>
#include <iostream>

void stdSort(const std::string& header, std::vector<int> data) {
    // Print the header
    std::cout << header << std::endl;

    // Sort the data
    std::sort(data.begin(), data.end());

    // Calculate indices for the quartiles
    size_t n = data.size();
    size_t P25 = n / 4;        // 25th percentile
    size_t P50 = n / 2;        // 50th percentile (median)
    size_t P75 = 3 * n / 4;    // 75th percentile

    // Output the five-number summary
    std::cout << "Min: " << data.front() << std::endl;
    std::cout << "P25: " << data[P25] << std::endl;
    std::cout << "P50: " << data[P50] << std::endl;
    std::cout << "P75: " << data[P75] << std::endl;
    std::cout << "Max: " << data.back() << std::endl;
}


