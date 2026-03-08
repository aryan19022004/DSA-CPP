#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
-----------------------------------------
1️⃣ BRUTE FORCE APPROACH
-----------------------------------------
Logic:
For every element, check if the next number (num+1) exists
in the array by scanning the whole array.

If found → increase count and continue checking.

Time Complexity:
O(n^2)

Space Complexity:
O(1)
*/

int bruteForce(vector<int> arr) {

    int n = arr.size();
    int longest = 1;

    for(int i = 0; i < n; i++) {

        int count = 1;
        int num = arr[i];

        for(int j = 0; j < n; j++) {
            if(arr[j] == num + 1) {
                count++;
                num = arr[j];
                j = -1; // restart search for next consecutive number
            }
        }

        longest = max(longest, count);
    }

    return longest;
}


/*
-----------------------------------------
2️⃣ BETTER APPROACH (SORTING)
-----------------------------------------
Logic:
1. Sort the array.
2. Traverse the array once.
3. If difference == 1 → increase count.
4. If difference > 1 → reset count.
5. Ignore duplicates.

Time Complexity:
O(n log n)  (because of sorting)

Space Complexity:
O(1)  (if sorting in-place)
*/

int betterSolution(vector<int> arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int count = 1;
    int longest = 1;

    for(int i = 0; i < n - 1; i++) {

        if(arr[i+1] - arr[i] == 1) {
            count++;
        }
        else if(arr[i+1] == arr[i]) {
            continue; // ignore duplicates
        }
        else {
            longest = max(longest, count);
            count = 1;
        }
    }

    longest = max(longest, count);

    return longest;
}


/*
-----------------------------------------
3️⃣ OPTIMAL APPROACH (HASH SET)
-----------------------------------------
Logic:
1. Insert all elements into a HashSet.
2. Start sequence only if (num-1) does NOT exist.
3. Expand sequence using num+1.

Example:
1 → 2 → 3 → 4

Time Complexity:
O(n)

Space Complexity:
O(n)
*/

int optimalSolution(vector<int> arr) {

    unordered_set<int> s(arr.begin(), arr.end());

    int longest = 0;

    for(int num : s) {

        if(s.find(num - 1) == s.end()) {

            int current = num;
            int count = 1;

            while(s.find(current + 1) != s.end()) {
                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}


int main() {

    vector<int> arr = {100,4,200,1,3,2};

    cout << "Brute Force Answer: " << bruteForce(arr) << endl;

    cout << "Better (Sorting) Answer: " << betterSolution(arr) << endl;

    cout << "Optimal (HashSet) Answer: " << optimalSolution(arr) << endl;

}
