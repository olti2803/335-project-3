/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
CountingSort.cpp
*/

// CountingSort.cpp
#include "CountingSort.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void countingSort(const std::string& header, std::vector<int> data) {
    std::cout << header << std::endl;

    // Using an unordered_map as a hash table for counting frequencies
    std::unordered_map<int, int> counts;
    for (int num : data) {
        counts[num]++;
    }

    // Prepare for sorting the unique keys
    std::vector<int> sortedKeys;
    for (const auto& pair : counts) {
        sortedKeys.push_back(pair.first);
    }
    std::sort(sortedKeys.begin(), sortedKeys.end());

    // Output results
    std::vector<int> sortedData;
    for (int key : sortedKeys) {
        for (int i = 0; i < counts[key]; i++) {
            sortedData.push_back(key);
        }
    }

    // Assuming the data size is divisible by 100 for easy percentile calculation
    int n = sortedData.size();
    std::cout << "Min: " << sortedData.front() << std::endl;
    std::cout << "P25: " << sortedData[n / 4] << std::endl;
    std::cout << "P50: " << sortedData[n / 2] << std::endl;
    std::cout << "P75: " << sortedData[3 * n / 4] << std::endl;
    std::cout << "Max: " << sortedData.back() << std::endl;

    // Also report the number of unique values
    std::cout << "Unique: " << sortedKeys.size() << std::endl;
}
