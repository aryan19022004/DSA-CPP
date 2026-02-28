#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/*
===========================================================
1️⃣ BRUTE FORCE APPROACH (Using Sorting)
===========================================================

Logic:
- Sort the array.
- Largest element = arr[n-1]
- Second largest element = arr[n-2]

Time Complexity: O(n log n)
Space Complexity: O(1)  (Ignoring internal stack space)

Note:
Sorting is unnecessary if we only need 2nd largest.
This is not optimal.
===========================================================
*/

int secondLargestBySorting(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n - 2];
}


/*
===========================================================
2️⃣ ONE PASS APPROACH (Your Logic - Works for Positive Numbers)
===========================================================

Logic:
- Maintain two variables: largest and secondLargest
- Update them while traversing

Time Complexity: O(n)
Space Complexity: O(1)

Limitation:
❌ Fails for negative numbers
❌ Fails when all elements are same
===========================================================
*/

int secondLargestPositiveOnly(int arr[], int n) {

    int largest = 0;
    int secondLargest = -1;

    for(int i = 0; i < n; i++) {

        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}


/*
===========================================================
3️⃣ OPTIMAL APPROACH (Fully Safe - Recommended)
===========================================================

Logic:
- Initialize largest and secondLargest with INT_MIN
- Traverse once
- Carefully update both values
- Ignore duplicates

Time Complexity: O(n)
Space Complexity: O(1)

Works For:
✔ Positive numbers
✔ Negative numbers
✔ Mixed values
✔ Duplicate largest values
===========================================================
*/

int secondLargestOptimal(int arr[], int n) {

    if(n < 2) return -1;

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++) {

        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if(secondLargest == INT_MIN)
        return -1;  // Means no second largest exists

    return secondLargest;
}


int main() {

    int arr[] = {5, 9, 7, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // NOTE: Sorting modifies array, so copy if needed in real use.

    cout << "Second Largest (Sorting): "
         << secondLargestBySorting(arr, n) << endl;

    cout << "Second Largest (Positive Only Logic): "
         << secondLargestPositiveOnly(arr, n) << endl;

    cout << "Second Largest (Optimal Safe): "
         << secondLargestOptimal(arr, n) << endl;

    return 0;
}
