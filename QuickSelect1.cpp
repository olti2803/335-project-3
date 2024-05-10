/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
QuickSelect1.cpp
*/

#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

// Partition function rearranges the elements in the vector around a pivot
// chosen from the vector. It places all elements smaller than the pivot to the left
// of the pivot and all larger elements to the right.
int partition(std::vector<int>& data, int left, int right, int pivotIndex) {
    int pivot = data[pivotIndex];
    std::swap(data[pivotIndex], data[right]);  // Move pivot to the end for simplicity
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (data[i] < pivot) {
            std::swap(data[i], data[storeIndex]);  // Move smaller elements to the left
            storeIndex++;
        }
    }
    std::swap(data[storeIndex], data[right]);  // Move pivot to its correct place
    return storeIndex;
}

// QuickSelect function implements the Quickselect algorithm to find the k-th smallest
// element in the vector within the bounds specified by left and right.
int quickSelect(std::vector<int>& data, int left, int right, int k) {
    if (left == right) return data[left];  // If there is only one element, return it
    if (right - left < 20) {
        insertionSort(data, left, right);  // Use insertion sort for small arrays for efficiency
        return data[k];
    }
    int pivotIndex = partition(data, left, right, (left + right) / 2);  // Partition the array
    if (k == pivotIndex) {
        return data[k];  // Found the k-th element
    } else if (k < pivotIndex) {
        return quickSelect(data, left, pivotIndex - 1, k);  // Recur on the left part
    } else {
        return quickSelect(data, pivotIndex + 1, right, k);  // Recur on the right part
    }
}

// quickSelect1 function to display the five-number summary of the dataset.
void quickSelect1(const std::string& header, std::vector<int> data) {
    std::cout << header << std::endl;  // Print the header
    const size_t n = data.size();
    int P50 = quickSelect(data, 0, n - 1, n / 2);  // Median
    int P25 = quickSelect(data, 0, n / 2, n / 4);  // First quartile
    int P75 = quickSelect(data, n / 2, n - 1, 3 * n / 4);  // Third quartile
    
    // Display the results including the min and max
    std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + n / 4) << std::endl;
    std::cout << "P25: " << P25 << std::endl;
    std::cout << "P50: " << P50 << std::endl;
    std::cout << "P75: " << P75 << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin() + 3 * n / 4, data.end()) << std::endl;
}