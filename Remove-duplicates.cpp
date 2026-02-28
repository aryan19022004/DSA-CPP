#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
=========================================================
1️⃣ BRUTE FORCE APPROACH
---------------------------------------------------------
Logic:
- Har element ko vector me daalne se pehle check karte hain
  ki wo already present hai ya nahi.
- Checking ke liye find() use karte hain.
- find() pura vector traverse karta hai.

Time Complexity:
Outer loop = n
find() each time = O(n)
Total = O(n^2)

Space Complexity:
O(n)

Order Preserved: ✅ YES
Sorted: ❌ NO
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
    for(auto it : result) {
        cout << it << " ";
    }
    cout << endl;
}



/*
=========================================================
2️⃣ BETTER APPROACH (Using set)
---------------------------------------------------------
Logic:
- set automatically unique elements store karta hai.
- Duplicates automatically remove ho jaate hain.
- set internally balanced BST hota hai.

Time Complexity:
Insertion in set = O(log n)
Total = n insertions = O(n log n)

Space Complexity:
O(n)

Order Preserved: ❌ NO
Sorted: ✅ YES (auto sorted)
=========================================================
*/

void removeDuplicatesBetter(int arr[], int n) {
    set<int> s;

    for(int i = 0; i < n; i++) {
        s.insert(arr[i]);
    }

    cout << "Better (set): ";
    for(auto it : s) {
        cout << it << " ";
    }
    cout << endl;
}



/*
=========================================================
3️⃣ OPTIMAL APPROACH (Using unordered_set + vector)
---------------------------------------------------------
Logic:
- unordered_set fast lookup deta hai (O(1) average).
- Ek vector maintain karte hain order preserve karne ke liye.
- Agar element pehle nahi dekha → set + vector me daal do.

Time Complexity:
Loop runs n times
unordered_set lookup = O(1) average
Total = O(n)

Space Complexity:
O(n)

Order Preserved: ✅ YES
Sorted: ❌ NO
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
    for(auto it : result) {
        cout << it << " ";
    }
    cout << endl;
}



/*
==================== MAIN FUNCTION =====================
*/

int main() {

    int arr[] = {1,2,3,4,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    removeDuplicatesBruteForce(arr, n);
    removeDuplicatesBetter(arr, n);
    removeDuplicatesOptimal(arr, n);

    return 0;
}
