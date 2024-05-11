/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
QuickSelect2.cpp
*/

#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

// Partition function rearranges the elements in the vector around a pivot
// chosen from the vector. It places all elements smaller than the pivot to the left
// of the pivot and all larger elements to the right.
static int partition(std::vector<int>& data, int left, int right, int pivotIndex) {
    int pivot = data[pivotIndex]; // Pivot element is selected from the pivot index
    std::swap(data[pivotIndex], data[right]); // Move pivot to the end for easier partitioning
    int storeIndex = left; // This will be the index of the smaller element
    for (int i = left; i < right; i++) {
        if (data[i] < pivot) {
            std::swap(data[i], data[storeIndex]); // Swap if current element is less than pivot
            storeIndex++; // Move to next position
        }
    }
    std::swap(data[storeIndex], data[right]); // Swap back the pivot element to its correct position
    return storeIndex; // Return the index of the pivot element after partitioning
}

// Recursive function for QuickSelect that handles multiple indices at once.
// It partitions the data and recursively selects on subarrays just as needed to find the desired indices.
void quickSelectRecursive(std::vector<int>& data, int left, int right, std::vector<int>& indices) {
    if (left >= right) return; // Base case: no need to sort/partition if subarray has 0 or 1 element

    int pivotIndex = partition(data, left, right, (left + right) / 2); // Partition the data
    std::vector<int> leftIndices, rightIndices; // Vectors to hold indices that fall to the left or right of the pivot

    for (int index : indices) {
        if (index < pivotIndex) {
            leftIndices.push_back(index); // Collect indices that are still to be found in the left subarray
        } else if (index > pivotIndex) {
            rightIndices.push_back(index); // Collect indices for the right subarray
        }
    }

    quickSelectRecursive(data, left, pivotIndex - 1, leftIndices); // Recurse on the left subarray
    quickSelectRecursive(data, pivotIndex + 1, right, rightIndices); // Recurse on the right subarray
}

// The main function to execute QuickSelect2, designed to find specific percentiles efficiently.
void quickSelect2(const std::string& header, std::vector<int> data) {
    std::cout << header << std::endl; // Display the header

    const size_t n = data.size(); // Total number of elements
    // Indices for quartiles
    std::vector<int> indices = {static_cast<int>(n / 4), static_cast<int>(n / 2), static_cast<int>(3 * n / 4)};
    quickSelectRecursive(data, 0, n - 1, indices); // Execute the recursive QuickSelect

    // Output the results of the quartiles
    std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + n / 4) << std::endl;
    std::cout << "P25: " << data[n / 4] << std::endl;
    std::cout << "P50: " << data[n / 2] << std::endl;
    std::cout << "P75: " << data[3 * n / 4] << std::endl;
    std::cout << "Max: " << *std::max_element(data.begin() + 3 * n / 4, data.end()) << std::endl;
}