#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
=========================================================
Approach 1: Using STL sort()
=========================================================

Logic:
- Directly use C++ inbuilt sort function.
- Internally uses Introsort (Quick + Heap + Insertion sort).

Time Complexity:
- O(n log n)

Space Complexity:
- O(log n) (due to recursion stack)

Best when:
- Simplicity matters more than optimization.
*/

void sortUsingSTL(vector<int>& v) {
    sort(v.begin(), v.end());
}


/*
=========================================================
Approach 2: Using Extra Vectors (Counting Method)
=========================================================

Logic:
- Traverse the array once.
- Store 0s, 1s, 2s in separate vectors.
- Clear original vector.
- Merge them back.

Time Complexity:
- O(n)  (1 traversal + merging)

Space Complexity:
- O(n)  (extra vectors used)

Best when:
- Time optimization needed but space is not a concern.
*/

void sortUsingExtraSpace(vector<int>& v) {
    vector<int> v0, v1, v2;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0)
            v0.push_back(0);
        else if (v[i] == 1)
            v1.push_back(1);
        else
            v2.push_back(2);
    }

    v.clear();

    for (auto x : v0) v.push_back(x);
    for (auto x : v1) v.push_back(x);
    for (auto x : v2) v.push_back(x);
}


/*
=========================================================
Approach 3: Dutch National Flag Algorithm (Optimal)
=========================================================

Logic:
- Use 3 pointers: low, mid, high
- Divide array into 4 parts:

[ 0 zone | 1 zone | unknown | 2 zone ]

Rules:
- If v[mid] == 0 → swap with low, low++, mid++
- If v[mid] == 1 → mid++
- If v[mid] == 2 → swap with high, high--

Time Complexity:
- O(n)  (single pass)

Space Complexity:
- O(1)  (in-place sorting)

Best approach for interviews.
*/

void sortUsingDNF(vector<int>& v) {
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;

    while (mid <= high) {
        if (v[mid] == 0) {
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if (v[mid] == 1) {
            mid++;
        }
        else { // v[mid] == 2
            swap(v[mid], v[high]);
            high--;
        }
    }
}


/*
Utility function to print vector
*/

void printVector(const vector<int>& v) {
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}


/*
==========================
Main Function
==========================
*/

int main() {

    vector<int> arr = {0,0,0,1,1,1,0,0,0,2,2,2,1,0};

    cout << "Original Array:\n";
    printVector(arr);

    // Uncomment any one to test

    // sortUsingSTL(arr);
    // sortUsingExtraSpace(arr);
    sortUsingDNF(arr);

    cout << "\nSorted Array:\n";
    printVector(arr);

    return 0;
}
