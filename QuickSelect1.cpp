/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
QuickSelect1.cpp
*/

// QuickSelect1.cpp
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& data, int left, int right, int pivotIndex) {
    int pivot = data[pivotIndex];
    std::swap(data[pivotIndex], data[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (data[i] < pivot) {
            std::swap(data[i], data[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(data[storeIndex], data[right]);
    return storeIndex;
}

int quickSelect(std::vector<int>& data, int left, int right, int k) {
    if (left == right) return data[left];
    if (right - left < 20) {
        insertionSort(data, left, right);
        return data[k];
    }
    int pivotIndex = (left + right) / 2;
    pivotIndex = partition(data, left, right, pivotIndex);
    if (k == pivotIndex) {
        return data[k];
    } else if (k < pivotIndex) {
        return quickSelect(data, left, pivotIndex - 1, k);
    } else {
        return quickSelect(data, pivotIndex + 1, right, k);
    }
}

void quickSelect1(const std::string& header, std::vector<int> data) {
    std::cout << header << std::endl;
    const size_t n = data.size();
    int P50 = quickSelect(data, 0, n - 1, n / 2);
    int P25 = quickSelect(data, 0, n / 2, n / 4);
    int P75 = quickSelect(data, n / 2, n - 1, 3 * n / 4);
    
    std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + n / 4) << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << P50 << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin() + 3 * n / 4, data.end()) << std::endl;
}