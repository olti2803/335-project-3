/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
QuickSelect1.cpp
*/

#include "QuickSelect1.hpp"
#include <iostream>   
#include <vector>     
#include <algorithm>  
#include <iterator>   
#include <functional> 

// Helper function to perform insertion sort within the specified range [left, right]
void insertionSort(std::vector<int>& data, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= left && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

// Partition the vector around a pivot element and return its final position
int partition(std::vector<int>& data, int left, int right, int pivotIndex) {
    std::swap(data[pivotIndex], data[right]); // Move pivot to end for easier manipulation
    int pivotValue = data[right];
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (data[i] < pivotValue) {
            std::swap(data[i], data[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(data[storeIndex], data[right]); // Move pivot to its final place
    return storeIndex;
}

// Quickselect algorithm to find the k-th smallest element in the vector
int quickSelect(std::vector<int>& data, int left, int right, int k) {
    if (left == right) { // If the list contains only one element,
        return data[left]; // return that element
    }

    int pivotIndex = (left + right) / 2; // Use middle element as pivot
    pivotIndex = partition(data, left, right, pivotIndex);

    // Recursively call quickSelect to find the k-th smallest element
    if (k == pivotIndex) {
        return data[k];
    } else if (k < pivotIndex) {
        return quickSelect(data, left, pivotIndex - 1, k);
    } else {
        return quickSelect(data, pivotIndex + 1, right, k);
    }
}

// Main function to execute the quickselect sorting and find the five-number summary
void quickSelect1(const std::string& header, std::vector<int> data) {
    std::cout << header << std::endl; // Print the header

    if (data.size() <= 20) {
        insertionSort(data, 0, data.size() - 1); // Use insertion sort for small arrays
    } else {
        const size_t n = data.size();
        int medianIndex = n / 2;
        int P50 = quickSelect(data, 0, n - 1, medianIndex); // Find the median
        int P25 = quickSelect(data, 0, medianIndex, medianIndex / 2); // Find the 25th percentile
        int P75 = quickSelect(data, medianIndex, n - 1, medianIndex + (n - medianIndex) / 2); // Find the 75th percentile

        std::cout << "Min: " << *std::min_element(data.begin(), data.begin() + medianIndex / 2) << std::endl;
        std::cout << "P25: " << P25 << std::endl;
        std::cout << "P50: " << P50 << std::endl;
        std::cout << "P75: " << P75 << std::endl;
        std::cout << "Max: " << *std::max_element(data.begin() + medianIndex + (n - medianIndex) / 2, data.end()) << std::endl;
    }
}