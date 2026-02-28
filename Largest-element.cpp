#include <iostream>
using namespace std;

/*
---------------------------------------------------------
Function 1: Better Solution (Only for Positive Numbers)
---------------------------------------------------------
Logic:
Initialize largest = 0.
Compare each element with largest.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
Works correctly only when all array elements are positive.
---------------------------------------------------------
*/

int findLargestPositive(int arr[], int n) {
    int largest = 0;  // Works only if all numbers are positive

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}


/*
---------------------------------------------------------
Function 2: Optimal Solution (Handles Negative Numbers)
---------------------------------------------------------
Logic:
Initialize largest with first element.
Traverse from index 1 and compare.

Time Complexity: O(n)
Space Complexity: O(1)

This works for:
✔ Positive numbers
✔ Negative numbers
✔ Mixed values
---------------------------------------------------------
*/

int findLargestOptimal(int arr[], int n) {
    int largest = arr[0];  // Safe initialization

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}


int main() {
    int arr[] = {5, 9, 7, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Better Solution (Positive Only): "
         << findLargestPositive(arr, n) << endl;

    cout << "Optimal Solution (All Cases): "
         << findLargestOptimal(arr, n) << endl;

    return 0;
}
