#include <iostream>
#include <algorithm>
using namespace std;

/*
===========================================================
1️⃣ BRUTE FORCE APPROACH (Using STL is_sorted)
===========================================================

Logic:
- Use built-in STL function is_sorted().
- It internally checks every adjacent pair.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
This is clean and professional.
But internally same linear traversal hi hota hai.
===========================================================
*/

bool isSortedSTL(int arr[], int n) {
    return is_sorted(arr, arr + n);
}


/*
===========================================================
2️⃣ OPTIMAL MANUAL APPROACH (Your Logic)
===========================================================

Logic:
- Traverse from index 1 to n-1
- Compare arr[i-1] with arr[i]
- If any previous element is greater → not sorted
- Early exit improves performance

Time Complexity: O(n)
Space Complexity: O(1)

Advantage:
- Full control over logic
- Interview-friendly
===========================================================
*/

bool isSortedManual(int arr[], int n) {

    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > arr[i]) {
            return false;   // Early exit
        }
    }

    return true;
}


int main() {

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Using STL Approach: ";
    if(isSortedSTL(arr, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    cout << "Using Manual Approach: ";
    if(isSortedManual(arr, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    return 0;
}
