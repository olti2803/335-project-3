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
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
//#include "CountingSort.hpp"

// Function prototypes for reading data and handling the sorting
std::vector<int> readData(std::ifstream& file);

int main(int argc, char* argv[]) {
    // Ensure the program is run with a file name argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    // Open the file
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << "\n";
        return 1;
    }

    // Read the header line
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

    // Verify data has been read
    if (data.empty()) {
        std::cerr << "No data found in the file.\n";
        return 1;
    }

    // Call each sorting function and display results
    std::vector<int> dataCopy;

    // Method 1: Standard sort
    dataCopy = data; // Make a copy of the data for sorting
    stdSort(header, dataCopy);

    // Method 2: QuickSelect first method
    dataCopy = data;
    quickSelect1(header, dataCopy);

    // Method 3: QuickSelect second method (modified)
    dataCopy = data;
    quickSelect2(header, dataCopy);

    // Method 4: Counting sort
    dataCopy = data;
   // countingSort(header, dataCopy);

    return 0;
}

// Function to read integer data from file into a vector
std::vector<int> readData(std::ifstream& file) {
    std::vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}
