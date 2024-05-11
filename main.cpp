/*
Olti Gjoni
CSCI-335 PROJECT 3
DUE 05/10/24
main.cpp
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

// Function prototypes for reading data and handling the sorting
std::vector<int> readData(std::ifstream& file);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    std::string header;
    if (!std::getline(inputFile, header)) {
        std::cerr << "Error reading header from file\n";
        inputFile.close();
        return 1;
    }
    std::cout << header << std::endl;

    // Read data from file
    std::vector<int> data = readData(inputFile);
    inputFile.close();

    if (data.empty()) {
        std::cerr << "No data found in the file.\n";
        return 1;
    }

    // Time each sorting function
    std::vector<int> dataCopy;
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> elapsed_time;

    // Method 1: Standard sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    stdSort(header, dataCopy);
    end = std::chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    std::cout << "StdSort time: " << elapsed_time.count() << " seconds.\n";

    // Method 2: QuickSelect first method
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    quickSelect1(header, dataCopy);
    end = std::chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    std::cout << "QuickSelect1 time: " << elapsed_time.count() << " seconds.\n";

    // Method 3: QuickSelect second method (modified)
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    quickSelect2(header, dataCopy);
    end = std::chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    std::cout << "QuickSelect2 time: " << elapsed_time.count() << " seconds.\n";

    // Method 4: Counting sort
    dataCopy = data;
    start = std::chrono::high_resolution_clock::now();
    countingSort(header, dataCopy);
    end = std::chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    std::cout << "CountingSort time: " << elapsed_time.count() << " seconds.\n";

    return 0;
}

std::vector<int> readData(std::ifstream& file) {
    std::vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}