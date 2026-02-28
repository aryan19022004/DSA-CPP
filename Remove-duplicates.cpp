#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
=========================================================
1️⃣ BRUTE FORCE APPROACH
Time Complexity: O(n^2)
Space Complexity: O(n)
Order Preserved: YES
=========================================================
*/

bool isPresent(vector<int>& v, int target) {
    return find(v.begin(), v.end(), target) != v.end();
}

void removeDuplicatesBruteForce(int arr[], int n) {
    vector<int> result;

    for(int i = 0; i < n; i++) {
        if(!isPresent(result, arr[i])) {
            result.push_back(arr[i]);
        }
    }

    cout << "Brute Force: ";
    for(auto it : result) cout << it << " ";
    cout << endl;
}


/*
=========================================================
2️⃣ BETTER APPROACH (Using set)
Time Complexity: O(n log n)
Space Complexity: O(n)
Sorted Output: YES
=========================================================
*/

void removeDuplicatesBetter(int arr[], int n) {
    set<int> s;

    for(int i = 0; i < n; i++)
        s.insert(arr[i]);

    cout << "Better (set): ";
    for(auto it : s) cout << it << " ";
    cout << endl;
}


/*
=========================================================
3️⃣ OPTIMAL APPROACH (unordered_set + vector)
Time Complexity: O(n)
Space Complexity: O(n)
Order Preserved: YES
=========================================================
*/

void removeDuplicatesOptimal(int arr[], int n) {
    unordered_set<int> seen;
    vector<int> result;

    for(int i = 0; i < n; i++) {
        if(seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            result.push_back(arr[i]);
        }
    }

    cout << "Optimal (unordered_set): ";
    for(auto it : result) cout << it << " ";
    cout << endl;
}


/*
=========================================================
4️⃣ MOST OPTIMAL (Sorted Array - In Place)
---------------------------------------------------------
IMPORTANT: Array must be sorted

Logic:
- Two pointer approach
- j keeps track of unique element index
- If arr[i] != arr[j], move arr[i] ahead

Time Complexity: O(n)
Space Complexity: O(1)  ⭐ (Best possible)

Order Preserved: YES
Extra Space Used: NO
=========================================================
*/

int removeDuplicatesSorted(int arr[], int n) {

    if(n == 0) return 0;

    int j = 0;

    for(int i = 1; i < n; i++) {
        if(arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    return j + 1;   // new size of array
}



/*
========================= MAIN =========================
*/

int main() {

    int arr1[] = {1,2,3,4,5,4,3,2,1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    removeDuplicatesBruteForce(arr1, n1);
    removeDuplicatesBetter(arr1, n1);
    removeDuplicatesOptimal(arr1, n1);

    cout << endl;

    // Sorted Array Example
    int arr2[] = {1,1,1,2,2,2,3,4,5,6,6,7,7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int newSize = removeDuplicatesSorted(arr2, n2);

    cout << "Sorted In-Place (O(1) space): ";
    for(int i = 0; i < newSize; i++)
        cout << arr2[i] << " ";

    cout << endl;
    cout << "Number of unique elements: " << newSize << endl;

    return 0;
}
