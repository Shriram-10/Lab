#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// Function prototypes
void generateData(std::vector<int>& data, int n);
int linearSearch(const std::vector<int>& data, int key, int& comparisons);
int binarySearch(const std::vector<int>& data, int key, int& comparisons);

int main() {
    int n = 1000; // Example size
    int key;
    std::vector<int> data;
    generateData(data, n);

    // Example for Linear Search
    int comparisons = 0;
    auto start = std::chrono::high_resolution_clock::now();
    int index = linearSearch(data, key, comparisons);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "Key " << (index != -1 ? "found" : "not found") 
              << " after " << comparisons << " comparisons.\n";
    std::cout << "Time taken: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " microseconds.\n";

    return 0;
}

void generateData(std::vector<int>& data, int n) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    data.clear();
    for (int i = 0; i < n; ++i) {
        data.push_back(dis(gen));
    }
}

int linearSearch(const std::vector<int>& data, int key, int& comparisons) {
    comparisons = 0;
    for (int i = 0; i < data.size(); ++i) {
        comparisons++;
        if (data[i] == key) return i;
    }
    return -1;
}

int binarySearch(const std::vector<int>& data, int key, int& comparisons) {
    comparisons = 0;
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (data[mid] == key) return mid;
        if (data[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}