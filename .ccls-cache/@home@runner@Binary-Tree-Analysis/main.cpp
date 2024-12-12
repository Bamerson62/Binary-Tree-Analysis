#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

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
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Fill the vector with random values in the range [1, 100]
    vector<int> vec(10);
    for (int& num : vec) {
        num = rand() % 100 + 1;
    }

    // Sort the vector
    sort(vec.begin(), vec.end());

    // Display the sorted vector
    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Generate a random target value in the range [1, 100]
    int target = rand() % 100 + 1;

    // Recursive Binary Search
    cout << "\nTesting Recursive Binary Search:" << endl;
    int index = recursiveBinarySearch(vec, target, 0, vec.size() - 1);
    if (index != -1)
        cout << target << " found at location " << index << endl;
    else
        cout << target << " was not found." << endl;

    // Iterative Binary Search
    cout << "\nTesting Iterative Binary Search:" << endl;
    index = iterativeBinarySearch(vec, target);
    if (index != -1)
        cout << target << " found at location " << index << endl;
    else
        cout << target << " was not found." << endl;

    // Sequential Search
    cout << "\nTesting Sequential Search:" << endl;
    index = sequentialSearch(vec, target);
    if (index != -1)
        cout << target << " found at location " << index << endl;
    else
        cout << target << " was not found." << endl;

    return 0;
}

