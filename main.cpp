#include <iostream>
#include <vector>
#include <algorithm>

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

    return -1; 
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
    // Test data
    vector<int> vec = {34, 7, 23, 32, 5, 62};

    // Sort the vector
    sort(vec.begin(), vec.end());

    // Display the sorted vector
    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    // Define test targets
    int target1 = 23; // Item that is in the list
    int target2 = 50; // Item that is not in the list

    // Recursive Binary Search
    cout << "\nTesting Recursive Binary Search:" << endl;
    int index = recursiveBinarySearch(vec, target1, 0, vec.size() - 1);
    if (index != -1)
        cout << target1 << " found at location " << index << endl;
    else
        cout << target1 << " was not found." << endl;

    index = recursiveBinarySearch(vec, target2, 0, vec.size() - 1);
    if (index != -1)
        cout << target2 << " found at location " << index << endl;
    else
        cout << target2 << " was not found." << endl;

    // Iterative Binary Search
    cout << "\nTesting Iterative Binary Search:" << endl;
    index = iterativeBinarySearch(vec, target1);
    if (index != -1)
        cout << target1 << " found at location " << index << endl;
    else
        cout << target1 << " was not found." << endl;

    index = iterativeBinarySearch(vec, target2);
    if (index != -1)
        cout << target2 << " found at location " << index << endl;
    else
        cout << target2 << " was not found." << endl;

    // Sequential Search
    cout << "\nTesting Sequential Search:" << endl;
    index = sequentialSearch(vec, target1);
    if (index != -1)
        cout << target1 << " found at location " << index << endl;
    else
        cout << target1 << " was not found." << endl;

    index = sequentialSearch(vec, target2);
    if (index != -1)
        cout << target2 << " found at location " << index << endl;
    else
        cout << target2 << " was not found." << endl;

    return 0;
}