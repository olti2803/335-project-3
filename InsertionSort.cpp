/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
InsertionSort.cpp
*/

// InsertionSort.cpp
#include "InsertionSort.hpp"

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
