#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

// Function prototypes
int recursiveBinarySearch(const vector<int>& vec, int target, int low, int high);
int iterativeBinarySearch(const vector<int>& vec, int target);
int sequentialSearch(const vector<int>& vec, int target);

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& vec, int target, int low, int high) {
    if (low > high) return -1; // Base case: not found

    int mid = low + (high - low) / 2;

    if (vec[mid] == target) return mid; // Target found
    else if (vec[mid] > target)
        return recursiveBinarySearch(vec, target, low, mid - 1); // Search in the left half
    else
        return recursiveBinarySearch(vec, target, mid + 1, high); // Search in the right half
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& vec, int target) {
    int low = 0, high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target)
            return mid; // Target found
        else if (vec[mid] > target)
            high = mid - 1; // Search in the left half
        else
            low = mid + 1; // Search in the right half
    }

    return -1; // Target not found
}

// Sequential Search
int sequentialSearch(const vector<int>& vec, int target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target)
            return i; // Target found
    }

    return -1; // Target not found
}

// Main function
int main() {
    srand(time(0)); // Seed the random number generator

    vector<int> testSizes = {5000, 50000, 100000, 150000, 200000};

    for (int N : testSizes) {
        double SumRBS = 0.0; // Accumulator for Recursive Binary Search
        double SumIBS = 0.0; // Accumulator for Iterative Binary Search
        double SumSeqS = 0.0; // Accumulator for Sequential Search

        // Loop to run the program 10 times
        for (int run = 0; run < 10; ++run) {
            // Generate a vector with N random numbers in the range [1, 100]
            vector<int> vec(N);
            for (int& num : vec) {
                num = rand() % 100 + 1;
            }

            // Sort the vector
            sort(vec.begin(), vec.end());

            // Generate a random target value in the range [1, 100]
            int target = rand() % 100 + 1;

            // Measure time for Recursive Binary Search
            auto start = high_resolution_clock::now();
            recursiveBinarySearch(vec, target, 0, vec.size() - 1);
            auto end = high_resolution_clock::now();
            SumRBS += duration_cast<microseconds>(end - start).count();

            // Measure time for Iterative Binary Search
            start = high_resolution_clock::now();
            iterativeBinarySearch(vec, target);
            end = high_resolution_clock::now();
            SumIBS += duration_cast<microseconds>(end - start).count();

            // Measure time for Sequential Search
            start = high_resolution_clock::now();
            sequentialSearch(vec, target);
            end = high_resolution_clock::now();
            SumSeqS += duration_cast<microseconds>(end - start).count();
        }

        // Output average running times for this test size
        cout << "For N = " << N << ":\n";
        cout << "  Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10.0 << endl;
        cout << "  Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10.0 << endl;
        cout << "  Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10.0 << endl;
        cout << endl;
    }

    return 0;
}
