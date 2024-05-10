/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
QuickSelect2.cpp
*/

// QuickSelect2.cpp
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& data, int left, int right, int pivotIndex) {
    int pivot = data[pivotIndex];
    std::swap(data[pivotIndex], data[right]); // Move pivot to end
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (data[i] < pivot) {
            std::swap(data[i], data[storeIndex]); // Corrected to use elements, not indices
            storeIndex++;
        }
    }
    std::swap(data[storeIndex], data[right]); // Move pivot to its final place
    return storeIndex;
}


void quickSelectRecursive(std::vector<int>& data, int left, int right, std::vector<int>& indices) {
    if (left >= right) return;

    int pivotIndex = partition(data, left, right, (left + right) / 2);
    std::vector<int> leftIndices, rightIndices;

    for (int index : indices) {
        if (index < pivotIndex) {
            leftIndices.push_back(index);
        } else if (index > pivotIndex) {
            rightIndices.push_back(index);
        }
    }

    quickSelectRecursive(data, left, pivotIndex - 1, leftIndices);
    quickSelectRecursive(data, pivotIndex + 1, right, rightIndices);
}

void quickSelect2(const std::string& header, std::vector<int> data) {
    std::cout << header << std::endl;

    const size_t n = data.size();
    std::vector<int> indices = {static_cast<int>(n / 4), static_cast<int>(n / 2), static_cast<int>(3 * n / 4)};
    quickSelectRecursive(data, 0, n - 1, indices);

    std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + n / 4) << std::endl;
    std::cout << "P25: " << data[n / 4] << std::endl;
    std::cout << "P50: " << data[n / 2] << std::endl;
    std::cout << "P75: " << data[3 * n / 4] << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin() + 3 * n / 4, data.end()) << std::endl;
}
