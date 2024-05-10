/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
InsertionSort.cpp
*/

// InsertionSort.cpp
#include "InsertionSort.hpp"

void insertionSort(std::vector<int>& data, int left, int right) {
    // Start from the second element in the subarray.
    for (int i = left + 1; i <= right; i++) {
        // The 'key' is the value to be inserted into the sorted portion of the array.
        int key = data[i];
        // Start comparing with the element just before the current element.
        int j = i - 1;

        // Move elements of data[0..i-1], that are greater than key,
        // to one position ahead of their current position.
        // This loop will shift all elements that are greater than 'key' to the right by one position.
        while (j >= left && data[j] > key) {
            data[j + 1] = data[j];
            j--; // Move back through the array.
        }
        // Insert the 'key' in its correct location in the sorted portion.
        data[j + 1] = key;
    }
}