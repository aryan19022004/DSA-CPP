#include <iostream>
#include <unordered_map>
using namespace std;

/*
===========================================================
1️⃣ BRUTE FORCE APPROACH
-----------------------------------------------------------
Idea:
Check every possible pair using two loops.

Time Complexity  : O(n^2)
Space Complexity : O(1)

Works for:
✔ All cases
✔ Negative numbers
✔ Non-consecutive elements
===========================================================
*/

void twoSumBruteForce(int arr[], int n, int target) {
    cout << "\n--- Brute Force Approach ---\n";

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                cout << "Numbers are " << arr[i] 
                     << " and " << arr[j] << endl;
                return;
            }
        }
    }

    cout << "No pair found\n";
}


/*
===========================================================
2️⃣ OPTIMIZED APPROACH (Using Unordered Map)
-----------------------------------------------------------
Idea:
Store visited elements in hashmap.
For every element, check if (target - element) exists.

Time Complexity  : O(n)
Space Complexity : O(n)

Works for:
✔ All cases
✔ Negative numbers
✔ Non-consecutive elements
===========================================================
*/

void twoSumOptimized(int arr[], int n, int target) {
    cout << "\n--- Optimized Approach (Unordered Map) ---\n";

    unordered_map<int,int> mp;

    for(int i = 0; i < n; i++) {
        int complement = target - arr[i];

        if(mp.find(complement) != mp.end()) {
            cout << "Numbers are " << arr[i] 
                 << " and " << complement << endl;
            return;
        }

        mp[arr[i]] = i;
    }

    cout << "No pair found\n";
}


/*
===========================================================
3️⃣ CONSECUTIVE ELEMENT APPROACH (Your Idea)
-----------------------------------------------------------
Idea:
Keep adding consecutive elements.
Reset sum when it exceeds target.

Time Complexity  : O(n)
Space Complexity : O(1)

IMPORTANT:
❌ Works only for consecutive elements
❌ Fails for general Two Sum
❌ Not suitable if negative numbers exist
===========================================================
*/

void twoSumConsecutive(int arr[], int n, int target) {
    cout << "\n--- Consecutive Elements Approach ---\n";

    int sum = 0;

    for(int i = 0; i < n; i++) {

        if(sum + arr[i] < target) {
            sum += arr[i];
        }
        else if(sum + arr[i] > target) {
            sum = arr[i];
        }
        else {
            cout << "Consecutive numbers are " 
                 << sum << " and " << arr[i] << endl;
            return;
        }
    }

    cout << "No consecutive pair found\n";
}


/*
===========================================================
MAIN FUNCTION
===========================================================
*/

int main() {

    int arr[] = {6,8,3,9,4,5};
    int target = 13;
    int n = sizeof(arr) / sizeof(arr[0]);

    twoSumBruteForce(arr, n, target);
    twoSumOptimized(arr, n, target);
    twoSumConsecutive(arr, n, target);

    return 0;
}
